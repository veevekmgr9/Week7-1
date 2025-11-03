#include "stm32f4xx.h"
#include <stdio.h>
#include <stdint.h>
#include "adxl345.h"


int16_t x,y,z;
float xg, yg, zg;

extern uint8_t rec_data[6];

int main(void){

	adxl_init();

	while(1){
		adxl_read_values(DATA_START_ADD);

		x = ((rec_data[1] << 8) | rec_data[0]);
		y = ((rec_data[3] << 8) | rec_data[2]);
		z = ((rec_data[5] << 8) | rec_data[4]);

		xg = x*0.0078;
		yg = y*0.0078;
		zg = z*0.0078;

	}
}
