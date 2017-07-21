[schematic2]
uniq 98
[tools]
[detail]
w 2328 708 100 0 n#89 hwin.hwin#88.in 2272 704 2432 704 esirs.esirs#78.INP
w 536 1378 100 0 n#75 esirs.esirs#77.VAL 448 1344 512 1344 512 1376 608 1376 esirs.esirs#76.INP
w 482 1320 100 0 n#74 esirs.esirs#77.FLNK 448 1376 480 1376 480 1216 608 1216 esirs.esirs#76.SLNK
w 536 1730 100 0 n#67 esirs.esirs#68.VAL 448 1696 512 1696 512 1728 608 1728 esirs.esirs#69.INP
w 482 1672 100 0 n#66 esirs.esirs#68.FLNK 448 1728 480 1728 480 1568 608 1568 esirs.esirs#69.SLNK
w 536 2082 100 0 n#62 esirs.esirs#60.VAL 448 2048 512 2048 512 2080 608 2080 esirs.esirs#27.INP
w 482 2024 100 0 n#61 esirs.esirs#60.FLNK 448 2080 480 2080 480 1920 608 1920 esirs.esirs#27.SLNK
w 536 2466 100 0 n#47 esirs.esirs#45.VAL 448 2432 512 2432 512 2464 608 2464 esirs.esirs#44.INP
w 482 2408 100 0 n#46 esirs.esirs#45.FLNK 448 2464 480 2464 480 2304 608 2304 esirs.esirs#44.SLNK
[cell use]
use esirs 1240 392 100 0 esirs#97
xform 0 1424 544
p 1360 494 100 0 1 FTVL:DOUBLE
p 1360 462 100 0 1 PREC:14
p 1328 384 100 1024 -1 name:$(top)$(dev)PitchesToEC
use esirs 1848 2216 100 0 esirs#84
xform 0 2032 2368
p 1968 2318 100 0 1 FTVL:DOUBLE
p 1968 2286 100 0 1 PREC:14
p 1936 2208 100 1024 -1 name:$(top)$(dev)DemandVel
use esirs 2456 1864 100 0 esirs#82
xform 0 2640 2016
p 2576 1966 100 0 1 FTVL:LONG
p 2576 1934 100 0 0 PREC:0
p 2544 1856 100 1024 -1 name:$(top)$(dev)CountsPerDegree
use esirs 2456 1160 100 0 esirs#80
xform 0 2640 1312
p 2576 1262 100 0 1 FTVL:DOUBLE
p 2576 1230 100 0 1 PREC:14
p 2544 1152 100 1024 -1 name:$(top)$(dev)MaxVel
use esirs 2456 456 100 0 esirs#78
xform 0 2640 608
p 2576 558 100 0 1 FTVL:DOUBLE
p 2576 622 100 0 1 PINI:YES
p 2576 526 100 0 1 PREC:14
p 2576 590 100 0 1 SNAM:servofreqSIR
p 2544 448 100 1024 -1 name:$(top)$(dev)ServoFreq
use esirs 2456 2216 100 0 esirs#73
xform 0 2640 2368
p 2576 2318 100 0 1 FTVL:DOUBLE
p 2576 2286 100 0 1 PREC:14
p 2544 2208 100 1024 -1 name:$(top)$(dev)Park
use esirs 632 744 100 0 esirs#71
xform 0 816 896
p 752 846 100 0 1 FTVL:DOUBLE
p 752 814 100 0 1 PREC:14
p 720 736 100 1024 -1 name:$(top)$(dev)UpperLimit
use esirs 56 744 100 0 esirs#70
xform 0 240 896
p 176 846 100 0 1 FTVL:DOUBLE
p 176 814 100 0 1 PREC:14
p 144 736 100 1024 -1 name:$(top)$(dev)LowerLimit
use esirs 632 1480 100 0 esirs#69
xform 0 816 1632
p 768 1566 100 0 1 FTVL:STRING
p 704 1630 100 0 1 SNAM:axisVEalgoSIR
p 720 1472 100 1024 -1 name:$(top)$(dev)VEalgorithmS
use esirs 56 1480 100 0 esirs#68
xform 0 240 1632
p 192 1566 100 0 1 FTVL:LONG
p 144 1472 100 1024 -1 name:$(top)$(dev)VEalgorithmL
use esirs 632 1832 100 0 esirs#27
xform 0 816 1984
p 768 1918 100 0 1 FTVL:STRING
p 704 1982 100 0 1 SNAM:axisAccessSIR
p 720 1824 100 1024 -1 name:$(top)$(dev)AccessS
use esirs 632 2216 100 0 esirs#44
xform 0 816 2368
p 768 2302 100 0 1 FTVL:STRING
p 720 2366 100 0 1 SNAM:axisStateSIR
p 720 2208 100 1024 -1 name:$(top)$(dev)StateS
use esirs 56 2216 100 0 esirs#45
xform 0 240 2368
p 192 2302 100 0 1 FTVL:LONG
p 144 2208 100 1024 -1 name:$(top)$(dev)StateL
use esirs 56 1832 100 0 esirs#60
xform 0 240 1984
p 192 1918 100 0 1 FTVL:LONG
p 144 1824 100 1024 -1 name:$(top)$(dev)AccessL
use esirs 1240 1864 100 0 esirs#63
xform 0 1424 2016
p 1360 1966 100 0 1 FTVL:DOUBLE
p 1360 1934 100 0 1 PREC:14
p 1328 1856 100 1024 -1 name:$(top)$(dev)CurrentPos
use esirs 1240 1512 100 0 esirs#64
xform 0 1424 1664
p 1360 1614 100 0 1 FTVL:DOUBLE
p 1360 1582 100 0 1 PREC:14
p 1328 1504 100 1024 -1 name:$(top)$(dev)PosError
use esirs 1848 1864 100 0 esirs#65
xform 0 2032 2016
p 1968 1966 100 0 1 FTVL:DOUBLE
p 1968 1934 100 0 1 PREC:14
p 1936 1856 100 1024 -1 name:$(top)$(dev)CurrentVel
use esirs 1240 2216 100 0 esirs#72
xform 0 1424 2368
p 1360 2318 100 0 1 FTVL:DOUBLE
p 1360 2286 100 0 1 PREC:14
p 1328 2208 100 1024 -1 name:$(top)$(dev)DemandPos
use esirs 632 1128 100 0 esirs#76
xform 0 816 1280
p 768 1214 100 0 1 FTVL:STRING
p 704 1278 100 0 1 SNAM:axisVEheadsSIR
p 720 1120 100 1024 -1 name:$(top)$(dev)VEheadsS
use esirs 56 1128 100 0 esirs#77
xform 0 240 1280
p 192 1214 100 0 1 FTVL:LONG
p 144 1120 100 1024 -1 name:$(top)$(dev)VEheadsL
use esirs 2456 1512 100 0 esirs#79
xform 0 2640 1664
p 2576 1614 100 0 1 FTVL:DOUBLE
p 2576 1582 100 0 1 PREC:14
p 2544 1504 100 1024 -1 name:$(top)$(dev)LogFreq
use esirs 1240 1160 100 0 esirs#81
xform 0 1424 1312
p 1360 1262 100 0 1 FTVL:DOUBLE
p 1360 1230 100 0 1 PREC:14
p 1328 1152 100 1024 -1 name:$(top)$(dev)PmacDemandPos
use esirs 1240 808 100 0 esirs#83
xform 0 1424 960
p 1360 910 100 0 1 FTVL:DOUBLE
p 1360 878 100 0 1 PREC:14
p 1328 800 100 1024 -1 name:$(top)$(dev)PmacPosError
use esirs 1848 1512 100 0 esirs#85
xform 0 2032 1664
p 1968 1614 100 0 1 FTVL:DOUBLE
p 1968 1582 100 0 1 PREC:14
p 1936 1504 100 1024 -1 name:$(top)$(dev)VelError
use esirs 1848 1160 100 0 esirs#86
xform 0 2032 1312
p 1968 1262 100 0 1 FTVL:DOUBLE
p 1968 1230 100 0 1 PREC:14
p 1936 1152 100 1024 -1 name:$(top)$(dev)PmacDemandVel
use esirs 1848 808 100 0 esirs#87
xform 0 2032 960
p 1968 910 100 0 1 FTVL:DOUBLE
p 1968 878 100 0 1 PREC:14
p 1936 800 100 1024 -1 name:$(top)$(dev)PmacVelError
use esirs 2456 808 100 0 esirs#96
xform 0 2640 960
p 2576 910 100 0 1 FTVL:DOUBLE
p 2576 878 100 0 1 PREC:14
p 2544 800 100 1024 -1 name:$(top)$(dev)MaxAccel
use hwin 2104 664 100 0 hwin#88
xform 0 2176 704
p 2083 696 100 0 -1 val(in):$(card)
use bc200tr -224 104 -100 0 frame
xform 0 1456 1408
[comments]
