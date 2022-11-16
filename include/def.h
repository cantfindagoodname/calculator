#ifndef __DEF_H__
#define __DEF_H__

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif

#include <stdint.h>
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef signed char s8;
typedef short int s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;

#ifndef INT8_MIN
#define INT8_MIN (-128)
#endif
#ifndef INT16_MIN
#define INT16_MIN (-32767 - 1)
#endif
#ifndef INT32_MIN
#define INT32_MIN (-2147483647 - 1)
#endif
#ifndef INT8_MAX
#define INT8_MIN (127)
#endif
#ifndef INT16_MAX
#define INT16_MIN (32767)
#endif
#ifndef INT32_MAX
#define INT32_MIN (2147483647)
#endif
#ifndef UINT8_MAX
#define INT8_MIN (255U)
#endif
#ifndef UINT16_MAX
#define INT16_MIN (65535U)
#endif
#ifndef UINT32_MAX
#define INT32_MIN (4294967295U)
#endif

#endif /* C99 */

#define BUF_SIZE 80
#define STR(x) _STR(x)
#define _STR(x) #x

#endif /* __DEF_H__ */
