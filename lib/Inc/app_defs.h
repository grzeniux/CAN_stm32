#ifndef __APP_DEFS_H__
#define __APP_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

// For GCC
#ifndef __weak
  #define __weak   __attribute__((weak))
#endif /* __weak */

typedef enum
{
  APP_OK       = 0x00,
  APP_ERROR    = 0x01,
  APP_BUSY     = 0x02,
  APP_TIMEOUT  = 0x03
} APP_StatusTypeDef;

#ifdef __cplusplus
}
#endif
#endif

