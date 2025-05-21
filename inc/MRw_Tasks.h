#ifndef __MRw_Tasks_H__
#define __MRw_Tasks_H__

/** -------------------------------------------------------------------------
 *
 *	@file	MRw_Tasks.h
 *	@brief	Tasks in a minimal RTOS
 *	@author	H.Someya
 *	@date	2025/04/23
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

#include <stdint.h>

#if (MRW_BASE == MRW_BASE_FREERTOS)
#include "MRw_Tasks_FreeRTOS.h"
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
	 *  @brief タスク作成 @n
	 *    タスクを作成する。
	 *  @param taskEntry タスク処理関数。
	 *  @param taskParams タスク処理関数に渡されるパラメータ。
	 *  @param priority 優先度。
	 *  @param stack スタック。※現状未対応。
	 *  @param stackDepth スタックのワード数。
	 *  @param ctxt コンテキスト。
	 *  @return なし。
	 */
	void MRw_CreateTask(
		MRw_TaskEntry_t taskEntry,
		void *const taskParams,
		uint32_t priority,
		MRw_StackAlign_t *stack,
		uint32_t stackDepth,
		MRw_Task *ctxt);

	/**
	 *  @brief 定周期タスク作成 @n
	 *    定周期タスクを作成する。
	 *  @param interval 定周期間隔[msec]。
	 *  @param taskEntry タスク処理関数。
	 *  @param taskParams タスク処理関数に渡されるパラメータ。
	 *  @param priority 優先度。
	 *  @param stack スタック。
	 *  @param stackDepth スタックのワード数。
	 *  @param ctxt コンテキスト。
	 *  @return なし。
	 */
	void MRw_CreatePeriodicTask(
		int32_t interval,
		MRw_TaskEntry_t taskEntry,
		void *const taskParams,
		uint32_t priority,
		MRw_StackAlign_t *stack,
		uint32_t stackDepth,
		MRw_PeriodicTask *ctxt);

	/**
	 *  @brief スケジューラ開始 @n
	 *    スケジューラを開始する。
	 *  @return なし。
	 */
	void MRw_StartScheduler(void);

#ifdef __cplusplus
}
#endif

#endif
