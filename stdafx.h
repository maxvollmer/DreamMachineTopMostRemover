#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>


// trim methods taken from https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

static inline std::wstring &ltrim(std::wstring &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

static inline std::wstring &rtrim(std::wstring &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

static inline std::wstring &trim(std::wstring &s) {
	return ltrim(rtrim(s));
}
