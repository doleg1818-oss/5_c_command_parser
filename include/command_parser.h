#ifndef COMMAND_PARSER_H
#define  COMMAND_PARSER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// #include "device_action/device_action.h"
#include "device_state.h"

typedef enum
{
    CMD_PING = 0x01,
    CMD_LED_SET = 0x02,
    CMD_GET_STATUS = 0x03,
    CMD_RESETT = 0x04
} command_id_t;

typedef enum
{
    CMD_RESULT_OK = 0,
    CMD_RESULT_ERROR_INVALID_COMMAND,
    CMD_RESULT_ERROR_INVALID_LENGTH,
    CMD_RESULT_ERROR_NULL_POINTER
} command_result_t;

typedef struct 
{   
    void (*led_set)(bool on);
    uint16_t (*temperature_read_x10)(void);
    void (*reset_request)(void);
}command_callbacks_t;

command_result_t command_process(
    device_state_t *state,
    const command_callbacks_t *callbacks,
    uint8_t command_id,
    const uint8_t *payload,
    size_t payload_len
);



#endif