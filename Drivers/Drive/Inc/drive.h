#pragma once

#include "main.h"
#include "control.h"

#define min_value_controller -500
#define max_value_controller 500
#define min_value_servo 200
#define max_value_servo 1350
#define max_value_driver 1
#define min_value_driver -1

extern void set_voltage_left(float duty);

extern void set_voltage_right(float duty);

extern void set_voltge_back(float duty);

extern void control_drivers(uint8_t channel, float speed);



extern void set_pos(uint8_t channel, uint16_t lenght); // Длина от 2% до 13.5%

extern void start_pos(uint8_t channel); // Возвращение в стартовую позицию

extern void control_pos_from_wheel(uint8_t channel, int16_t slider_value);

extern void control_pos_from_stick(uint8_t channel, int16_t stick_value);

