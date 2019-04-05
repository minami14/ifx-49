TARGET = bypass
SRC = main.c
LIB = ../common/bfin_gcc.c ../common/bfin_pll.c ../common/bfin_spi0.c ../common/bfin_uart0.c ../common/bfin_gpio.c ../common/bfin_timer0.c ../common/adau1361.c ../common/ifx-49.c

all:
	bfin-elf-gcc -O2 -mcpu=bf592-any -mfast-fp -Wl,-Map=$(TARGET).map,--cref -I../common -T../common/bf592.ld -o $(TARGET).dxe $(SRC) $(LIB)
	bfin-elf-ldr -T BF592 -c $(TARGET).ldr $(TARGET).dxe --bmode spi

clean:
	del *.map
	del *.dxe
	del *.ldr
