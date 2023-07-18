#
# Copyright 2019 NXP
#
# SPDX-License-Identifier:      GPL-2.0+
#

obj-y += lec-imx8mp.o

ifdef CONFIG_SPL_BUILD
obj-y += spl.o
obj-$(CONFIG_LPDDR4_2GB) += lpddr4_timing_MT53D512M32D2DS-053_WTD_1500MHz.o
obj-$(CONFIG_LPDDR4_2GK) += lpddr4_timing_MT53D512M32D2DS-046_ITD_2000MHz.o
obj-$(CONFIG_LPDDR4_4GB) += lpddr4_timing_MT53D1024M32D4DT-053_WTD_1500MHz.o
obj-$(CONFIG_LPDDR4_8GB) += lpddr4_timing_MT53E2G32D4DT-046_WTA_2000MHz.o
endif #CONFIG_SPL_BUILD
