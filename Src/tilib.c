/*
 * TLib.c
 */

#include <tilib.h>

static volatile unsigned long msTick = 0UL;

/**
 * @brief	This function is called from SysTick_Handler IRQ.
 * 			It increments 1ms counter
 */
void tilib_inc_tick(void)
{
	msTick++;
}

/**
 * @brief	Returns time in ms
 * @retval	msTick Time in ms
 */
unsigned long tilib_get_ms(void)
{
	return msTick;
}


/**
 * @brief  Sets interval between two SysTick IRQ.
 * @param  ticks_per_ms Core clock cycles it takes for 1ms to pass.
 * @retval None
*/
void tilib_set_systick(unsigned long ticks_per_ms)
{
	if(((ticks_per_ms) <= SYSTICK_MAX_LOAD_RELOAD))
	{
		SysTick -> LOAD = ticks_per_ms;
		SysTick -> CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
		SysTick -> VAL = 0U;
	}
}

/**
 * @brief	Forces microcontroller to idle for set time
 * @param	delay	Time in ms to wait for
 */
void tilib_delay(unsigned long delay)
{
	volatile unsigned long start_ms = tilib_get_ms();
	while(tilib_get_ms() - start_ms <= delay) {}
}
