/*
 * Stepper.c
 *
 *  Created on: Sep 10, 2025
 *      Author: Andrea
 */
#include <Stepper.hpp>



Stepper::Stepper(int8_t ID, int32_t Resolution, float Acc) {
    id = ID;
    resolution = Resolution;
    Acceleration = Acc;
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    last_update = HAL_GetTick();
}



void Stepper::SetAcceleration(float acc)
{
	Acceleration = acc;
}
void Stepper::SetVelocity(float rpm)
{
	Target_Speed = rpm;
}



void Stepper::ProfileVelocity(){
	uint32_t now = HAL_GetTick();
	float dt = (now - last_update) / 1000.0f;
	last_update = now;
	float delta = Target_Speed - Current_Speed;

	if (delta < 0){
		Current_Speed -= Acceleration * (-delta / Target_Speed)*dt;
		if (Current_Speed < Target_Speed){ Current_Speed = Target_Speed;}
	}else if(delta > 0){
		Current_Speed += Acceleration * (delta / Target_Speed)*dt;
		if (Current_Speed > Target_Speed){ Current_Speed = Target_Speed;}
	}
	setStepsFreq(Rpm_to_StepS(Current_Speed));
}

void Stepper::ProfilePosition(int32_t Position){

}




void Stepper::QuickStop(){
	Current_Speed = 0;
	Target_Speed = 0;
    __HAL_TIM_DISABLE(&htim1);
    __HAL_TIM_SET_AUTORELOAD(&htim1, 1000);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
    __HAL_TIM_ENABLE(&htim1);
}

void Stepper::setStepsFreq(float StepPerS) {
	if (StepPerS == 0) StepPerS = 1;
	uint32_t arr = 1000000 / StepPerS;

    if (StepPerS <= 0) {
    	__HAL_TIM_DISABLE(&htim1);
		__HAL_TIM_SET_AUTORELOAD(&htim1, arr);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
		__HAL_TIM_ENABLE(&htim1);
        return;
    }

    __HAL_TIM_DISABLE(&htim1);
    __HAL_TIM_SET_AUTORELOAD(&htim1, arr);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, arr/2);
    __HAL_TIM_ENABLE(&htim1);
}

float Stepper::Rpm_to_StepS (float rpm){
	return (resolution*rpm)/60;
}

float Stepper::Angle_to_steps(float angle){
	return (angle*resolution)/360;
}
