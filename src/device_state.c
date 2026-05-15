#include "device_state.h"

void device_stste_init(device_state_t *state)
{
    if(state == NULL)
    {
        return;
    }
    state->led_on = false;
    state->temperature_x10 = 253;
    state->temperature_x10 = 3800;
    state->reset_requested = false;
}

