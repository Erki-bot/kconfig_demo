//
// Created by erki on 1/7/26.
//

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "say_hello.h"

static const char *TAG="kconfig_demo";

static const uint32_t sleep_time_ms = 1000;

void delay(uint32_t timeout);

void app_main(void)
{
    while (1)
    {
        printf("Log messages...\n");
        ESP_LOGE(TAG, "Error");
        ESP_LOGW(TAG, "Warn");
        ESP_LOGI(TAG, "Info");
        ESP_LOGD(TAG, "Debug");
        ESP_LOGV(TAG, "Verbose");

#ifdef CONFIG_SAY_HELLO
        say_hello();
#endif

        delay(sleep_time_ms);
    }
}

void delay(const uint32_t timeout)
{
    vTaskDelay(timeout/portTICK_PERIOD_MS);
}
