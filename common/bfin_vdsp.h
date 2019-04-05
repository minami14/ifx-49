/*
 * bfin_vdsp.h
 *
 * Copyright(C) 2014 Shinya Kaneko
 *
 * Last Update: 2014/09/10
 *
 * [ご注意]
 * このソフトウェアはフリーソフトウェアです。どなたでも自由に改変して使用することができます。
 * このソフトウェアは無保証です。このソフトウェアの使用に起因し、ユーザまたは第三者に
 * 生じた損害に関し、一切の責任を負いません。
 *
 * [NOTE]
 * This program is free software, you can redistribute it and/or modify it.
 * There is no warranty for this free software.
 *
 */
#ifndef _BFIN_VDSP_
#define _BFIN_VDSP_
#ifndef __ECC__
#error This header file is for Visual DSP++.
#endif /* __ECC__ */

#include <sys/exception.h>

#define DECL_INT_HANDLER(handler) EX_INTERRUPT_HANDLER(handler)

#define bfin_register_handler register_handler
#define ex_handler_fn_isr ex_handler_fn

#endif /* _BF_VDSP_ */
