#include "command_parser.h"
//#include "device_action/device_action.h"

command_result_t command_process(
    device_state_t *state,
    const command_callbacks_t *callbacks,
    uint8_t command_id,
    const uint8_t *payload,
    size_t payload_len
)
{
    if(state == NULL)
    {
        return CMD_RESULT_ERROR_NULL_POINTER;
    }

    switch(command_id)
    {
        case CMD_PING:
            if(payload_len != 0)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }
            return CMD_RESULT_OK;
        
        case CMD_LED_SET:
            if(payload == NULL || callbacks->led_set == NULL)
            {
                return CMD_RESULT_ERROR_NULL_POINTER;
            }
            if(payload_len != 1)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }
            state->led_on = (payload[0] != 0);
            callbacks->led_set(state->led_on);      // Callback 
            return CMD_RESULT_OK;

        case CMD_GET_STATUS:
            if(callbacks->temperature_read_x10 == NULL)
            {
                return CMD_RESULT_ERROR_NULL_POINTER;
            }

            if(payload_len != 0)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }

            state->temperature_x10 = callbacks->temperature_read_x10();
            return CMD_RESULT_OK;

        case CMD_RESETT:
            if(callbacks->reset_request == NULL)
            {
                return CMD_RESULT_ERROR_NULL_POINTER;
            }
            if(payload_len != 0)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }
            state->reset_requested = true;
            callbacks->reset_request();
            return CMD_RESULT_OK;

        default:
            return CMD_RESULT_ERROR_INVALID_COMMAND;
    }
}