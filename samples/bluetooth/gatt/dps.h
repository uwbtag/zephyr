/**
 * Copyright (c) 2019 - Frederic Mes, RTLOC
 * 
 * This file is part of Zephyr-DWM1001.
 *
 *   Zephyr-DWM1001 is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Zephyr-DWM1001 is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Zephyr-DWM1001.  If not, see <https://www.gnu.org/licenses/>.
 * 
 */

/*! ----------------------------------------------------------------------------
 *  @file   dps.h
 *  @brief  DPS GATT Profile header.
 *  @author RTLOC
 */


#ifndef __DPS_H__
#define __DPS_H__

#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>

/** 
 *  @def BT_UUID_DPS
 *  @brief Distance Position Service
 */
#define BT_UUID_DPS                    BT_UUID_DECLARE_128(0xE7, 0x29, 0x13, 0xC2, 0xA1, 0xBA, 0x11, 0x9C, 0x1F, 0x4C, 0x46, 0xC9, 0xD9, 0x21, 0x0C, 0x68)

#define BT_UUID_DPS_OPERATION_MODE     BT_UUID_DECLARE_128(0x64, 0x89, 0x59, 0x99, 0xc0, 0x9f, 0xe7, 0xb5, 0xb0, 0x46, 0x70, 0x77, 0x88, 0xfd, 0x0a, 0x3f)

#define BT_UUID_DPS_NETWORK_ID         BT_UUID_DECLARE_128(0x08, 0x12, 0x99, 0x37, 0x6a, 0x2d, 0x81, 0xA1, 0xBB, 0x45, 0xFF, 0x3B, 0xbc, 0xD8, 0xF9, 0x80)

//a02b947edf974516996a1882521e0ead
#define BT_UUID_DPS_LOC_DATA_MODE      BT_UUID_DECLARE_128(0xad, 0x0e, 0x1e, 0x52, 0x82, 0x18, 0x6a, 0x99, 0x16, 0x45, 0x97, 0xdf, 0x7e, 0x94, 0x2b, 0xa0)
                                                            
//003bbdf2c6344b3dab567ec889b89a37
#define BT_UUID_DPS_LOC_DATA           BT_UUID_DECLARE_128(0x37, 0x9a, 0xb8, 0x89, 0xc8, 0x7e, 0x56, 0xab, 0x3d, 0x4b, 0x34, 0xc6, 0xf2, 0xbd, 0x3b, 0x00)

//f4a67d7d379d41839c034b6ea5103291
#define BT_UUID_DPS_PROXY_POS          BT_UUID_DECLARE_128(0x91, 0x32, 0x10, 0xa5, 0x6e, 0x4b, 0x03, 0x9c, 0x83, 0x41, 0x9d, 0x37, 0x7d, 0x7d, 0xa6, 0xf4)
                                                            
//1e63b1ebd4ed444eaf54c1e965192501
#define BT_UUID_DPS_DEV_INFO           BT_UUID_DECLARE_128(0x01, 0x25, 0x19, 0x65, 0xe9, 0xc1, 0x54, 0xaf, 0x4e, 0x44, 0xed, 0xd4, 0xeb, 0xb1, 0x63, 0x1e)
                                                            
//0eb2bc59baf14c1c85358a0204c69de5
#define BT_UUID_DPS_STAT               BT_UUID_DECLARE_128(0xe5, 0x9d, 0xc6, 0x04, 0x02, 0x8a, 0x35, 0x85, 0x1c, 0x4c, 0xf1, 0xba, 0x59, 0xbc, 0xb2, 0x0e)

//5955aa10e08540308aa6bdfac89ac32b
#define BT_UUID_DPS_FWUP_PUSH          BT_UUID_DECLARE_128(0x2b, 0xc3, 0x9a, 0xc8, 0xfa, 0xbd, 0xa6, 0x8a, 0x30, 0x40, 0x85, 0xe0, 0x10, 0xaa, 0x55, 0x59)
                                                            
//9eed0e2709c04d1cbd927c441daba850
#define BT_UUID_DPS_FWUP_POLL          BT_UUID_DECLARE_128(0x50, 0xa8, 0xab, 0x1d, 0x44, 0x7c, 0x92, 0xbd, 0x1c, 0x4d, 0xc0, 0x09, 0x27, 0x0e, 0xed, 0x9e)

//ed83b848da034a0aa2dc8b401080e473
#define BT_UUID_DPS_DISCONNECT         BT_UUID_DECLARE_128(0x73, 0xe4, 0x80, 0x10, 0x40, 0x8b, 0xdc, 0xa2, 0x0a, 0x4a, 0x03, 0xda, 0x48, 0xb8, 0x83, 0xed)

//0cd7e9d1638a49618b46ae55020161a8
#define BT_UUID_DPS_SENSOR_MODE          BT_UUID_DECLARE_128(0xa8, 0x61, 0x01, 0x02, 0x55, 0xae, 0x46, 0x8b, 0x61, 0x49, 0x8a, 0x63, 0xd1, 0xe9, 0xd7, 0x0c)

//bd097d0e597849ee8c824d0b861eae75
#define BT_UUID_DPS_SENSOR_DATA         BT_UUID_DECLARE_128(0x75, 0xae, 0x1e, 0x86, 0x0b, 0x4d, 0x82, 0x8c, 0xee, 0x49, 0x78, 0x59, 0x0e, 0x7d, 0x09, 0xbd)


/**
 * @brief   
 * @details 
 */
struct ble_dls_evt_rx_data
{
    uint8_t const * p_data; /**< A pointer to the buffer with received data. */
    uint16_t        length; /**< Length of received data. */
} __attribute__((__packed__));
typedef struct ble_dls_evt_rx_data ble_dls_evt_rx_data_t;

/**
 * @brief 
 * @details
 */
struct ble_dps_data_evt
{
    struct bt_conn  *conn;     /**< Connection referencee. */
    ble_dls_evt_rx_data_t    rx_data;   /**< @ref BLE_NUS_EVT_RX_DATA event data. */
}__attribute__((__packed__));
typedef struct ble_dps_data_evt ble_dps_data_evt_t;

/** @brief  */
typedef void (* ble_dps_data_handler_t) (ble_dps_data_evt_t * p_evt);

/**
 * @brief 
 * @details 
 */
struct ble_dps_init {
    ble_dps_data_handler_t data_handler2; /**< Event handler to be called for handling received data. */
}__attribute__((__packed__));
typedef struct ble_dps_init ble_dps_init_t;

 /**
 * @brief 
 * @details 
 */
 struct ble_device_info {
	uint64_t uid;
	uint32_t hw_ver;
	uint32_t fw1_ver;
	uint32_t fw2_ver;
	uint32_t fw1_crc;
	uint32_t fw2_crc;
	uint8_t flag;
} __attribute__((__packed__));
typedef struct ble_device_info ble_device_info_t;

/** @brief  */
s32_t dps_init(ble_dps_init_t *p_init);

/** @brief  */
s32_t dps_notify(struct bt_conn *conn, u8_t tx);

/** @brief  */
s32_t dps_notify_loc_data(struct bt_conn *conn, u8_t *tx, uint16_t len);

/** @brief  */
void dps_set_device_info(ble_device_info_t * devinfo_new);

#endif /* __DPS_H__ */ 
