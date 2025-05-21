/** -------------------------------------------------------------------------
 *
 *	@file	MRw_Sleeps_FreeRTOS.c
 *	@brief	Sleeps in a minimal RTOS
 *	@author	H.Someya
 *	@date	2024/11/01
 *
 */
/*
MIT License

Copyright (c) 2021 Hirobumi Someya

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "MRw_Configs.h"
#if (MRW_BASE == MRW_BASE_FREERTOS)

#include "MRw_Sleeps.h"

#if defined(ARDUINO)
#include "Arduino_FreeRTOS.h"
#else
#endif

/* --------------------------------------------------------------------------
 *  P R I V A T E S
 */

/* --------------------------------------------------------------------------
 *  P U B L I C   I N T E R F A C E S
 */

/**
 *  @brief スリープ @n
 *    スリープする。
 *  @param sleepMs スリープする時間[msec]。
 *  @return なし。
 */
void MRw_Sleep(
	int32_t sleepMs)
{
	vTaskDelay(pdMS_TO_TICKS(sleepMs));
}

#endif // #if (MRW_BASE == MRW_BASE_FREERTOS)
