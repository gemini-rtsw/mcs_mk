[schematic2]
uniq 149
[tools]
[detail]
w 1690 1794 100 0 n#148 estatus.estatus#94.BI11 1360 1792 2080 1792 2080 1952 2432 1952 ebis.ebis#128.INP
w 1706 1762 100 0 n#147 estatus.estatus#94.LK11 1360 1760 2112 1760 2112 1920 2432 1920 ebis.ebis#128.SLNK
w 1738 1538 100 0 n#136 estatus.estatus#94.BI15 1360 1536 2176 1536 2176 1792 2432 1792 ebis.ebis#127.INP
w 1754 1506 100 0 n#135 estatus.estatus#94.LK15 1360 1504 2208 1504 2208 1760 2432 1760 ebis.ebis#127.SLNK
w 1802 1410 100 0 n#123 estatus.estatus#94.BI17 1360 1408 2304 1408 2304 1472 2432 1472 ebis.ebis#121.INP
w 1818 1378 100 0 n#122 estatus.estatus#94.LK17 1360 1376 2336 1376 2336 1440 2432 1440 ebis.ebis#121.SLNK
w 2082 1314 100 0 n#120 estatus.estatus#94.BI18 1360 1344 1792 1344 1792 1312 2432 1312 ebis.ebis#124.INP
w 2066 1282 100 0 n#119 estatus.estatus#94.LK18 1360 1312 1760 1312 1760 1280 2432 1280 ebis.ebis#124.SLNK
w 2050 1138 100 0 n#118 estatus.estatus#94.BI19 1360 1280 1728 1280 1728 1136 2432 1136 ebis.ebis#115.INP
w 2034 1106 100 0 n#117 estatus.estatus#94.LK19 1360 1248 1696 1248 1696 1104 2432 1104 ebis.ebis#115.SLNK
w 1954 642 100 0 n#103 estatus.estatus#94.BI22 1360 1088 1536 1088 1536 640 2432 640 ebis.ebis#99.INP
w 1938 610 100 0 n#102 estatus.estatus#94.LK22 1360 1056 1504 1056 1504 608 2432 608 ebis.ebis#99.SLNK
w 854 2562 100 0 n#3 hwin.hwin#2.in 800 2560 944 2560 estatus.estatus#94.INP
s 544 2368 100 0 Use's PMAC Background
s 544 2320 100 0 Variable Data Buffer
s 592 2464 100 0 Global Status Word 2
[cell use]
use ebis 2456 536 100 0 ebis#99
xform 0 2560 608
p 2544 528 100 1024 -1 name:$(top)$(axis)$(ID)HCM
p 2720 638 100 0 1 ONAM:Host Communication Mode
p 2208 478 100 0 0 ZNAM:Host Communication Mode
use ebis 2456 1032 100 0 ebis#115
xform 0 2560 1104
p 2544 1024 100 1024 -1 name:$(top)$(axis)$(ID)MBO
p 2720 1134 100 0 1 ONAM:Motion Buffer Open
p 2208 974 100 0 0 ZNAM:Motion Buffer Open
use ebis 2456 1368 100 0 ebis#121
xform 0 2560 1440
p 2544 1360 100 1024 -1 name:$(top)$(axis)$(ID)PBO
p 2704 1470 100 0 1 ONAM:PLC Buffer Open
p 2208 1310 100 0 0 ZNAM:PLC Buffer Open
use ebis 2456 1208 100 0 ebis#124
xform 0 2560 1280
p 2544 1200 100 1024 -1 name:$(top)$(axis)$(ID)RBO
p 2704 1310 100 0 1 ONAM:Rotary Buffer Open
p 2208 1150 100 0 0 ZNAM:Rotary Buffer Open
use ebis 2456 1688 100 0 ebis#127
xform 0 2560 1760
p 2544 1680 100 1024 -1 name:$(top)$(axis)$(ID)VCM
p 2704 1790 100 0 1 ONAM:VME Communication Mode
p 2208 1630 100 0 0 ZNAM:VME Communication Mode
use ebis 2456 1848 100 0 ebis#128
xform 0 2560 1920
p 2544 1840 100 1024 -1 name:$(top)$(axis)$(ID)FBF
p 2704 1950 100 0 1 ONAM:Fixed Buffer Full
p 2208 1790 100 0 0 ZNAM:Fixed Buffer Full
use estatus 968 424 100 0 estatus#94
xform 0 1152 1520
p 1024 414 100 0 -1 name:$(top)$(axis)$(ID)
p 1104 2430 100 0 1 PINI:YES
p 1040 2382 100 0 1 DTYP:PMAC-VME DPRAM
p 1072 2318 100 0 1 SCAN:I/O Intr
use hwin 632 2520 100 0 hwin#2
xform 0 704 2560
p 608 2510 100 0 -1 val(in):#C$(CARD) S0 @$(ADDRESS2)
use bc200tr 384 200 -100 0 frame
xform 0 2064 1504
[comments]
