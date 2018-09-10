#include "expander.h"
#include "struct/mt4/MqlStr.h"


/**
 * Gibt die Speicheradresse eines MQL-String-Arrays zur�ck.
 *
 * @param  MqlStr values[] - MQL-String-Array
 *
 * @return uint - Speicheradresse oder NULL, falls ein Fehler auftrat
 */
uint WINAPI GetStringsAddress(const MqlStr values[]) {
   if (values && (uint)values < MIN_VALID_POINTER) return(error(ERR_INVALID_PARAMETER, "invalid parameter values = 0x%p (not a valid pointer)", values));
   return((uint) values);
   #pragma EXPANDER_EXPORT
}


/**
 * Gibt die Speicheradresse eines C-Strings zur�ck.
 *
 * @param  char* value - C-String: MetaTrader �bergibt f�r einen MQL-String das Element MqlStr.string
 *
 * @return uint - Speicheradresse oder NULL, falls ein Fehler auftrat
 *
 * Achtung: GetStringAddress() darf in MQL nur mit Array-Elementen verwendet werden. Ist der Parameter ein einfacher String,
 *          wird an die DLL eine Kopie dieses Strings �bergeben. Diese Kopie wird u.U. sofort nach R�ckkehr freigegeben und
 *          die erhaltene Adresse ist ung�ltig (z.B. im Tester bei mehrfachen Tests).
 */
uint WINAPI GetStringAddress(const char* value) {
   if (value && (uint)value < MIN_VALID_POINTER) return(error(ERR_INVALID_PARAMETER, "invalid parameter value = 0x%p (not a valid pointer)", value));
   return((uint) value);
   #pragma EXPANDER_EXPORT
}


/**
 * Gibt den �bergebenen Zeiger auf einen C-String selbst zur�ck. Wird in MQL zum Lesen eines Strings von
 * einer Adresse verwendet, da MetaTrader einen C-String automatisch in einen MQL-String konvertiert.
 *
 * @param  char* value - C-String
 *
 * @return char* - derselbe Zeiger oder NULL, falls ein Fehler auftrat
 */
const char* WINAPI GetString(const char* value) {
   if (value && (uint)value < MIN_VALID_POINTER) return((char*)error(ERR_INVALID_PARAMETER, "invalid parameter value = 0x%p (not a valid pointer)", value));
   return((char*) value);
   #pragma EXPANDER_EXPORT
}


/**
 * Pr�ft, ob ein C-String initialisiert oder ein NULL-Pointer ist.
 *
 * @param  char* value - zu pr�fender String
 *
 * @return BOOL
 */
BOOL WINAPI StringIsNull(const char* value) {
   return(!value);
   #pragma EXPANDER_EXPORT
}


/**
 * Whether or not two strings are considered equal.
 *
 * @param  char* s1
 * @param  char* s2
 *
 * @return BOOL
 */
BOOL WINAPI StringCompare(const char* s1, const char* s2) {
   if ( s1 ==  s2) return(TRUE);                                     // if pointers are equal values are too
   if (!s1 || !s2) return(FALSE);                                    // if one is a NULL pointer the other can't
   return(strcmp(s1, s2) == 0);                                      // both are not NULL pointers
   #pragma EXPANDER_EXPORT
}


/**
 * Whether or not a string ends with the specified substring.
 *
 * @param  char* str
 * @param  char* suffix
 *
 * @return BOOL
 */
BOOL WINAPI StringEndsWith(const char* str, const char* suffix) {
   if (!str)    return(FALSE);
   if (!suffix) return(warn(ERR_INVALID_PARAMETER, "invalid parameter suffix=%s", suffix));

   size_t strLen    = strlen(str);
   size_t suffixLen = strlen(suffix);
   if (!suffixLen) return(warn(ERR_INVALID_PARAMETER, "illegal parameter suffix=\"\""));

   if (strLen >= suffixLen)
      return(strncmp(str + strLen - suffixLen, suffix, suffixLen) == 0);
   return(FALSE);
   #pragma EXPANDER_EXPORT
}


/**
 * Convert a C string to lower-case.
 *
 * @param  _In_Out_ char* str
 */
void WINAPI StrToLower(char* str) {
   string s(str);
   for (std::basic_string<char>::iterator i=s.begin(); i != s.end(); ++i) {
      *i = tolower(*i);
   }
   strcpy(str, s.c_str());
}


/**
 * Convert a std::string to lower-case.
 *
 * @param  _In_Out_ string& str
 */
void WINAPI StrToLower(std::basic_string<char>& str) {
   for (std::basic_string<char>::iterator i=str.begin(); i != str.end(); ++i) {
      *i = tolower(*i);
   }
}


/**
 * Convert a std::wstring to lower-case.
 *
 * @param  _In_Out_ wstring& str
 */
void WINAPI StrToLower(std::basic_string<wchar_t>& str) {
   for (std::basic_string<wchar_t>::iterator i=str.begin(); i != str.end(); ++i) {
      *i = towlower(*i);
   }
}


/**
 * Convert a C string to upper-case.
 *
 * @param  _In_Out_ char* str
 */
void WINAPI StrToUpper(char* str) {
   string s(str);
   for (std::basic_string<char>::iterator i=s.begin(); i != s.end(); ++i) {
      *i = toupper(*i);
   }
   strcpy(str, s.c_str());
}


/**
 * Convert a std::string to upper-case.
 *
 * @param  _In_Out_ string& str
 */
void WINAPI StrToUpper(std::basic_string<char>& str) {
   for (std::basic_string<char>::iterator i=str.begin(); i != str.end(); ++i) {
      *i = toupper(*i);
   }
}


/**
 * Convert a std::wstring to upper-case.
 *
 * @param  _In_Out_ wstring& str
 */
void WINAPI StrToUpper(std::basic_string<wchar_t>& str) {
   for (std::basic_string<wchar_t>::iterator i=str.begin(); i != str.end(); ++i) {
      *i = towupper(*i);
   }
}
