[schematic2]
uniq 13
[tools]
[detail]
w 2224 2723 100 0 n#6 estringouts.estringouts#60.OUT 2128 2720 2320 2720 2320 2976 junction
w 1360 2963 100 0 n#1 efanouts.efanouts#16.LNK3 1264 2960 1456 2960 1456 2736 1872 2736 estringouts.estringouts#60.SLNK
w 1800 2771 100 0 n#2 hwin.hwin#59.in 1728 2768 1872 2768 estringouts.estringouts#60.DOL
w 1824 2243 100 0 n#3 estringinval.estringinval#48.VAL 1776 2240 1872 2240 egenSub.egenSub#46.INPA
w 1312 2899 100 0 n#4 efanouts.efanouts#16.LNK5 1264 2896 1360 2896 1360 1568 1872 1568 egenSub.egenSub#46.SLNK
w 1360 3027 100 0 n#5 efanouts.efanouts#16.LNK1 1264 3024 1456 3024 1456 3360 1872 3360 estringouts.estringouts#44.SLNK
w 2304 2979 100 0 n#6 estringouts.estringouts#9.OUT 2128 2976 2480 2976 hwout.hwout#25.outp
w 2224 3347 100 0 n#6 estringouts.estringouts#44.OUT 2128 3344 2320 3344 2320 2976 junction
w 1800 3395 100 0 n#7 hwin.hwin#43.in 1728 3392 1872 3392 estringouts.estringouts#44.DOL
w 1328 2931 100 0 n#8 efanouts.efanouts#16.LNK4 1264 2928 1392 2928 1392 2496 1872 2496 eaos.eaos#1.SLNK
w 936 2947 100 0 SLNK inhier.SLNK.P 848 2944 1024 2944 efanouts.efanouts#16.SLNK
w 1328 3059 100 0 FLNK efanouts.efanouts#16.FLNK 1264 3056 1392 3056 1392 3536 1840 3536 outhier.FLNK.p
w 1568 2995 100 0 n#9 efanouts.efanouts#16.LNK2 1264 2992 1872 2992 estringouts.estringouts#9.SLNK
w 1800 3027 100 0 n#10 hwin.hwin#14.in 1728 3024 1872 3024 estringouts.estringouts#9.DOL
w 2240 2467 100 0 n#11 eaos.eaos#1.OUT 2128 2464 2352 2464 hwout.hwout#2.outp
w 1800 2531 100 0 n#12 hwin.hwin#0.in 1728 2528 1872 2528 eaos.eaos#1.DOL
n 1839 2621 2673 2645 100
WARNING: $(command) isn't passed down the chain when being called from gisAxis.sch
_
[cell use]
use bc200tr 352 1192 -100 0 frame
xform 0 2032 2496
use estringouts 1872 2919 100 0 estringouts#9
xform 0 2000 2992
p 1936 3072 100 0 1 DTYP:PMAC-VME ASCII
p 1936 3104 100 0 1 OMSL:closed_loop
p 1808 2958 100 0 0 VAL:
p 1984 2912 100 1024 -1 name:$(top)$(dev)$(command)PMAC_AbortS
use estringouts 1872 3287 100 0 estringouts#44
xform 0 2000 3360
p 1936 3440 100 0 1 DTYP:PMAC-VME ASCII
p 1936 3472 100 0 1 OMSL:closed_loop
p 1808 3326 100 0 0 VAL:
p 1984 3280 100 1024 -1 name:$(top)$(dev)$(command)PMAC_P_102_OFFS
use estringouts 1872 2663 100 0 estringouts#60
xform 0 2000 2736
p 1936 2816 100 0 1 DTYP:PMAC-VME ASCII
p 1936 2848 100 0 1 OMSL:closed_loop
p 1808 2702 100 0 0 VAL:
p 1984 2656 100 1024 1 name:$(top)$(dev)$(command)PMAC_CSPointStopS
use hwin 1536 2487 100 0 hwin#0
xform 0 1632 2528
p 1539 2520 100 0 -1 val(in):0
use hwin 1536 2983 100 0 hwin#14
xform 0 1632 3024
p 1536 3056 100 0 -1 val(in):$(top)PmacCmd_Abort
use hwin 1536 3351 100 0 hwin#43
xform 0 1632 3392
p 1536 3424 100 0 -1 val(in):$(top)PmacCmd_P102_OFF
use hwin 1536 2727 100 0 hwin#59
xform 0 1632 2768
p 1536 2800 100 0 -1 val(in):$(top)PmacCmd_CSPoint
use estringinval 1520 2183 100 0 estringinval#48
xform 0 1648 2256
p 1520 2350 100 0 0 VAL:$(dev) Tracking OFF
p 1456 1820 100 0 0 def(INP):$(dev) Tracking OFF
p 1632 2176 100 1024 -1 name:$(top)$(dev)$(command)Msg
use egenSub 1872 1479 100 0 egenSub#46
xform 0 2016 1904
p 1968 2240 100 0 1 FTA:STRING
p 1936 2320 100 0 1 SNAM:log_console
p 1984 1472 100 1024 1 name:$(top)$(dev)$(command)logMsg
use hwout 2352 2423 100 0 hwout#2
xform 0 2448 2464
p 2400 2400 100 0 -1 val(outp):$(top)FollowL .PP
use hwout 2480 2935 100 0 hwout#25
xform 0 2576 2976
p 2560 3008 100 0 -1 val(outp):#C$(card) S1
use efanouts 1024 2807 100 0 efanouts#16
xform 0 1144 2960
p 1120 3104 100 0 1 SELM:All
p 1136 2800 100 1024 -1 name:$(top)$(dev)$(command)trackingOffFO
p 1296 3024 75 1280 -1 pproc(LNK1):PP
p 1296 2992 75 1280 -1 pproc(LNK2):PP
p 1296 2928 75 1280 -1 pproc(LNK4):PP
use outhier 1808 3495 100 0 FLNK
xform 0 1824 3536
use inhier 832 2903 100 0 SLNK
xform 0 848 2944
use eaos 1872 2407 100 0 eaos#1
xform 0 2000 2496
p 1616 2478 100 0 0 OMSL:closed_loop
p 1984 2400 100 1024 -1 name:$(top)$(dev)$(command)TrackingOff
[comments]
