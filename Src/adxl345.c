#include "adxl345.h"  // Header file for ADXL345 accelerometer functions

char data;            // Variable to temporarily store a single byte of data
uint8_t rec_data[6];  // Array to store 6 bytes of acceleration data (X, Y, Z axes)

// Function to read a single register from ADXL345
void adxl_read_address(uint8_t reg){
	I2C1_readByte(DEVICE_ADDR, reg, &data);  // Read one byte from the given register address
}

// Function to write a single byte value to a register in ADXL345
void adxl_write(uint8_t reg, char value){
	char data[1];
	data[0] = value;
	I2C1_burstWrite(DEVICE_ADDR, reg, 1, data); 
}

// Function to read 6 bytes of data starting from a specific register (used to get acceleration values for X, Y, Z axes)
void adxl_read_values(uint8_t reg){
	I2C1_burstRead(DEVICE_ADDR, reg, 6, (char*)rec_data);  // Read 6 consecutive bytes
}

// Function to initialize the ADXL345 sensor
void adxl_init(void){
	I2C1_init();  // Initialize the I2C communication
	adxl_read_address(DEVID);  // Read device ID to check connection

	adxl_write(DATA_FORMAT, FOUR_G);  // Set data format

	adxl_write(PWR_CTL, RESET);       // Reset power control register
	adxl_write(PWR_CTL, SET_MEASURE_B); // Enable measurement mode
}
