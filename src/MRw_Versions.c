/** -------------------------------------------------------------------------
 *
 *	@file	MRw_Versions.c
 *	@brief	Initialization for minimal RTOS
 *	@author	H.Someya
 *	@date	2025/05/08
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
#include "MRw_Versions.h"

#include "MRw_Configs.h"

/* --------------------------------------------------------------------------
 *  P R I V A T E S
 */

static uint32_t m_versions =
	((0 << 24) & 0xff000000UL) |	  // Major
	((1 << 16) & 0x00ff0000UL) |	  // Minor
	((0 << 8) & 0x0000ff00UL) |		  // -
	((MRW_BASE << 0) & 0x000000ffUL); // Based RTOS

/* --------------------------------------------------------------------------
 *  P U B L I C   I N T E R F A C E S
 */

/**
 *  @brief バージョン取得 @n
 *    バージョンを取得する。
 *  @return バージョン情報。 @n
 *    D31-D24:Majorバージョン。 @n
 *    D23-D16:Minorバージョン。 @n
 *    D15-D08:- @n
 *    D07-D00:ベースRTOS種別。
 */
uint32_t MRw_Version(void)
{
	return m_versions;
}
