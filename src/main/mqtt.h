/*
 * File: mqtt.h
 *
 * Description:
 * This header file declares the API for initializing the MQTT client and starting the
 * publishing task in an ESP8266 WiFi thermometer project. It provides the necessary
 * function prototypes for establishing a connection to an MQTT broker and periodically
 * publishing temperature readings.
 *
 * The file is part of an ESP8266 application that securely transmits temperature data
 * over MQTT. It abstracts the setup and management of MQTT communication to simplify
 * main application logic.
 *
 * Functions:
 * - void mqtt_app_start(void): Initializes the MQTT client with the specified broker
 *   credentials and starts the MQTT connection.
 * - void publish_task(void): A FreeRTOS task that handles periodic publishing of
 *   temperature data to a configured MQTT topic.
 *
 * External Dependencies:
 * This file depends on the ESP8266 SDK and the esp-mqtt library for MQTT functionality,
 * as well as FreeRTOS for task scheduling.
 *
 * Usage:
 * Include this header in the main application file to use the MQTT initialization and
 * publishing functionalities. Ensure that the MQTT broker details are correctly configured
 * in the implementation file.
 *
 * Author: Sean Webster
 * Created on: Jan 2024
 *
 * MIT License
 *
 * Copyright (c) 2024 Sean Webster
 *
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

void mqtt_app_start(void);

void publish_task(void);
