[schematic2]
uniq 48
[tools]
[detail]
w 1832 555 100 0 n#25 efanouts.tFan.LNK1 2928 1072 3232 1072 3232 544 480 544 480 1312 junction
w 376 1314 100 0 n#25 inhier.STOP.P 160 1312 640 1312 elongouts.tStp.SLNK
w 3128 1803 100 0 n#25 efanouts.efanouts#43.LNK2 3072 1792 3232 1792 3232 1072 junction
w 2640 1387 100 0 n#47 efanouts.efanouts#43.LNK1 3072 1824 3152 1824 3152 1376 2176 1376 2176 880 2256 880 ecalcs.tExp.SLNK
w 2320 2018 100 0 n#45 hwin.hwin#46.in 2288 2016 2400 2016 ecalcs.ecalcs#42.INPA
w 2754 1818 100 0 n#40 ecalcs.ecalcs#42.FLNK 2688 1856 2752 1856 2752 1744 2832 1744 efanouts.efanouts#43.SLNK
w 2766 1826 100 0 n#39 ecalcs.ecalcs#42.VAL 2688 1824 2880 1824 efanouts.efanouts#43.SELL
w 1282 1552 100 0 n#38 elongouts.tTog.VAL 1216 1456 1280 1456 1280 1600 1392 1600 ecalc.tInc.INPB
w 930 1536 100 0 n#37 elongouts.tGo.OUT 896 1568 928 1568 928 1456 960 1456 elongouts.tTog.SLNK
w 930 1392 100 0 n#37 elongouts.tStp.OUT 896 1280 928 1280 928 1456 junction
w 3008 1042 100 0 n#35 efanouts.tFan.LNK2 2928 1040 3136 1040 outhier.TIMEOUT.p
w 2224 1643 100 0 n#33 ecalc.tInc.FLNK 2096 1632 2400 1632 ecalcs.ecalcs#42.SLNK
w 2016 1019 100 0 n#32 eaos.tOut.VAL 1936 1008 2144 1008 2144 1232 2256 1232 ecalcs.tExp.INPB
w 1688 1922 100 0 n#29 ecalc.tInc.VAL 2096 1536 2144 1536 2144 1920 1280 1920 1280 1632 1392 1632 ecalc.tInc.INPA
w 2176 1275 100 0 n#29 junction 2144 1536 2144 1264 2256 1264 ecalcs.tExp.INPA
w 376 1602 100 0 n#24 inhier.START.P 160 1600 640 1600 elongouts.tGo.SLNK
w 560 1346 100 0 n#19 hwin.hwin#17.in 528 1344 640 1344 elongouts.tStp.DOL
w 560 1634 100 0 n#18 hwin.hwin#16.in 528 1632 640 1632 elongouts.tGo.DOL
w 1608 1042 100 0 n#10 hwin.hwin#9.in 1584 1040 1680 1040 eaos.tOut.DOL
w 2610 1066 100 0 n#5 ecalcs.tExp.FLNK 2544 1104 2608 1104 2608 992 2688 992 efanouts.tFan.SLNK
w 2622 1074 100 0 n#4 ecalcs.tExp.VAL 2544 1072 2736 1072 efanouts.tFan.SELL
s 2832 192 100 0 Gemini Mount Control System
s 2592 2384 100 0 $Id: mcsTimeout.sch,v 1.1 2008/08/25 19:49:32 gemvx Exp $
s 1344 2240 200 0 Timeout counter 
s 544 1088 100 0 The toggle record is only present as it proved impossible
s 544 1056 100 0 to define a user port on the calc record for field B.
s 544 1024 100 0 Defining FLD4 as B resulted in being unable to write
s 544 992 100 0 anything into field B even from cau.
s 1216 2176 100 0 The counter increments once a second until the timeout
s 1216 2144 100 0 period is exceeded or the counter is stopped. If the timeout
s 1216 2112 100 0 period is exceeded then the TIMEOUT output link is triggered.
s 1216 2032 100 0 To use the schematic the macros timeout and top must
s 1216 2000 100 0 both be defined on a higher level schematic.
[cell use]
use hwin 360 1304 100 0 hwin#17
xform 0 432 1344
p 339 1336 100 0 -1 val(in):0
use hwin 360 1592 100 0 hwin#16
xform 0 432 1632
p 339 1624 100 0 -1 val(in):1
use hwin 1416 1000 100 0 hwin#9
xform 0 1488 1040
p 1395 1032 100 0 -1 val(in):$(timeout)
use hwin 2120 1976 100 0 hwin#46
xform 0 2192 2016
p 1984 1968 100 0 -1 val(in):$(top)$(dev)DriveCondition
use efanouts 2712 856 100 0 tFan
xform 0 2808 1008
p 2544 974 100 0 0 SELM:Mask
p 2800 848 100 1024 0 name:$(top)$(dev)tFan
use efanouts 2856 1608 100 0 efanouts#43
xform 0 2952 1760
p 2688 1726 100 0 0 SELM:Mask
p 2944 1600 100 1024 -1 name:$(top)$(dev)DriveCondFanout
use ecalcs 2280 792 100 0 tExp
xform 0 2400 1056
p 2368 990 100 0 -1 CALC:A>B?3:0
p 2320 1326 100 0 -1 DESC:Check for expiry
p 2368 784 100 1024 0 name:$(top)$(dev)tExp
use ecalcs 2424 1544 100 0 ecalcs#42
xform 0 2544 1808
p 2512 1742 100 0 -1 CALC:A=2?3:1
p 2464 2078 100 0 -1 DESC:Check for drive condition
p 2512 1536 100 1024 -1 name:$(top)$(dev)DriveCond
use elongouts 664 1224 100 0 tStp
xform 0 768 1312
p 704 1422 100 0 -1 DESC:Stop timer
p 480 1230 100 0 0 OMSL:closed_loop
p 752 1216 100 1024 0 name:$(top)$(dev)tStp
p 896 1280 75 768 -1 pproc(OUT):PP
use elongouts 664 1512 100 0 tGo
xform 0 768 1600
p 704 1710 100 0 -1 DESC:Start timer
p 480 1518 100 0 0 OMSL:closed_loop
p 752 1504 100 1024 0 name:$(top)$(dev)tGo
p 896 1568 75 768 -1 pproc(OUT):PP
use elongouts 984 1368 100 0 tTog
xform 0 1088 1456
p 1024 1566 100 0 -1 DESC:Toggle timer
p 800 1374 100 0 0 OMSL:supervisory
p 1072 1360 100 1024 0 name:$(top)$(dev)tTog
use ecalc 1416 1160 100 0 tInc
xform 0 1744 1488
p 1520 1278 100 0 0 ADEL:0.000000000000000e+00
p 1715 1736 100 0 -1 CALC:B=1?A+1:0
p 1601 1686 100 0 1 DESC:Incrementing counter
p 1520 1470 100 0 0 DISS:NO_ALARM
p 1520 1502 100 0 1 DISV:1
p 1520 1406 100 0 1 EGU:none
p 1520 1566 100 0 0 EVNT:0
p 1776 1438 100 0 0 HHSV:NO_ALARM
p 1776 1502 100 0 0 HIGH:0.0000000e+00
p 1776 1566 100 0 0 HIHI:0.0000000e+00
p 1776 1630 100 0 0 HOPR:0.0000000e+00
p 1776 1406 100 0 0 HSV:NO_ALARM
p 1520 1310 100 0 0 HYST:0.000000000000000e+00
p 1776 1342 100 0 0 LLSV:NO_ALARM
p 1776 1534 100 0 0 LOLO:0.0000000e+00
p 1776 1598 100 0 0 LOPR:0.0000000e+00
p 1776 1470 100 0 0 LOW:0.0000000e+00
p 1776 1374 100 0 0 LSV:NO_ALARM
p 1520 1246 100 0 0 MDEL:0.000000000000000e+00
p 1520 1598 100 0 0 PHAS:0
p 1520 1534 100 0 0 PINI:NO
p 1520 1374 100 0 0 PREC:0
p 1520 1438 100 0 0 PRIO:LOW
p 1520 1630 100 0 1 SCAN:1 second
p 1504 1152 100 1024 0 name:$(top)$(dev)tInc
p 1424 1760 100 1024 -1 username(U4):FLD4
use inhier 168 1272 100 0 STOP
xform 0 160 1312
use inhier 168 1560 100 0 START
xform 0 160 1600
use eaos 1704 920 100 0 tOut
xform 0 1808 1008
p 1744 1118 100 0 -1 DESC:Timeout value
p 1648 734 100 0 0 EGU:seconds
p 1424 990 100 0 0 OMSL:closed_loop
p 1792 912 100 1024 0 name:$(top)$(dev)tOut
use outhier 3128 1000 100 0 TIMEOUT
xform 0 3120 1040
use bc200tr 0 -88 -100 0 frame
xform 0 1680 1216
[comments]
