#include <stdio.h>
#include <stdint.h>

#include "command_parser.h"
#include "device_state.h"

int main(void)
{
    device_state_t state;
    device_stste_init(&state);

    uint8_t led_payload[] = {1};

    command_result_t result =
        command_process(&state, CMD_LED_SET, led_payload, sizeof(led_payload));

    printf("Command result: %d\n", result);
    printf("LED state: %s\n", state.led_on ? "ON" : "OFF");

    return 0;
}