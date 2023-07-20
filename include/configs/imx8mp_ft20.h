/* SPDX-License-Identifier: GPL-2.0+ */
/*
 *
 */

#ifndef __IMX8MP_FT20_H
#define __IMX8MP_FT20_H

#include <asm/arch/imx-regs.h>
#include <linux/sizes.h>

#define CFG_SYS_UBOOT_BASE	\
	(QSPI0_AMBA_BASE + CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR * 512)


#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1) \
	func(USB, usb, 0) \
	func(USB, usb, 1) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>

#define CFG_EXTRA_ENV_SETTINGS BOOTENV

/* UART4 Console Config */
#define CFG_MXC_UART_BASE		UART4_BASE_ADDR
#define CFG_CONSOLE_DEV			"ttymxc3"


/* USDHC2 SD Boot Config */
#define CFG_SYS_FSL_USDHC_NUM   	1
#define CONFIG_SYS_FSL_ESDHC_ADDR	0
#define CFG_SYS_MMC_ENV_DEV     	0     		
#define CONFIG_MMCROOT			"/dev/mmcblk1p2"


/* Link Definitions */
#define CFG_SYS_INIT_RAM_ADDR		0x40000000
#define CFG_SYS_INIT_RAM_SIZE		0x80000


/* 4GB LPDDR4 Config */
#define CFG_SYS_SDRAM_BASE		0x40000000
#define PHYS_SDRAM			0x40000000
#define PHYS_SDRAM_SIZE			0x80000000      /* 2 GB */
#define PHYS_SDRAM_2			0xC0000000
#define PHYS_SDRAM_2_SIZE		0x80000000      /* 2 GB */


#endif /* __IMX8MP_FT20_H */

