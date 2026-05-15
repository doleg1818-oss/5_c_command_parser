#include "command_parser.h"


command_result_t command_process(
    device_state_t *state,
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
            if(payload == NULL)
            {
                return CMD_RESULT_ERROR_NULL_POINTER;
            }
            if(payload_len != 1)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }
            state->led_on = (payload[0] != 0);
            return CMD_RESULT_OK;

        case CMD_GET_STATUS:
            if(payload_len != 0)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }
            return CMD_RESULT_OK;

        case CMD_RESETT:
            if(payload_len != 0)
            {
                return CMD_RESULT_ERROR_INVALID_LENGTH;
            }
            state->reset_requested = true;
            return CMD_RESULT_OK;

        default:
            return CMD_RESULT_ERROR_INVALID_COMMAND;
    }
}