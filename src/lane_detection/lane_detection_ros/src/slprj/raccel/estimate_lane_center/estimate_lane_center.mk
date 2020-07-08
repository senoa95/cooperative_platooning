# Copyright 1994-2018 The MathWorks, Inc.
#
# File    : raccel_unix.tmf   
#
# Abstract:
#	Template makefile for building a UNIX-based "rapid acceleration"
#       executable from the generated C code.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the build
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is -O.
#	  CPP_OPTS       - C++ compiler options.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc)
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see raccel.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = /usr/local/MATLAB/R2019b/bin/glnxa64/gmake
HOST            = UNIX
BUILD           = yes
SYS_TARGET_FILE = raccel.tlc
BUILD_SUCCESS	= *** Created

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = ["Clang v3.1 | gmake (64-bit Mac)", \
             "GNU gcc/g++ | gmake (64-bit Linux)"]

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  TGT_FCN_LIB         - Target function (code replacement) library to use


MODEL                  = estimate_lane_center
MODULES                = rt_logging.c estimate_lane_center.c estimate_lane_center_capi.c estimate_lane_center_data.c estimate_lane_center_tgtconn.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_logging_mmi.c rtw_modelmap_utils.c raccel_main_new.c raccel_sup.c raccel_mat.c simulink_solver_api.c raccel_utils.c common_utils.c ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c rtiostream_utils.c
MAKEFILE               = estimate_lane_center.mk
MATLAB_ROOT            = /usr/local/MATLAB/R2019b
ALT_MATLAB_ROOT        = /usr/local/MATLAB/R2019b
MATLAB_ROOTQ           = \"/usr/local/MATLAB/R2019b\"
MASTER_ANCHOR_DIR      = 
START_DIR              = /home/senoa95/cooperative_platooning/src/lane_detection/lane_detection_ros/src
S_FUNCTIONS_LIB        = $(MATLAB_ROOT)/bin/glnxa64/libmwcoder_target_services.so $(MATLAB_ROOT)/bin/glnxa64/libmwcoder_ParamTuningTgtAppSvc.so
COMPUTER               = GLNXA64
BUILDARGS              =  RSIM_SOLVER_SELECTION=2 PCMATLABROOT="/usr/local/MATLAB/R2019b" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 MODELREF_TARGET_TYPE=NONE ISPROTECTINGMODEL=NOTPROTECTING OPTS="-DTGTCONN -DON_TARGET_WAIT_FOR_START=0"
RSIM_PARAMETER_LOADING = 1
ENABLE_SLEXEC_SSBRIDGE = 1


TGT_FCN_LIB         = ISO_C

MODELREFS           = 
OPTIMIZATION_FLAGS  = -O0 -fPIC
ADDITIONAL_LDFLAGS  = 
DEFINES_CUSTOM      = -DEXT_MODE -DIS_RAPID_ACCEL 
SYSTEM_LIBS         = -L"/usr/local/MATLAB/R2019b/bin/glnxa64" -lmwipp -lut -lmx -lmex -lmat -lmwmathutil -lmwslexec_simbridge -lmwsl_fileio -lmwsigstream -lmwsl_AsyncioQueue -lmwsl_services -lmwsdi_raccel -lmwi18n -lmwsl_simtarget_instrumentation -lfixedpoint -lmwslexec_simlog -lm -lpthread -ldl

MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0


#--------------------------- Model and reference models -----------------------
MODELREF_LINK_LIBS        = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
GLOBAL_TIMING_ENGINE      = 0

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#--------------------------- Solver ---------------------------------------------
RSIM_WITH_SL_SOLVER = 1

#--------------------------- Tool Specifications -------------------------------

include $(MATLAB_ROOT)/rtw/c/tools/unixtools.mk

#------------------------------Parameter Tuning---------------------------------
PARAM_CC_OPTS = -DRSIM_PARAMETER_LOADING

#------------------------------ Include Path -----------------------------------

# Additional includes

ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/slprj/raccel/estimate_lane_center \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/rapid \
	-I$(MATLAB_ROOT)/rtw/c/raccel \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils \


INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES)

#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# General User Options
ifeq ($(DEBUG_BUILD),0)
DBG_FLAG =
else
#   Set OPTS=-g and any additional flags for debugging
DBG_FLAG = -g
LDFLAGS += -g
endif

# Compiler options, etc:
ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS)  $(PARAM_CC_OPTS) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPT_OPTS) $(OPTS)  $(PARAM_CC_OPTS)
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DHAVESTDIO -DUNIX

CPP_REQ_DEFINES += -DNRT \
                   -DRSIM_WITH_SL_SOLVER

ifneq ($(ENABLE_SLEXEC_SSBRIDGE), 0)
   CPP_REQ_DEFINES += -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
endif

CPP_REQ_DEFINES += -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)

CFLAGS = $(ANSI_OPTS) $(DBG_FLAG) $(CC_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_ANSI_OPTS) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES)

# g1593309
ifneq (,$(findstring MAC,$(COMPUTER)))
    GCC_WALL_FLAG += -Wno-invalid-source-encoding
endif

#----------------------------- Source Files ------------------------------------
USER_SRCS =
SRC_DEP =
PRODUCT            = $(MODEL)
BUILD_PRODUCT_TYPE = "executable"
REQ_SRCS = $(MODULES)

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS = $(REQ_SRCS)

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

#--------------------------- Link flags & libraries ----------------------------

LIBS =
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

BINDIR = $(MATLAB_ROOT)/bin/$(ARCH)

ifneq (,$(findstring GLNX,$(COMPUTER)))
  LDFLAGS += -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH) -L$(MATLAB_ROOT)/sys/os/$(ARCH)
endif

ifneq (,$(findstring MAC,$(COMPUTER)))
  LDFLAGS += -Wl,-rpath,$(BINDIR) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L$(MATLAB_ROOT)/sys/os/$(ARCH)
endif

#--------------------------------- Rules ---------------------------------------

$(PRODUCT) : $(OBJS) $(LIBS)  $(MODELREF_LINK_LIBS)
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(LINK_OBJS) $(MODELREF_LINK_LIBS) \
		$(LIBS) $(ADDITIONAL_LDFLAGS) $(SYSTEM_LIBS)
	@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@"

#-------------------------- Standard rules for building modules --------------

%.o : %.c
	$(CC) -c -o $(@F) $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS)$(GCC_WALL_FLAG)  "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -o $(@F) $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

rt_logging.o : /usr/local/MATLAB/R2019b/rtw/c/src/rt_logging.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rt_logging.c

raccel_main_new.o : /usr/local/MATLAB/R2019b/rtw/c/raccel/raccel_main_new.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/raccel/raccel_main_new.c

raccel_sup.o : /usr/local/MATLAB/R2019b/rtw/c/raccel/raccel_sup.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/raccel/raccel_sup.c

raccel_mat.o : /usr/local/MATLAB/R2019b/rtw/c/raccel/raccel_mat.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/raccel/raccel_mat.c

simulink_solver_api.o : /usr/local/MATLAB/R2019b/simulink/include/simulink_solver_api.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/simulink/include/simulink_solver_api.c

raccel_utils.o : /usr/local/MATLAB/R2019b/rtw/c/src/rapid/raccel_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rapid/raccel_utils.c

common_utils.o : /usr/local/MATLAB/R2019b/rtw/c/src/rapid/common_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rapid/common_utils.c

ext_svr.o : /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/ext_svr.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/ext_svr.c

updown.o : /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/updown.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/updown.c

ext_work.o : /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/ext_work.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/ext_work.c

rtiostream_interface.o : /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/rtiostream_interface.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/ext_mode/common/rtiostream_interface.c

rtiostream_tcpip.o : /usr/local/MATLAB/R2019b/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c

rtiostream_utils.o : /usr/local/MATLAB/R2019b/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c




%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"
%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"
%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"
%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"
%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"


# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

