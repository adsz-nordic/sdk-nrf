/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 * Copyright (c) 2020 Prevas A/S
 * Copyright (c) 2025 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <common.h>
#include "ab_utils.h"

#include <zephyr/retention/blinfo.h>
#include <bootutil/image.h>

#define LOG_LEVEL LOG_LEVEL_DBG
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(ab_sample);

static void blinfo_bootloader_version(void)
{
	struct image_version version = {0x00};

	int ret = blinfo_lookup(BLINFO_BOOTLOADER_VERSION,
				(char *)&version,
				sizeof(struct image_version));


	if (ret < 0) {
		LOG_INF("blinfo_lookup error: %d", ret);

	} else {
		LOG_INF("bl iv_major: %d", version.iv_major);
		LOG_INF("bl iv_minor: %d", version.iv_minor);
		LOG_INF("bl iv_revision: %d", version.iv_revision);
		LOG_INF("bl iv_build_num: %d", version.iv_build_num);
	}
}

int main(void)
{
#ifdef CONFIG_MCUMGR_TRANSPORT_BT
	start_smp_bluetooth_adverts();
#endif

	/* Give BLE a moment to start up */
	k_sleep(K_MSEC(1000));

	ab_actions_perform();

	/* using __TIME__ ensure that a new binary will be built on every
	 * compile which is convenient when testing firmware upgrade.
	 */
	LOG_INF("build time: " __DATE__ " " __TIME__);

	blinfo_bootloader_version();

	/* The system work queue handles all incoming mcumgr requests.  Let the
	 * main thread idle while the mcumgr server runs.
	 */
	while (1) {
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
