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
 *  @file   dps.c
 *  @brief  DPS GATT Profile implementation.
 *  @author RTLOC
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <misc/printk.h>
#include <misc/byteorder.h>
#include <zephyr.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/conn.h>
#include <bluetooth/gatt.h>
#include <bluetooth/uuid.h>

#include "dps.h"

static ssize_t read_device_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			 void *buf, uint16_t len, uint16_t offset);

static struct bt_gatt_ccc_cfg dps_ccc_cfg[BT_GATT_CCC_MAX] = {};
static uint8_t dps_tx_started;
static ble_device_info_t devinfo;

static ble_dps_init_t ble_dps = {
  .data_handler2 = NULL
};

static void dps_ccc_cfg_changed(const struct bt_gatt_attr *attr,
				 u16_t value)
{
	dps_tx_started = (value == BT_GATT_CCC_NOTIFY) ? 1 : 0;
}


static struct bt_gatt_attr attrs[] = 
{
	BT_GATT_PRIMARY_SERVICE(BT_UUID_DPS),

	/* Location Data */    
	BT_GATT_CHARACTERISTIC(BT_UUID_DPS_LOC_DATA, BT_GATT_CHRC_NOTIFY,
	   BT_GATT_PERM_NONE, NULL, NULL, NULL),
	BT_GATT_CCC(dps_ccc_cfg, dps_ccc_cfg_changed),

	/* Device Info */    
	BT_GATT_CHARACTERISTIC(BT_UUID_DPS_DEV_INFO, BT_GATT_CHRC_READ,
	   BT_GATT_PERM_READ, read_device_info, NULL, NULL),	
};

static struct bt_gatt_service dps_svc = BT_GATT_SERVICE(attrs);

int dps_init(ble_dps_init_t *p_init)
{
    if (p_init->data_handler2 == NULL)
    {
        return -1;
    }
    else
    {
        ble_dps.data_handler2 = p_init->data_handler2;
    }

	/* Reset device info struct */
	memset(&devinfo, 0, sizeof(ble_device_info_t));
    
	return bt_gatt_service_register(&dps_svc);
}

void dps_set_device_info(ble_device_info_t * devinfo_new)
{
	memcpy(&devinfo, devinfo_new, sizeof(ble_device_info_t));
}

static ssize_t read_device_info(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			 void *buf, u16_t len, u16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &devinfo, sizeof(ble_device_info_t));
}

int dps_notify_loc_data(struct bt_conn *conn, u8_t *tx, uint16_t len)
{    
	if (!dps_tx_started) 
	{
		return -1;
	}
	return bt_gatt_notify(conn, &attrs[2], tx, len);//buf, len);
}

/* EOF */