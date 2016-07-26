/* Driver for SHT21.
 * David Hladky
 * 2016
 * Version 1.0 Update 14-7-2016
 */

#include "sht21.h"

void sht21_soft_reset(void)
{
	uint8_t commnad = SHT21_SOFT_RESET;
	HAL_I2C_Master_Transmit(&I2C1_struct,I2C_dev_add,&commnad,1,1000); // Send command to the SHT21.
	HAL_Delay(15);
}

uint8_t sht21_read_user_reg(void)
{
	uint8_t user_reg, commnad = SHT21_READ_USER_REGISTER;
	HAL_I2C_Master_Transmit(&I2C1_struct,I2C_dev_add,&commnad,1,1000); // Send command to the SHT21.
	HAL_Delay(55);
	HAL_I2C_Master_Receive(&I2C1_struct,I2C_dev_add,user_reg,1,3000);
	return user_reg;
}

void sht21_write_user_reg(uint8_t data)
{
	uint8_t data_to_sht21[2];
	data_to_sht21[0] = SHT21_WRITE_USER_REGISTER;
	data_to_sht21[1] = data;
	HAL_I2C_Master_Transmit(&I2C1_struct,I2C_dev_add,data_to_sht21,2,1000);
}

float sht21_get_temperature(void)
{
	uint8_t data_from_sht21[3], commnad = SHT21_T_MEASURE_NO_MASTER;
	float temperature, temp_data;

	HAL_I2C_Master_Transmit(&I2C1_struct,I2C_dev_add,&commnad,1,1000); // Send command to the SHT21.
	HAL_Delay(50);
	HAL_I2C_Master_Receive(&I2C1_struct,I2C_dev_add,data_from_sht21,3,3000); // Read data from SHT21.

	temp_data = ((data_from_sht21[0]<<8)|data_from_sht21[1]) & 0xFFFC;
	temperature = -46.85 + 175.12*((float)((temp_data/65535)));

	return temperature;
}

float sht21_get_humidity(void)
{
	uint8_t data_from_sht21[3], commnad = SHT21_H_MEASURE_NO_MASTER;
	float humidity,temp_data;

	HAL_I2C_Master_Transmit(&I2C1_struct,I2C_dev_add,&commnad,1,1000); // Send command to the SHT21.
	HAL_Delay(20);
	HAL_I2C_Master_Receive(&I2C1_struct,I2C_dev_add,data_from_sht21,3,1000); // Read data from SHT21.

	temp_data = ((data_from_sht21[0]<<8)|data_from_sht21[1]) & 0xFFFC;
	humidity = -6 + 125*((temp_data/65535));

	return humidity;
}





