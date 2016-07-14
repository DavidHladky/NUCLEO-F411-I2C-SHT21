/* Example of using temperature and humidity sensor SHT21r.
 * David Hladky
 * 2016
 * Version 1.0 Update 14-7-2016
 */


/*-----------Include files-----------*/

#include <stdio.h>
#include <stdlib.h>
#include "HD44780.h"
#include "sht21.h"
#include "i2c_hal.h"



int main(void)
{
  // At this stage the system clock should have already been configured
  // at high speed.

  // Infinite loop
	float temp,humi;
	int8_t temperature_decimal, temperature_fract, humidity_decimal, humidity_fract;;
	char temperature[10],humidity[10];

	HAL_Init(); // Initialization HAL library and system.

	i2c_hal_intialization(); // Initialization I2C peripherals MCU.

	display_HD44780_init(); // HD44780 initialization after initialization I2C peripherals.

	display_HD44780_write_string_position("Temp:",1,2);
	display_HD44780_write_string_position("Humi:",2,2);

	sht21_soft_reset(); // Reset SHT21.


  while (1)
    {
	  temp = sht21_get_temperature(); // Read temperature from SHT21.
	  humi = sht21_get_humidity(); // Read humidity from SHT21.

	  temp *= 100; // Temperature.
	  temperature_decimal = temp/100;
	  temperature_fract = (int)(temp) % 100; // Preparing data for display.

	  humi *= 100; // Humidity.
	  humidity_decimal = humi/100;
	  humidity_fract = (int)(humi) % 100; // Preparing data for display.

	  sprintf(temperature,"%d.%2d C",temperature_decimal,temperature_fract); // Create string from processed data - temperature.
	  sprintf(humidity,"%d.%2d %%",humidity_decimal,humidity_fract);  // Create string from processed data - humidity.

	  display_HD44780_write_string_position(temperature,1,8); // Display processed data on the display - temperature.
	  display_HD44780_write_string_position(humidity,2,8); // Display processed data on the display - humidity.

	  HAL_Delay(2000);


    }
}

