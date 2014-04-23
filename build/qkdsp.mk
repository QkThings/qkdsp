####################################################################
# qkthings                                                      
####################################################################


####################################################################
# DIRS AND FLAGS                     
####################################################################

QKDSP_DIR = qkperipheral

INCLUDE_DIR += \
$(QKDSP_DIR)/include \
$(QKDSP_DIR)/lib/include

C_SRC_DIR += \
$(QKDSP_DIR)/lib

s_SRC += 
S_SRC += 

include $(QKDSP_DIR)/build/target/$(TARGET_NAME)/$(TARGET_NAME).mk


