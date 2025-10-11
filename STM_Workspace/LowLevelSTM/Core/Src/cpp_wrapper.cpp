/*
 * Starting.cpp
 *
 *  Created on: Oct 11, 2025
 *      Author: Andrea
 */

#include <cpp_wrapper.h>
#include "ComunicationLib.hpp"

void StartCOM(){
	HAL_UART_Receive_IT(&huart1, Uart1.rx_buffer , Uart1.BufferLen);
	HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_SET);

}
