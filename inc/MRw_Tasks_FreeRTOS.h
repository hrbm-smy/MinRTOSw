#ifndef __MRw_Tasks_FreeRTOS_H__
#define __MRw_Tasks_FreeRTOS_H__

/** -------------------------------------------------------------------------
 *
 *	@file	MRw_Tasks_FreeRTOS.h
 *	@brief	Tasks in a minimal RTOS
 *	@author	H.Someya
 *	@date	2024/10/25
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

#if defined(ARDUINO)
#include "Arduino_FreeRTOS.h"
#else
#endif

/* --------------------------------------------------------------------------
 *  P U B L I C   D E F I N I T I O N S
 */

/* --------------------------------------------------------------------------
 *  P U B L I C   I N T E R F A C E S
 */

#ifdef __cplusplus
extern "C"
{
#endif

	/**
	 * タスクエントリ関数型。
	 */
	typedef TaskFunction_t MRw_TaskEntry_t;
	/**
	 * スタックアライメント型。
	 */
	typedef StackType_t MRw_StackAlign_t;

	/**
	 * タスクコンテキスト。
	 */
	typedef struct
	{
		/**
		 * ハンドル。
		 */
		TaskHandle_t Handle;
		/**
		 * コントロールブロック。
		 */
		StaticTask_t CB;
	} MRw_Task;

	/**
	 * 定周期タスクコンテキスト。
	 */
	typedef struct
	{
		/**
		 * 定周期間隔[msec]。
		 */
		int32_t Interval;
		/**
		 * タスクエントリ。
		 */
		MRw_TaskEntry_t TaskEntry;
		/**
		 * タスクパラメータ。
		 */
		void *TaskParams;

		/**
		 * タスクコンテキスト。
		 */
		MRw_Task Task;

	} MRw_PeriodicTask;

#ifdef __cplusplus
}
#endif

#endif
