[schematic2]
uniq 147
[tools]
[detail]
w 1642 1730 100 0 n#142 estatus.estatus#94.BI12 1360 1728 1984 1728 1984 2288 2432 2288 ebis.ebis#130.INP
w 1658 1698 100 0 n#141 estatus.estatus#94.LK12 1360 1696 2016 1696 2016 2256 2432 2256 ebis.ebis#130.SLNK
w 1674 1666 100 0 n#140 estatus.estatus#94.BI13 1360 1664 2048 1664 2048 2112 2432 2112 ebis.ebis#129.INP
w 1690 1634 100 0 n#139 estatus.estatus#94.LK13 1360 1632 2080 1632 2080 2080 2432 2080 ebis.ebis#129.SLNK
w 1706 1602 100 0 n#138 estatus.estatus#94.BI14 1360 1600 2112 1600 2112 1952 2432 1952 ebis.ebis#128.INP
w 1722 1570 100 0 n#137 estatus.estatus#94.LK14 1360 1568 2144 1568 2144 1920 2432 1920 ebis.ebis#128.SLNK
w 1738 1538 100 0 n#136 estatus.estatus#94.BI15 1360 1536 2176 1536 2176 1792 2432 1792 ebis.ebis#127.INP
w 1754 1506 100 0 n#135 estatus.estatus#94.LK15 1360 1504 2208 1504 2208 1760 2432 1760 ebis.ebis#127.SLNK
w 1770 1474 100 0 n#134 estatus.estatus#94.BI16 1360 1472 2240 1472 2240 1632 2432 1632 ebis.ebis#126.INP
w 1786 1442 100 0 n#133 estatus.estatus#94.LK16 1360 1440 2272 1440 2272 1600 2432 1600 ebis.ebis#126.SLNK
w 1802 1410 100 0 n#123 estatus.estatus#94.BI17 1360 1408 2304 1408 2304 1472 2432 1472 ebis.ebis#121.INP
w 1818 1378 100 0 n#122 estatus.estatus#94.LK17 1360 1376 2336 1376 2336 1440 2432 1440 ebis.ebis#121.SLNK
w 2082 1314 100 0 n#120 estatus.estatus#94.BI18 1360 1344 1792 1344 1792 1312 2432 1312 ebis.ebis#124.INP
w 2066 1282 100 0 n#119 estatus.estatus#94.LK18 1360 1312 1760 1312 1760 1280 2432 1280 ebis.ebis#124.SLNK
w 2050 1138 100 0 n#118 estatus.estatus#94.BI19 1360 1280 1728 1280 1728 1136 2432 1136 ebis.ebis#115.INP
w 2034 1106 100 0 n#117 estatus.estatus#94.LK19 1360 1248 1696 1248 1696 1104 2432 1104 ebis.ebis#115.SLNK
w 2018 978 100 0 n#114 estatus.estatus#94.BI20 1360 1216 1664 1216 1664 976 2432 976 ebis.ebis#112.INP
w 2002 946 100 0 n#113 estatus.estatus#94.LK20 1360 1184 1632 1184 1632 944 2432 944 ebis.ebis#112.SLNK
w 1954 642 100 0 n#103 estatus.estatus#94.BI22 1360 1088 1536 1088 1536 640 2432 640 ebis.ebis#99.INP
w 1938 610 100 0 n#102 estatus.estatus#94.LK22 1360 1056 1504 1056 1504 608 2432 608 ebis.ebis#99.SLNK
w 854 2562 100 0 n#3 hwin.hwin#2.in 800 2560 944 2560 estatus.estatus#94.INP
s 544 2320 100 0 Variable Data Buffer
s 544 2368 100 0 Use's PMAC Background
s 592 2448 100 0 Global Status Word 1
[cell use]
use ebis 2456 2184 100 0 ebis#130
xform 0 2560 2256
p 2544 2176 100 1024 -1 name:$(top)$(axis)$(ID)PCE
p 2704 2286 100 0 1 ONAM:PROM Checksum Error
p 2208 2126 100 0 0 ZNAM:PROM Checksum Error
use ebis 2456 2008 100 0 ebis#129
xform 0 2560 2080
p 2544 2000 100 1024 -1 name:$(top)$(axis)$(ID)MCE
p 2704 2110 100 0 1 ONAM:Memory Checksum Error
p 2208 1950 100 0 0 ZNAM:Memory Checksum Error
use ebis 2456 1848 100 0 ebis#128
xform 0 2560 1920
p 2544 1840 100 1024 -1 name:$(top)$(axis)$(ID)LCO
p 2704 1950 100 0 1 ONAM:Leadscrew Comp. on
p 2208 1790 100 0 0 ZNAM:Leadscrew Comp. on
use ebis 2456 1688 100 0 ebis#127
xform 0 2560 1760
p 2544 1680 100 1024 -1 name:$(top)$(axis)$(ID)SFA
p 2704 1790 100 0 1 ONAM:Stimulus Function Active
p 2208 1630 100 0 0 ZNAM:Stimulus Function Active
use ebis 2456 1528 100 0 ebis#126
xform 0 2560 1600
p 2544 1520 100 1024 -1 name:$(top)$(axis)$(ID)STE
p 2704 1630 100 0 1 ONAM:Stimulus Table Entered
p 2208 1470 100 0 0 ZNAM:Stimulus Table Entered
use ebis 2456 1208 100 0 ebis#124
xform 0 2560 1280
p 2544 1200 100 1024 -1 name:$(top)$(axis)$(ID)DGSOS
p 2704 1310 100 0 1 ONAM:Data Gather Start onServo
p 2208 1150 100 0 0 ZNAM:Data Gather Start onServo
use ebis 2456 1368 100 0 ebis#121
xform 0 2560 1440
p 2544 1360 100 1024 -1 name:$(top)$(axis)$(ID)DGOT
p 2704 1470 100 0 1 ONAM:Data Gather on Trigger
p 2208 1310 100 0 0 ZNAM:Data Gather on Trigger
use ebis 2456 1032 100 0 ebis#115
xform 0 2560 1104
p 2544 1024 100 1024 -1 name:$(top)$(axis)$(ID)DGO
p 2720 1134 100 0 1 ONAM:Data Gathering On
p 2208 974 100 0 0 ZNAM:Data Gathering On
use ebis 2456 872 100 0 ebis#112
xform 0 2560 944
p 2544 864 100 1024 -1 name:$(top)$(axis)$(ID)SE
p 2720 974 100 0 1 ONAM:Servo Error
p 2208 814 100 0 0 ZNAM:Servo Error
use ebis 2456 536 100 0 ebis#99
xform 0 2560 608
p 2544 528 100 1024 -1 name:$(top)$(axis)$(ID)RTIR
p 2720 638 100 0 1 ONAM:Real-Time Int. Re-entry
p 2208 478 100 0 0 ZNAM:Real-Time Int. Re-entry
use estatus 968 424 100 0 estatus#94
xform 0 1152 1520
p 1024 414 100 0 -1 name:$(top)$(axis)$(ID)
p 1104 2430 100 0 1 PINI:YES
p 1040 2382 100 0 1 DTYP:PMAC-VME DPRAM
p 1072 2318 100 0 1 SCAN:I/O Intr
use hwin 632 2520 100 0 hwin#2
xform 0 704 2560
p 608 2510 100 0 -1 val(in):#C$(CARD) S0 @$(ADDRESS1)
use bc200tr 384 200 -100 0 frame
xform 0 2064 1504
[comments]
