[schematic2]
uniq 172
[tools]
[detail]
w 1754 2498 100 0 n#169 estatus.estatus#94.BI00 1360 2496 2208 2496 2208 2640 2432 2640 ebis.ebis#161.INP
w 1770 2466 100 0 n#168 estatus.estatus#94.LK00 1360 2464 2240 2464 2240 2608 2432 2608 ebis.ebis#161.SLNK
w 1786 2434 100 0 n#167 estatus.estatus#94.BI01 1360 2432 2272 2432 2272 2480 2432 2480 ebis.ebis#160.INP
w 1802 2402 100 0 n#166 estatus.estatus#94.LK01 1360 2400 2304 2400 2304 2448 2432 2448 ebis.ebis#160.SLNK
w 1690 2370 100 0 n#165 estatus.estatus#94.BI02 1360 2368 2080 2368 2080 2320 2432 2320 ebis.ebis#126.INP
w 1674 2338 100 0 n#164 estatus.estatus#94.LK02 1360 2336 2048 2336 2048 2288 2432 2288 ebis.ebis#126.SLNK
w 1658 2306 100 0 n#163 estatus.estatus#94.BI03 1360 2304 2016 2304 2016 2160 2432 2160 ebis.ebis#121.INP
w 1642 2276 100 0 n#162 estatus.estatus#94.LK03 1360 2272 1984 2272 1984 2128 2432 2128 ebis.ebis#121.SLNK
w 1802 1858 100 0 n#159 estatus.estatus#94.BI10 1360 1856 2304 1856 2304 1968 2432 1968 ebis.ebis#124.INP
w 1818 1826 100 0 n#158 estatus.estatus#94.LK10 1360 1824 2336 1824 2336 1936 2432 1936 ebis.ebis#124.SLNK
w 1866 1794 100 0 n#157 estatus.estatus#94.BI11 1360 1792 2432 1792 ebis.ebis#115.INP
w 1866 1762 100 0 n#156 estatus.estatus#94.LK11 1360 1760 2432 1760 ebis.ebis#115.SLNK
w 1866 1570 100 0 n#154 estatus.estatus#94.LK14 1360 1568 2432 1568 ebis.ebis#125.SLNK
w 1866 1602 100 0 n#153 estatus.estatus#94.BI14 1360 1600 2432 1600 ebis.ebis#125.INP
w 1986 1058 100 0 n#151 estatus.estatus#94.BI20 1360 1216 1600 1216 1600 1056 2432 1056 ecalcs.ecalcs#152.INPA
w 1970 1026 100 0 n#150 estatus.estatus#94.BI21 1360 1152 1568 1152 1568 1024 2432 1024 ecalcs.ecalcs#152.INPB
w 1954 994 100 0 n#149 estatus.estatus#94.BI22 1360 1088 1536 1088 1536 992 2432 992 ecalcs.ecalcs#152.INPC
w 1938 674 100 0 n#148 estatus.estatus#94.LK22 1360 1056 1504 1056 1504 672 2432 672 ecalcs.ecalcs#152.SLNK
w 1402 1122 100 0 n#148 estatus.estatus#94.LK21 1360 1120 1504 1120 1504 1056 junction
w 1402 1186 100 0 n#148 estatus.estatus#94.LK20 1360 1184 1504 1184 1504 1120 junction
w 1922 482 100 0 n#101 estatus.estatus#94.BI23 1360 1024 1472 1024 1472 480 2432 480 ebis.ebis#96.INP
w 1906 450 100 0 n#100 estatus.estatus#94.LK23 1360 992 1440 992 1440 448 2432 448 ebis.ebis#96.SLNK
w 854 2562 100 0 n#3 hwin.hwin#2.in 800 2560 944 2560 estatus.estatus#94.INP
s 544 2336 100 0 Fixed Data Buffer
s 624 2432 100 0 Status Word 2
s 544 2368 100 0 Use's PMAC Background
[cell use]
use bc200tr 384 200 -100 0 frame
xform 0 2064 1504
use ebis 2456 376 100 0 ebis#96
xform 0 2560 448
p 2704 494 100 0 1 ONAM:Assigned to CS
p 2208 318 100 0 0 ZNAM:Assigned to CS
p 2544 368 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)ATC
use ebis 2456 1688 100 0 ebis#115
xform 0 2560 1760
p 2720 1790 100 0 1 ONAM:Stopped on Position Limit
p 2208 1630 100 0 0 ZNAM:Stopped on Position Limit
p 2544 1680 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)SOPL
use ebis 2456 2056 100 0 ebis#121
xform 0 2560 2128
p 2704 2158 100 0 1 ONAM:Error
p 2704 2112 100 0 1 ZNAM:ok
p 2544 2048 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)AFE
use ebis 2456 1496 100 0 ebis#125
xform 0 2560 1568
p 2720 1598 100 0 1 ONAM:Amplifier Enabled
p 2208 1438 100 0 0 ZNAM:Amplifier Enabled
p 2544 1488 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)AE
use ebis 2456 2216 100 0 ebis#126
xform 0 2560 2288
p 2704 2318 100 0 1 ONAM:Error
p 2704 2272 100 0 1 ZNAM:ok
p 2544 2208 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)FFE
use ebis 2456 1864 100 0 ebis#124
xform 0 2560 1936
p 2704 1966 100 0 1 ONAM:Home Complete
p 2208 1806 100 0 0 ZNAM:Home Complete
p 2544 1856 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)HC
use ebis 2456 2376 100 0 ebis#160
xform 0 2560 2448
p 2704 2478 100 0 1 ONAM:Warning
p 2704 2432 100 0 1 ZNAM:ok
p 2544 2368 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)WFE
use ebis 2456 2536 100 0 ebis#161
xform 0 2560 2608
p 2704 2638 100 0 1 ONAM:In Position
p 2208 2478 100 0 0 ZNAM:In Position
p 2544 2528 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)IP
use ecalcs 2456 584 100 0 ecalcs#152
xform 0 2576 848
p 2624 702 100 0 1 CALC:1+A+2*B+4*C
p 2544 576 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)CSN
use estatus 968 424 100 0 estatus#94
xform 0 1152 1520
p 1040 2382 100 0 1 DTYP:PMAC-VME DPRAM
p 1104 2430 100 0 1 PINI:YES
p 1072 2318 100 0 1 SCAN:I/O Intr
p 1024 414 100 0 -1 name:$(top)$(axis)$(ID)$(NUM)
use hwin 632 2520 100 0 hwin#2
xform 0 704 2560
p 608 2510 100 0 -1 val(in):#C$(CARD) S0 @$(ADDRESS2)
[comments]
