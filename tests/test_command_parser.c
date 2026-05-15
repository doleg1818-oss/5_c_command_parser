#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "command_parser.h"
#include "device_state.h"

int main(void)
{
    device_state_t state;
    device_stste_init(&state);

    assert(state.led_on == false);
    assert(state.reset_requested == false);

    command_result_t result;

    result = command_process(&state, CMD_PING, NULL, 0);
    assert(result == CMD_RESULT_OK);

    uint8_t led_on_payload[] = {1};

    result = command_process(&state, CMD_LED_SET, led_on_payload, sizeof(led_on_payload));
    assert(result == CMD_RESULT_OK);
    assert(state.led_on == true);

    uint8_t led_off_payload[] = {0};
    result = command_process(&state, CMD_LED_SET, led_off_payload, sizeof(led_off_payload));
    assert(result == CMD_RESULT_OK);
    assert(state.led_on == false);

    result = command_process(&state, CMD_RESETT, NULL,0);
    assert(result == CMD_RESULT_OK);
    assert(state.reset_requested == true);

    result = command_process(&state, 0x99, NULL, 0);
    assert(result == CMD_RESULT_ERROR_INVALID_COMMAND);
    printf("Command parser tests passed\n");

    return 1;
}