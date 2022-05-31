# TiLib
## About
 This library lets to create timed delays for stm32f1 microcontroller.
 
## Usage
### <ins>Initialization</ins>
Then:
1) Add "tilib_inc_tick();" line inside SysTick_Handler(void) function(It can be found in "stm32f1xx_it.c" file).
```c
//Example:
/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */

  tilib_inc_tick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}
```
2) Call tilib_set_systick(unsigned long ticks_per_ms) function after clock source is configured.
```c
//Example:
 tilib_set_systick(current_core_frequency/FREQ_DIV_SYSTICK);
/* @Note: current_core_frequency - frequency the microcontroller is running at.
*         FREQ_DIV_SYSTICK - number of microcontroller clock cycles after which SysTick_Handler function is called.
* Counter is incremented every 1/(current_core_frequency/FREQ_DIV_SYSTICK) second.
* tilib_set_systick(FREQ/1000) can be used to set 1ms systick
*/
```
### <ins>Available functions</ins>
```c 
// Returns counter value
unsigned long tilib_get_ms(void);
// Gets microcontroller into the loop and microcontroller exits the loop when (1/(current_core_frequency/FREQ_DIV_SYSTICK) * delay) seconds pass.
// If FREQ_DIV_SYSTICK in tilib_set_systick is 1000, loop will take (delay)ms to finish.
void tilib_delay(unsigned long delay);
```

## Notes
