#include "stm32f4xx.h"   // Header file for STM32F4 series microcontrollers
#include <stdio.h>
#include <stdint.h>
#include "adxl345.h"      // Header file for ADXL345 accelerometer functions

int16_t x, y, z;          // Variables to store raw acceleration data
float xg, yg, zg;         // Variables to store acceleration in 'g' units

extern uint8_t rec_data[6];   // Array to store 6 bytes of data received from ADXL345

int main(void){

	adxl_init();    // Initialize the ADXL345 sensor

	while(1){
		adxl_read_values(DATA_START_ADD);  // Read 6 bytes of acceleration data starting from data register

		// Combine two 8-bit values into one 16-bit value for each axis
		x = ((rec_data[1] << 8) | rec_data[0]);  // X-axis data
		y = ((rec_data[3] << 8) | rec_data[2]);  // Y-axis data
		z = ((rec_data[5] << 8) | rec_data[4]);  // Z-axis data

		// Convert raw data to acceleration in 'g' units 
		xg = x * 0.0078;
		yg = y * 0.0078;
		zg = z * 0.0078;

		// The variables xg, yg, and zg now hold acceleration values for each axis
	}
}
