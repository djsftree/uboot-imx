#
# Copyright 2019 NXP
#
# SPDX-License-Identifier:      GPL-2.0+
#

obj-y += mxa-200.o
obj-y += ../../freescale/common/

ifdef CONFIG_SPL_BUILD
obj-y += spl.o
ifdef CONFIG_IMX8M_LPDDR4_FREQ0_3200MTS
obj-y += lpddr4_timing_ndm.o
else
#obj-$(CONFIG_IMX8M_LPDDR4) += lpddr4_timing_MT53D512M32D2DS-046_ITD_2000MHz.o
#obj-$(CONFIG_IMX8M_LPDDR4) += lpddr4_timing_MT53D512M32D2DS-053_WTD_1500MHz.o
obj-$(CONFIG_IMX8M_LPDDR4) += lpddr4_timing_MT53E512M32D1ZW-046_WTD_2000MHz.o
obj-$(CONFIG_IMX8M_LPDDR4) += lpddr4_timing_MT53D1024M32D4DT-053_WTD_1500MHz.o
obj-$(CONFIG_IMX8M_DDR4) += ddr4_timing.o
endif
endif
