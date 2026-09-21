/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Ha Thach for Adafruit Industries
 * Copyright (c) 2026 KORLINX
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef NX40_NRF52840_H
#define NX40_NRF52840_H

/*------------------------------------------------------------------*/
/* LED -- active low. P0.14 for DFU activity, P0.08 for BLE OTA.
 *------------------------------------------------------------------*/
#define LEDS_NUMBER       2
#define LED_PRIMARY_PIN   PINNUM(0, 14)
#define LED_SECONDARY_PIN PINNUM(0, 8)
#define LED_STATE_ON      0

/*------------------------------------------------------------------*/
/* BUTTON -- SW2 only; SW1 is wired to P0.18/RESET.
 *------------------------------------------------------------------*/
#define BUTTON_DFU     PINNUM(0, 7)
#define BUTTON_PULL    NRF_GPIO_PIN_PULLUP

//--------------------------------------------------------------------+
// BLE OTA
//--------------------------------------------------------------------+
#define BLEDIS_MANUFACTURER "KORLINX"
#define BLEDIS_MODEL        "NX40"

//--------------------------------------------------------------------+
// USB
//--------------------------------------------------------------------+

// pid.codes VID, see https://pid.codes/1209/4E58/
#define USB_DESC_VID          0x1209
#define USB_DESC_UF2_PID      0x4E58
#define USB_DESC_CDC_ONLY_PID 0x4E58

#define UF2_PRODUCT_NAME      "KORLINX NX40 nRF52840"
#define UF2_VOLUME_LABEL      "NX40BOOT"

#define UF2_MSC_VENDOR        "KORLINX"
#define UF2_MSC_PRODUCT       "NX40 UF2"
#define UF2_BOARD_ID          "nRF52840-nx40-v1"
#define UF2_INDEX_URL         "https://wiki.korlinx.com/docs/Network/Bluetooth/NX40_Dev_Kit/NX40_Dev_Kit_Overview"

#endif // NX40_NRF52840_H
