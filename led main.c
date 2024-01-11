#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_control.h"

void blink_task(void *pvParameter) {
    while (1) {
        // Blink the LED
        led_toggle();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void led_main() {
    // Initialize the LED
    led_init();

    // Create a task to blink the LED
    xTaskCreate(&blink_task, "blink_task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
}
