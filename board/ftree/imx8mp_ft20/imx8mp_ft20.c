// SPDX-License-Identifier: GPL-2.0+
/*
 *
 */

#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <miiphy.h>
#include <netdev.h>
#include <linux/delay.h>
#include <asm/global_data.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm-generic/gpio.h>
#include <asm/arch/imx8mp_pins.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/gpio.h>

DECLARE_GLOBAL_DATA_PTR;


#define UART_PAD_CTRL		(PAD_CTL_DSE6 | PAD_CTL_FSEL1)
#define USDHC_PAD_CTRL		(PAD_CTL_DSE6 | PAD_CTL_HYS | PAD_CTL_PUE | PAD_CTL_FSEL2)
#define USDHC_GPIO_PAD_CTRL 	(PAD_CTL_PUE  | PAD_CTL_DSE1)
#define WDOG_PAD_CTRL		(PAD_CTL_DSE6 | PAD_CTL_ODE | PAD_CTL_PUE | PAD_CTL_PE)


static iomux_v3_cfg_t const uart_pads[] = {
	MX8MP_PAD_NAND_CLE__UART4_DCE_RX	| MUX_PAD_CTRL(UART_PAD_CTRL),
	MX8MP_PAD_NAND_DATA01__UART4_DCE_TX	| MUX_PAD_CTRL(UART_PAD_CTRL),
};


static iomux_v3_cfg_t const wdog_pads[] = {
	MX8MP_PAD_GPIO1_IO02__WDOG1_WDOG_B	| MUX_PAD_CTRL(WDOG_PAD_CTRL),
};


iomux_v3_cfg_t const usdhc2_pads[] = {
        MX8MP_PAD_SD2_CLK__USDHC2_CLK		| MUX_PAD_CTRL(USDHC_PAD_CTRL),
        MX8MP_PAD_SD2_CMD__USDHC2_CMD		| MUX_PAD_CTRL(USDHC_PAD_CTRL),
        MX8MP_PAD_SD2_DATA0__USDHC2_DATA0	| MUX_PAD_CTRL(USDHC_PAD_CTRL),
        MX8MP_PAD_SD2_DATA1__USDHC2_DATA1	| MUX_PAD_CTRL(USDHC_PAD_CTRL),
        MX8MP_PAD_SD2_DATA2__USDHC2_DATA2	| MUX_PAD_CTRL(USDHC_PAD_CTRL),
        MX8MP_PAD_SD2_DATA3__USDHC2_DATA3	| MUX_PAD_CTRL(USDHC_PAD_CTRL),
        MX8MP_PAD_SD2_CD_B__USDHC2_CD_B		| MUX_PAD_CTRL(USDHC_GPIO_PAD_CTRL),
};


int board_init(void)
{
	int ret = 0;

	imx_iomux_v3_setup_multiple_pads(wdog_pads,   ARRAY_SIZE(wdog_pads));
	imx_iomux_v3_setup_multiple_pads(uart_pads,   ARRAY_SIZE(uart_pads));
	imx_iomux_v3_setup_multiple_pads(usdhc2_pads, ARRAY_SIZE(uart_pads));

	init_uart_clk(5);

	return ret;
}


int board_late_init(void)
{
	return 0;
}

int ft_board_setup(void *fdt, struct bd_info *bd)
{
	return 0;
}
