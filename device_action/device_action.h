#ifndef DEVICE_ACTION_H
#define DEVICE_ACTION_H

#include "stdio.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


void device_led_set(bool on);
uint16_t device_temperature_read_x10(void);
void device_reset_request(void);




#endif 