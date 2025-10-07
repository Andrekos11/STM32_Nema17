/*
 * ComunicationLib.hpp
 *
 *  Created on: Oct 7, 2025
 *      Author: Andrea
 */

#ifndef INC_COMUNICATIONLIB_HPP_
#define INC_COMUNICATIONLIB_HPP_

#include "Stepper.hpp"
#include "usart.h"



class MyUSART{
	public:
	int BufferLen=16;
	uint8_t header;
	uint8_t closing_bit;
	uint8_t rx_buffer[16];

	MyUSART (uint8_t Header, uint8_t ClosingBit);

	void Analyse_msg();
	float FloatExtraction(const uint8_t buffer[16], int pos);

};

extern MyUSART Uart1;


#endif /* INC_COMUNICATIONLIB_HPP_ */
