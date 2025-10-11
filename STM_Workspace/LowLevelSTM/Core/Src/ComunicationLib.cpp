/*
 * ComunicationLib.cpp
 *
 *  Created on: Oct 7, 2025
 *      Author: Andrea
 */
#include "ComunicationLib.hpp"



MyUSART::MyUSART (uint8_t Header, uint8_t ClosingBit){
	header = Header;
	closing_bit = ClosingBit;
	for(int i=0; i<BufferLen; i++){
		rx_buffer[i]=0x00;
	}
}

MyUSART Uart1(0xAA, 0xEE);

Stepper Nodo[5];

void MyUSART :: Analyse_msg(){
	switch(rx_buffer[2]){
	case 0: //cmd_vel
		Nodo[rx_buffer[1]]= Stepper(rx_buffer[1], FloatExtraction(rx_buffer, 3), FloatExtraction(rx_buffer, 7));
		break;
	case 1: Nodo[rx_buffer[1]].SetVelocity(FloatExtraction(rx_buffer, 3));
		break;
	case 2: Nodo[rx_buffer[1]].SetAcceleration(FloatExtraction(rx_buffer, 7));
		break;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
	HAL_GPIO_TogglePin(Led_GPIO_Port,Led_Pin);
    //HAL_UART_Transmit(&huart1, tx_buff, 10, HAL_MAX_DELAY);
	Uart1.Analyse_msg();
    HAL_UART_Receive_IT(&huart1, Uart1.rx_buffer , Uart1.BufferLen);
  }
}

float MyUSART::FloatExtraction(const uint8_t buffer[16], int pos){
	float valore;
	std::memcpy(&valore, buffer + pos, sizeof(float));
	return valore;
}


