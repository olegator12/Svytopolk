#pragma once

#include "main.h"
#include "tim.h"
#include "drive.h"
#include "stdbool.h"

typedef struct{
	void (*constructor)(void);
	void (*destructor)(void);
	void (*runner)(void);
}Program;


typedef struct{
	bool isChanged;
	int16_t captured_value[8];
	int16_t rc_data[7];
	uint8_t pointer;
	uint16_t servo_value[6];
	uint16_t previous_servo_value[6];
	float smoothing_factor;
	float speed;
	Program demo;
}Svytopolk;

enum GamePad{
	left_stick_h,
	right_stick_v,
	left_stick_v,
	right_stick_h,
	left_wheel,
	right_wheel,
	far_left_toggle_switch,
	near_left_toggle_switch
};

extern Program demo;
extern Svytopolk robot;


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

extern void robot_init(void);

extern void constrction_program(void);

extern void destrction_program(void);

void runner_program_1(void);

void runner_program_2(void);

void runner_program_3(void);
