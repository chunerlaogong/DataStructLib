CAL_PATH:=$(call my-dir)

rs_base_CFLAGS :=  -Wall -Wno-unused-parameter -Wno-unused-variable -fno-exceptions
ifeq ($(TARGET_BUILD_PDK), true)
  rs_base_CFLAGS += -D__RS_PDK__
endif

ifneq ($(OVERRIDE_RS_DRIVER),)
  rs_base_CFLAGS += -DOVERRIDE_RS_DRIVER=$(OVERRIDE_RS_DRIVER)
endif

ifneq ($(DISABLE_RS_64_BIT_DRIVER),)
  rs_base_CFLAGS += -DDISABLE_RS_64_BIT_DRIVER
endif

ifeq ($(RS_FIND_OFFSETS), true)
  rs_base_CFLAGS += -DRS_FIND_OFFSETS
endif

include $(CLEAR_VARS)
ifneq ($(HOST_OS),windows)
LOCAL_CLANG := true
endif
LOCAL_MODULE := libdatastruct
LOCAL_MODULE_TARGET_ARCH_WARN := arm mips mips64 x86 x86_64 arm64

LOCAL_SRC_FILES:= \
	src/Object.cpp \
	src/Exception.cpp

LOCAL_SHARED_LIBRARIES += libRS libRSCpuRef libc++
LOCAL_SHARED_LIBRARIES += liblog libcutils libutils libEGL libGLESv1_CM libGLESv2
LOCAL_SHARED_LIBRARIES += libui libgui libsync

LOCAL_SHARED_LIBRARIES += libbcc libbcinfo libLLVM
LOCAL_SHARED_LIBRARIES += \
    libcutils \
    libbinder \
    libutils \
    libhardware

LOCAL_C_INCLUDES += ./include
LOCAL_C_INCLUDES += external/libcxx/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/

LOCAL_CFLAGS += $(rs_base_CFLAGS)
LOCAL_CPPFLAGS += -fexceptions

LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

