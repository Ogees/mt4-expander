#pragma once
#include "expander.h"
#include "struct/mt4/MqlString.h"
#include <sstream>


/**
 * C++11 to_string() replacement for VS 2008.
 *
 * @param  <typename T> value
 *
 * @return string
 *
 * Note: The returned string is a temporary object that will be destructed at the end of the expression.
 */
template <typename T> string to_string(T value) {
   std::ostringstream os;
   os << value;
   return(os.str());
}


char*        WINAPI DoubleQuoteStr(const char* value);
const char*  WINAPI GetStringA(const char* value);
const wchar* WINAPI GetStringW(const wchar* value);

BOOL         WINAPI SortMqlStringsA(MqlStringA strings[], int size);
BOOL         WINAPI SortMqlStringsW(MqlStringW strings[], int size);

BOOL         WINAPI StrCompare(const char* s1, const char* s2);
char*        WINAPI StrFormat(const char* format, ...);
BOOL         WINAPI StrIsNull(const char* value);
BOOL         WINAPI StrStartsWith(const char* str, const char* prefix);
BOOL         WINAPI StrStartsWith(const wchar* str, const wchar* prefix);
BOOL         WINAPI StrEndsWith(const char* str, const char* suffix);
string&      WINAPI StrReplace(string &subject, const string &search, const string &replace, size_t count=INT_MAX);
char*        WINAPI StrToLower(char* const str);
string&      WINAPI StrToLower(string &str);
wstring&     WINAPI StrToLower(wstring &str);
char*        WINAPI StrToUpper(char* const str);
string&      WINAPI StrToUpper(string &str);
wstring&     WINAPI StrToUpper(wstring &str);

char*        WINAPI StrTrim(char* const str);
char*        WINAPI StrTrimLeft(char* const str);
char*        WINAPI StrTrimRight(char* const str);

uint         WINAPI AnsiToWCharStr(const char* source, wchar* dest, uint destSize);
uint         WINAPI WCharToAnsiStr(const wchar* source, char* dest, uint destSize);

std::istream& getline(std::istream &is, string &line);

wstring       ansiToUnicode(const string &str);
string        ansiToUtf8   (const string &str);
string        unicodeToAnsi(const wstring &wstr);
string        unicodeToUtf8(const wstring &wstr);
string        utf8ToAnsi   (const string &str);
wstring       utf8ToUnicode(const string &str);


namespace rsf {
   inline wchar* copywchars(const wchar* str) { return(wcscpy(new wchar[wcslen(str)+1], str)); };
   char*         strformat(const char* format, ...);
   char*         strformat(const char* format, const va_list &args);
}
