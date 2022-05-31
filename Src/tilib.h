/*
 * TLib.h
 *
 * Requires tilib_inc_tick(void); to be put in SysTick_Handler function
 * and systick has to be 1ms, tilib_set_systick(SYSTEM_CORE_FREQUENCY/1000) can be used to set 1ms systick
 */

#ifndef __TILIB_H_
#define __TILIB_H_

#ifdef __cplusplus
extern "C" {
#endif

//including core_cm3 directly gives errors
#include "stm32f1xx.h"

#define SYSTICK_MAX_LOAD_RELOAD 0xFFFFFF

void tilib_inc_tick(void);
unsigned long tilib_get_ms(void);

void tilib_set_systick(unsigned long);
void tilib_delay(unsigned long );

#ifdef __cplusplus
}
#endif
#endif /* _TILIB_H_ */
