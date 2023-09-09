TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

USR_CFLAGS   += -DTELESCOPE


PROD_IOC_RTEMS = mcs-mk-ioc
# mcs-mk-ioc.dbd will be created and installed
DBD += mcs-mk-ioc.dbd

# mcs-mk-ioc.dbd will be made up from these files:
mcs-mk-ioc_DBD += base.dbd
mcs-mk-ioc_DBD += menuScan.dbd
#mcs-mk-ioc_DBD += iocAdmin.dbd    
mcs-mk-ioc_DBD += geminiRecords.dbd        
mcs-mk-ioc_DBD += pvload.dbd   
mcs-mk-ioc_DBD += loadRecord.dbd
mcs-mk-ioc_DBD += pmacDev.dbd
#mcs-mk-ioc_DBD += bancommDev.dbd 
mcs-mk-ioc_DBD += xy240Supp.dbd 
mcs-mk-ioc_DBD += xy566Supp.dbd 
mcs-mk-ioc_DBD += timelibSupp.dbd 
mcs-mk-ioc_DBD += slalib.dbd
mcs-mk-ioc_DBD += timeProbeSupp.dbd 
mcs-mk-ioc_DBD += listAlarmRecords.dbd
#mcs-mk-ioc_DBD += initTrace.dbd
#mcs-mk-ioc_DBD += spy.dbd
mcs-mk-ioc_DBD += net_config.dbd
mcs-mk-ioc_DBD += mcs.dbd 

# Include dbd files from all support modules:
#mcs-mk-ioc_DBD += xxx.dbd

# Add all the support libraries used by this IOC
# mcs-mk-ioc_LIBS += xxx
# mcs-mk-ioc_LIBS += seq pv seqDev
#mcs-mk-ioc_LIBS += devIocStats        
mcs-mk-ioc_LIBS += geminiRecords        
mcs-mk-ioc_LIBS += pvload             
#mcs-mk-ioc_LIBS += bancomm
mcs-mk-ioc_LIBS += xy240
mcs-mk-ioc_LIBS += xy566
mcs-mk-ioc_LIBS += pmaclib
mcs-mk-ioc_LIBS += timelib
mcs-mk-ioc_LIBS += slalib
mcs-mk-ioc_LIBS += timeProbe
mcs-mk-ioc_LIBS += seq pv
mcs-mk-ioc_LIBS += autosave
mcs-mk-ioc_LIBS += listAlarmRecords
#mcs-mk-ioc_LIBS += rtemsutils

# mcs-mk-ioc_registerRecordDeviceDriver.cpp derives from mcs-mk-ioc.dbd
mcs-mk-ioc_SRCS += mcs-mk-ioc_registerRecordDeviceDriver.cpp

mcs-mk-ioc_SRCS += azconfigCAD.c
mcs-mk-ioc_SRCS += cwmoveCAD.c
mcs-mk-ioc_SRCS += datumCAD.c
mcs-mk-ioc_SRCS += debugCAD.c
mcs-mk-ioc_SRCS += elconfigCAD.c
mcs-mk-ioc_SRCS += followCAD.c
mcs-mk-ioc_SRCS += initCAD.c
mcs-mk-ioc_SRCS += logDataCAD.c
mcs-mk-ioc_SRCS += logTrackingCAD.c
mcs-mk-ioc_SRCS += moveCAD.c
mcs-mk-ioc_SRCS += parkCAD.c
mcs-mk-ioc_SRCS += rebootCAD.c
mcs-mk-ioc_SRCS += reloadCAD.c
mcs-mk-ioc_SRCS += simulateCAD.c
mcs-mk-ioc_SRCS += stopCAD.c
mcs-mk-ioc_SRCS += testCAD.c
mcs-mk-ioc_SRCS += testLanCAD.c
mcs-mk-ioc_SRCS += toleranceCAD.c
mcs-mk-ioc_SRCS += trajectoryCAD.c

mcs-mk-ioc_SRCS += arraySIR.c
mcs-mk-ioc_SRCS += axisAccessSIR.c
mcs-mk-ioc_SRCS += axisStateSIR.c
mcs-mk-ioc_SRCS += axisVEalgoSIR.c
mcs-mk-ioc_SRCS += axisVEheadsSIR.c
mcs-mk-ioc_SRCS += commandSIR.c
mcs-mk-ioc_SRCS += datumMechSIR.c
mcs-mk-ioc_SRCS += datumSIR.c
mcs-mk-ioc_SRCS += debugSIR.c
mcs-mk-ioc_SRCS += followSIR.c
mcs-mk-ioc_SRCS += healthSIR.c
mcs-mk-ioc_SRCS += inPositionSIR.c
mcs-mk-ioc_SRCS += logDataSIR.c
mcs-mk-ioc_SRCS += mcHealthSIR.c
mcs-mk-ioc_SRCS += servofreqSIR.c
mcs-mk-ioc_SRCS += simulateSIR.c
mcs-mk-ioc_SRCS += slewSIR.c
mcs-mk-ioc_SRCS += stateSIR.c
mcs-mk-ioc_SRCS += trajectorySIR.c
mcs-mk-ioc_SRCS += wrapSIR.c

mcs-mk-ioc_SRCS += axis.c
mcs-mk-ioc_SRCS += caLogDataDriver.c
mcs-mk-ioc_SRCS += caput.c
mcs-mk-ioc_SRCS += carCombines.c
mcs-mk-ioc_SRCS += datum.c
mcs-mk-ioc_SRCS += endCommand.c
mcs-mk-ioc_SRCS += follow.c
#mcs-mk-ioc_SRCS += getTime.c
mcs-mk-ioc_SRCS += healthRoutines.c
mcs-mk-ioc_SRCS += logData.c
mcs-mk-ioc_SRCS += miscRoutines.c
mcs-mk-ioc_SRCS += pmacLogin.c
mcs-mk-ioc_SRCS += pvloadCalls.c
mcs-mk-ioc_SRCS += simRoutines.c
mcs-mk-ioc_SRCS += tcsRandom.c
mcs-mk-ioc_SRCS += tcsServo.c
#mcs-mk-ioc_SRCS += test.c
mcs-mk-ioc_SRCS += testFollow.c
mcs-mk-ioc_SRCS += testLan.c
mcs-mk-ioc_SRCS += trajectory.c
#mcs-mk-ioc_SRCS += initTrace.c
mcs-mk-ioc_SRCS += net_config.c

INC += tcsServo.h
INC += tcsRandom.h
INC += mcs.h
INC += mcscad.h
INC += caLogDataDriver.h


# Build the main IOC entry point on workstation OSs.
mcs-mk-ioc_SRCS_DEFAULT += mcs-mk-iocMain.cpp


# Finally link to the EPICS Base libraries
mcs-mk-ioc_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

