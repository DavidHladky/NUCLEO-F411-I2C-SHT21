# NUCLEO-F411-I2C-SHT21
This library deals with the operation of the library for the sensor SHT21. The library provides basic functions for communications between MCU and SHT21. The main routine are placed in the file SHT21.c. In the file SHT21.h are located definitions of functions and commands. The main function (main.c) is the example of using this library. The Main function uses libraries form the porject NUCLEO-F411-I2C-HD44780. In the main function is exmaple of using SHT21. Basic loop performs measurements of temperature and humidity. Temperature and humidity obtained from the sensor are displayed on the display HD44780.

## Description of functions in the file SHT21.c
* The first function is `sht21_soft_reset()`. This function performs a software reset SHT21 and set to default.
* 
