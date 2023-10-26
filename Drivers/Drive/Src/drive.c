#include "drive.h"


void set_voltage_left(float duty)
{

	if(duty >= 0)
	{
		HAL_GPIO_WritePin(GPIOB, BTN1_DIR_Pin, GPIO_PIN_RESET);
		TIM3->CCR1 = ((int32_t) (duty * TIM3->ARR));
		return;
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, BTN1_DIR_Pin, GPIO_PIN_SET);
		TIM3->CCR1 = ((int32_t)(TIM3->ARR + (duty * TIM3->ARR)));
	}
}


void set_voltage_right(float duty)
{
	if(duty >= 0)
	{
		HAL_GPIO_WritePin(GPIOB, BTN2_DIR_Pin, GPIO_PIN_RESET);
		TIM3->CCR2 = ((int32_t) (duty * TIM3->ARR));
		return;
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, BTN2_DIR_Pin, GPIO_PIN_SET);
		TIM3->CCR2 = ((int32_t)(TIM3->ARR + (duty * TIM3->ARR)));
	}
}


void set_voltage_back(float duty)
{
	if(duty >= 0)
	{
		HAL_GPIO_WritePin(GPIOB, BTN3_DIR_Pin, GPIO_PIN_RESET);
		TIM3->CCR3 = ((int32_t) (duty * TIM3->ARR));
		return;
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, BTN2_DIR_Pin, GPIO_PIN_SET);
		TIM3->CCR3 = ((int32_t)(TIM3->ARR + (duty * TIM3->ARR)));
	}
}


void control_drivers(uint8_t channel, float speed)
{
	robot.speed = min_value_driver + (speed - min_value_controller) * (max_value_driver - min_value_driver) / (max_value_controller - min_value_controller);

	switch(channel)
	{
		case 1:
			set_voltage_left(robot.speed);
			break;
		case 2:
			set_voltage_right(robot.speed);
			break;
		case 3:
			set_voltage_back(robot.speed);
			break;

		default:
			break;

	}
}




void start_pos(uint8_t channel)
{
	for(uint16_t i = 1350; i > 200; i--)
	{
	  set_pos(channel, i);
	  HAL_Delay(10);
	}
}


void set_pos(uint8_t channel, uint16_t lenght)
{
	switch(channel)
	{
		case 1:
			TIM1->CCR4 = lenght;
			break;
		case 2:
			TIM1->CCR3 = lenght;
			break;
		case 3:
			TIM1->CCR2 = lenght;
			break;
		case 4:
			TIM1->CCR1 = lenght;
			break;
		case 5:
			TIM4->CCR1 = lenght;
			break;
		case 6:
			TIM4->CCR2 = lenght;
			break;
		default:
			break;

	}

}


void control_pos_from_wheel(uint8_t channel, int16_t slider_value)
{
	uint16_t servo_value = min_value_servo + (slider_value - min_value_controller) * (max_value_servo - min_value_servo) / (max_value_controller - min_value_controller);

	HAL_Delay(20);

	set_pos(channel, servo_value);
}


void control_pos_from_stick(uint8_t channel, int16_t stick_value)
{

	if (stick_value > 20 || stick_value < -20) {
		float target_value = ((float)stick_value - min_value_controller) * (max_value_servo - min_value_servo) / (max_value_controller - min_value_controller);

		robot.servo_value = robot.previous_servo_value + robot.smoothing_factor * (target_value - robot.previous_servo_value);

		if (robot.servo_value > 1300)
			robot.servo_value = 1300;
		else if (robot.servo_value < 200)
			robot.servo_value = 200;

		robot.previous_servo_value = robot.servo_value;
	}

	HAL_Delay(100);

	set_pos(channel, robot.servo_value);

}


