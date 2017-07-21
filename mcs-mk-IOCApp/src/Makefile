TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = mcs-mk-IOC
# mcs-mk-IOC.dbd will be created and installed
DBD += mcs-mk-IOC.dbd

# mcs-mk-IOC.dbd will be made up from these files:
mcs-mk-IOC_DBD += base.dbd

# Include dbd files from all support modules:
#mcs-mk-IOC_DBD += xxx.dbd

# Add all the support libraries used by this IOC
# mcs-mk-IOC_LIBS += xxx
# mcs-mk-IOC_LIBS += seq pv seqDev

# mcs-mk-IOC_registerRecordDeviceDriver.cpp derives from mcs-mk-IOC.dbd
mcs-mk-IOC_SRCS += mcs-mk-IOC_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
mcs-mk-IOC_SRCS_DEFAULT += mcs-mk-IOCMain.cpp

# Finally link to the EPICS Base libraries
mcs-mk-IOC_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

