#include "led_control.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO GPIO_NUM_2  // GPIO pin for the LED

void led_on() {
    gpio_set_level(BLINK_GPIO, 1);
}

void led_off() {
    gpio_set_level(BLINK_GPIO, 0);
}

void led_toggle() {
    int current_level = gpio_get_level(BLINK_GPIO);
    gpio_set_level(BLINK_GPIO, !current_level);
}

void led_init() {
    // Configure the GPIO for the LED
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL<<BLINK_GPIO),
        .mode = GPIO_MODE_OUTPUT
    };
    gpio_config(&io_conf);
}
