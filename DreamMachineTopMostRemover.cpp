
#include "stdafx.h"

BOOL CALLBACK FindDreamMachineWindow(_In_ HWND hwnd, _In_ LPARAM lParam);

const char DREAMMACHINE_WINDOW_CLASSNAME[] = "The Dream Machine";

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	while (true)
	{
		EnumChildWindows(NULL, FindDreamMachineWindow, NULL);
		Sleep(50);
	}
}

BOOL CALLBACK FindDreamMachineWindow(_In_ HWND hwnd, _In_ LPARAM lParam)
{
	DWORD_PTR dwResult = 0;
	char windowTitle[256];
	windowTitle[0] = 0;
	SendMessageTimeoutA(hwnd, WM_GETTEXT, 256, (LPARAM)windowTitle, SMTO_ABORTIFHUNG, 100, &dwResult);

	char windowClassname[256];
	windowClassname[0] = 0;
	GetClassNameA(hwnd, windowClassname, 256);

	bool foundWindow = std::string(windowTitle).find(DREAMMACHINE_WINDOW_CLASSNAME) == 0;

	if (foundWindow)
	{
		long dwExStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
		dwExStyle &= ~WS_EX_TOPMOST;
		SetWindowLong(hwnd, GWL_EXSTYLE, dwExStyle);
		SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);
	}

	return foundWindow ? FALSE : TRUE;
}

