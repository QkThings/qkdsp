###############################################################################
# qkthings
###############################################################################

include $(TARGET_GLOBAL)


###############################################################################
# FILES and DIRS
###############################################################################
INCLUDE_DIR += \
$(ENERGYMICRO)/CMSIS/Include \
$(ENERGYMICRO)/Device/EnergyMicro/EFM32G/Include \
$(ENERGYMICRO)/emlib/inc

C_SRC_DIR += 

C_SRC += \
$(ENERGYMICRO)/Device/EnergyMicro/EFM32G/Source/system_efm32g.c

S_SRC += $(ENERGYMICRO)/Device/EnergyMicro/EFM32G/Source/GCC/startup_efm32g.S

