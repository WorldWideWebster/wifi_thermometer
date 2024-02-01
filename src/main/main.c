/*
 * File: main.c
 *
 * Description:
 * This is the main entry point for an ESP8266-based WiFi thermometer application. The application
 * demonstrates the integration of WiFi and MQTT protocols to publish temperature readings. It initializes
 * the necessary system components, connects the device to a WiFi network, establishes a connection with
 * an MQTT broker, and periodically publishes temperature readings to a specified MQTT topic.
 *
 * Key Components:
 * - NVS (Non-Volatile Storage): Initializes storage for persistent configuration across reboots.
 * - WiFi: Connects the device to a WiFi network in station mode using credentials specified in "wifi.h".
 * - MQTT: Handles communication with an MQTT broker, as configured in "mqtt.h", for publishing temperature readings.
 * - FreeRTOS Tasks: Utilizes tasks for managing WiFi connectivity, MQTT messaging, and temperature measurement.
 *
 * External Dependencies:
 * - FreeRTOS: For creating and managing tasks.
 * - ESP8266 SDK: Utilizes ESP8266 Non-OS SDK for system, network, and WiFi functionalities.
 * - LWIP: Lightweight IP stack for handling network communication.
 * - Custom Header Files: "mqtt.h", "secrets.h", and "wifi.h" contain configurations for MQTT, WiFi credentials, and other secrets.
 *
 * Usage:
 * To use this application, compile and flash it to an ESP8266 device. Ensure the device is equipped with a temperature
 * sensor and configured to connect to your WiFi network and MQTT broker. The application will measure the temperature
 * and publish the readings to the MQTT broker at predefined intervals.
 *
 * Logging:
 * Configures logging levels for system and application components to facilitate debugging and monitoring. It logs system
 * startup information, free memory, ESP8266 SDK version, and the status of WiFi and MQTT connections.
 *
 * Author: Sean Webster
 * Created on: Jan 2024
 *
 * Note: This file is part of an ESP8266 WiFi thermometer project. It requires external setup for WiFi and MQTT broker
 * connectivity details.
 *
 * Copyright (c) 2024 Sean Webster
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "nvs.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "mqtt.h"
#include "secrets.h"
#include "wifi.h"

static const char *WIFI_TAG = "wifi station";
static const char *MQTT_TAG = "MQTTS";

void app_main()
{
    ESP_LOGI(MQTT_TAG, "[APP] Startup..");
    ESP_LOGI(MQTT_TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    ESP_LOGI(MQTT_TAG, "[APP] IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_INFO);
    esp_log_level_set("esp-tls", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_EXAMPLE", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_TCP", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_SSL", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT", ESP_LOG_VERBOSE);
    esp_log_level_set("OUTBOX", ESP_LOG_VERBOSE);

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());

    ESP_LOGI(WIFI_TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
    mqtt_app_start();
    xTaskCreate(&publish_task, "publish_task", 4096, NULL, 5, NULL);
}
