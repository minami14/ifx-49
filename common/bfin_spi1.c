/*
 * bfin_spi1.c
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

void bfin_spi1_init(void)
{
    /*****************************************************************************
     * ポート初期化
     ****************************************************************************/
    /* CSピンはGPIO制御なので、各モジュールにて初期化の事 */

    *pSPI1_CTL     = 0;
    /* SPI SCK, MOSI, MISO */
    *pPORTG_FER   |= PG8 | PG9 | PG10;
    *pPORTG_MUX   &= ~(PG8 | PG9 | PG10);
    /* SPI初期化 */
    *pSPI1_BAUD    = 5;     /* 9.8MHz */
    *pSPI1_FLG     = 0;
    *pSPI1_CTL     = SPE | MSTR | EMISO | TDBR_CORE;
    ssync();
}

/* SPI 1バイト転送 */
uint8_t bfin_spi1_xfer(uint8_t send_data)
{
    /* 送信データを設定し、転送開始 */
    *pSPI1_TDBR = send_data;
    ssync();
    /* 転送完了まで待機 */
    while((*pSPI1_STAT & RXS) == 0) ssync();

    /* 受信データを取得 */
    return (uint8_t)*pSPI1_RDBR;
}
