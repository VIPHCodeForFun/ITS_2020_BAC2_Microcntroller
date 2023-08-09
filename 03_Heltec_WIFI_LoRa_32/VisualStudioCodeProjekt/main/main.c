/*  Sample Project setup see Readme and:
    https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#start-a-new-project

    HAL see:
    https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/
*/

#include <stdio.h>

/* BY ERROR: Add ESP_PATH  in .vscode -> c_cpp_properties.json */
#include "driver/gpio.h"
#include "sdkconfig.h"

#define PIN23 23

static uint8_t led_state = 0;

void app_main(void)
{
    gpio_reset_pin(PIN23);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(PIN23, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(PIN23, led_state);
        led_state = !led_state;
        for (volatile int i = 0; i < 1000000; i++)
        {
        }
    }
}
