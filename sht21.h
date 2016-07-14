/* Driver for SHT21.
 * David Hladky
 * 2016
 * Version 1.0 Update 14-7-2016
 */

#include "stm32f4xx_hal.h"
#include "i2c_hal.h"


/*----------------------- Definitions cmd -----------------------*/

#define SHT21_READ_USER_REGISTER 	0xE7
#define SHT21_WRITE_USER_REGISTER 	0xE6
#define SHT21_SOFT_RESET 			0xFE
#define SHT21_T_MEASURE_MASTER 		0xE3
#define SHT21_H_MEASURE_MASTER 		0xE5
#define SHT21_T_MEASURE_NO_MASTER 	0xF3
#define SHT21_H_MEASURE_NO_MASTER 	0xF5


/*--------------- Definitions addresses of SHT21 ----------------*/
#define I2C_dev_add	0x80

/*-------------------------- Functions --------------------------*/
void sht21_soft_reset(void); // Reset SHT21

uint8_t sht21_read_user_reg(void); // Read user register of SHT21.

void sht21_write_user_reg(uint8_t data); // Write data to the user register of SHT21.

float sht21_get_temperature(void); // Start measure temperature.

float sht21_get_humidity(void); // Start measure humidity

