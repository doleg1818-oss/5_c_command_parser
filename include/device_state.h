#ifndef DEVICE_STATE_H
#define DEVICE_STATE_H

#include "stdint.h"
#include "stdbool.h"

typedef struct 
{
    bool led_on;
    uint16_t temperature_x10;
    uint16_t battery_mv;
    bool reset_requested;
}device_state_t;

void device_stste_init(device_state_t *state);

#endif