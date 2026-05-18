// #include "stdio.h"
// #include <stdint.h>
// #include <stdbool.h>
// #include <stddef.h>

#include "device_action.h"


void device_led_set(bool on)
{
    printf("LED in now %s\n", on ? "ON" : "OFF");
}

uint16_t device_temperature_read_x10(void)
{
    printf("Еуьзукфегку куфв куйгуіеув\n");
    return 253;
}

void device_reset_request(void)
{
    printf("Sistem reset requested\n");
}

