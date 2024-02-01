/*
 * File: wifi.h
 *
 * Description:
 * This header file declares the interface for the Wifi API specific to the ESP8266 microcontroller.
 * It provides the necessary function declarations for initializing and managing a WiFi station
 * interface. This file should be included in projects where WiFi functionality is required,
 * in conjunction with the corresponding implementation file (wifi.c).
 *
 * The primary function declared in this file is:
 * - void wifi_init_sta(void): Initializes the WiFi station mode and manages the connection
 *   process, including handling reconnection attempts and event logging.
 *
 * Usage:
 * Include this header in your project source files to utilize the WiFi functionalities provided
 * for the ESP8266. Ensure that the corresponding implementation file (wifi.c) is compiled and linked
 * in your project.
 *
 * Note: This file assumes the availability of FreeRTOS and ESP-IDF libraries for the ESP8266.
 *
 * Author: Sean Webster
 * Created on: January 2024
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

void wifi_init_sta(void);