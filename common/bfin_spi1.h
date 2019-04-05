/*
 * bfin_spi1.h
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
#ifndef _BFIN_SPI1_
#define _BFIN_SPI1_

extern void bfin_spi1_init(void);
extern uint8_t bfin_spi1_xfer(uint8_t send_data);

#endif /* _BFIN_SPI1_ */
