#include "control.h"


Svytopolk robot;
Program demo;


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	uint8_t i;
	uint16_t temp;
	temp = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
	if (temp > 2000)
	{
		robot.pointer = 0;
		for (i = 0; i < 6; i++)
		{
			if (robot.captured_value[i] < -500)
				robot.captured_value[i] = -500;
			else if (robot.captured_value[i] > 500)
				robot.captured_value[i] = 500;
			robot.rc_data[i] = robot.captured_value[i] - 1500;
		};
		robot.rc_data[6] = 0;
		if (robot.captured_value[6] > 1500)
			robot.rc_data[6] |= (1<<4);
		if (robot.captured_value[7] > 1500)
			robot.rc_data[6] |= (1<<5);
	}
	else
	{
		robot.captured_value[robot.pointer] = temp - 1500;
		robot.pointer++;
	};
	if (robot.pointer == 8)
		robot.pointer = 0;
}


void robot_init(void)
{
	robot.captured_value[0] = 0;
	robot.captured_value[1] = 0;
	robot.captured_value[2] = 0;
	robot.captured_value[3] = 0;
	robot.captured_value[4] = -500;
	robot.captured_value[5] = -500;
	robot.captured_value[6] = 500;
	robot.captured_value[7] = 500;

	robot.rc_data[0] = 0;
	robot.rc_data[1] = 0;
	robot.rc_data[2] = 0;
	robot.rc_data[3] = 0;
	robot.rc_data[4] = 0;
	robot.rc_data[5] = 0;
	robot.rc_data[6] = 0;

	robot.pointer = 0;
	robot.servo_value = 200;
	robot.previous_servo_value = min_value_servo;
	robot.smoothing_factor = 0.1;

}


void constrction_program(void)
{
	robot.isChanged = false;

	switch(robot.captured_value[7])
	{
		case 500:

			//Включение движков
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);


			//Включение серв
			HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

			robot.demo.runner = &runner_program_1;
			break;
		case 0:
			HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
			robot.demo.runner = &runner_program_2;
			break;
		case -500:
			robot.demo.runner = &runner_program_3;
			break;
		default:
			break;

	}
}

void destrction_program(void)
{
	switch(robot.captured_value[7])
	{
		case 500:

			//Выключение движков
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);

			//Выключение серв
			HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);

			robot.speed = 0;


			break;
		case 0:
			HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);

			break;
		case -500:

			break;

		default:
			break;

	}

	robot.demo.runner = 0;
	robot.isChanged = true;
}


void runner_program_1(void)
{
	control_pos_from_wheel(6, robot.captured_value[4]); // Управление камерой
	control_drivers(1, robot.captured_value[2]);

	if(robot.captured_value[7] != 500)
		robot.isChanged = true;
}


void runner_program_2(void)
{
	control_pos_from_stick(6, robot.captured_value[6]);

	if(robot.captured_value[7] != 0)
		robot.isChanged = true;
}


void runner_program_3(void)
{


	if(robot.captured_value[7] != -500)
		robot.isChanged = true;
}
