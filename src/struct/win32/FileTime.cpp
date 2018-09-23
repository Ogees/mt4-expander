/**
 * Win32 struct FILETIME
 *
 * struct FILETIME {
 *    DWORD dwLowDateTime;          //  4
 *    DWORD dwHighDateTime;         //  4
 * };                               //  8 byte
 */
#include "expander.h"


/**
 * Gibt die unteren 32 Bit einer FILETIME zur�ck.
 *
 * @param  FILETIME* ft
 *
 * @return DWORD
 */
DWORD WINAPI ft_LowDateTime(const FILETIME* ft) {
   if ((uint)ft < MIN_VALID_POINTER) return(error(ERR_INVALID_PARAMETER, "invalid parameter ft: 0x%p (not a valid pointer)", ft));
   return(ft->dwLowDateTime);
   #pragma EXPANDER_EXPORT
}


/**
 * Gibt die oberen 32 Bit einer FILETIME zur�ck.
 *
 * @param  FILETIME* ft
 *
 * @return DWORD
 */
DWORD WINAPI ft_HighDateTime(const FILETIME* ft) {
   if ((uint)ft < MIN_VALID_POINTER) return(error(ERR_INVALID_PARAMETER, "invalid parameter ft: 0x%p (not a valid pointer)", ft));
   return(ft->dwHighDateTime);
   #pragma EXPANDER_EXPORT
}
