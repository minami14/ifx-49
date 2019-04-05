/*
 * bfin_timer2.c
 *
 * Copyright(C) 2014 Shinya Kaneko
 *
 * Last Update: 2014/06/28
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

#include <ifx-49.h>

void bfin_timer2_start(uint32_t period, ex_handler_fn_isr handler)
{
    /* 割り込みハンドラをIVG13に登録 */
    *pSIC_IAR2 = (*pSIC_IAR2 & 0xFF0FFFFFu) | 0x00600000U;
    bfin_register_handler(ik_ivg13, handler);
    *pSIC_IMASK |= IRQ_TIMER2;

    /* GPタイマ2の設定 */
    *pTIMER2_CONFIG = OUT_DIS | IRQ_ENA | PERIOD_CNT | PWM_OUT;
    *pTIMER2_PERIOD = (BF592_SCLOCK_HZ / 1000 / 10) * period;
    *pTIMER2_WIDTH = 1;
    *pTIMER_ENABLE = TIMEN2;
    ssync();
}

