#include <stdio.h>
#include <stdint.h>

#include "command_parser.h"
#include "device_state.h"
#include "device_action.h"


int main(void)
{
    command_callbacks_t callbacks =
    {
        .led_set = device_led_set,
        .temperature_read_x10 = device_temperature_read_x10,
        .reset_request = device_reset_request
    };

    device_state_t state;
    device_stste_init(&state);

    uint8_t led_payload[] = {1};

    command_result_t result =
        command_process(&state, &callbacks, CMD_LED_SET, led_payload, sizeof(led_payload));

    printf("Command result: %d\n", result);
    printf("LED state: %s\n", state.led_on ? "ON" : "OFF");

    return 0;
}