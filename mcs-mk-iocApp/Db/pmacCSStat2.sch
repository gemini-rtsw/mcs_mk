[schematic2]
uniq 168
[tools]
[detail]
w 2114 994 100 0 n#167 estatus.estatus#94.LK23 1984 992 2304 992 2304 880 2496 880 ebis.ebis#165.SLNK
w 2130 1026 100 0 n#166 estatus.estatus#94.BI23 1984 1024 2336 1024 2336 912 2496 912 ebis.ebis#165.INP
w 2210 1058 100 0 n#164 estatus.estatus#94.LK22 1984 1056 2496 1056 ebis.ebis#128.SLNK
w 2210 1090 100 0 n#163 estatus.estatus#94.BI22 1984 1088 2496 1088 ebis.ebis#128.INP
w 2202 1954 100 0 n#162 estatus.estatus#94.LK08 1984 1952 2480 1952 ebis.ebis#129.SLNK
w 2202 1986 100 0 n#161 estatus.estatus#94.BI08 1984 1984 2480 1984 ebis.ebis#129.INP
w 2202 2210 100 0 n#158 estatus.estatus#94.LK04 1984 2208 2480 2208 ebis.ebis#130.SLNK
w 2202 2242 100 0 n#157 estatus.estatus#94.BI04 1984 2240 2480 2240 ebis.ebis#130.INP
w 1478 2562 100 0 n#3 hwin.hwin#2.in 1424 2560 1568 2560 estatus.estatus#94.INP
s 1248 2432 100 0 Status Word 2
s 1232 2352 100 0 Use's PMAC Background
s 1232 2320 100 0 Fixed Data Buffer
[cell use]
use ebis 2520 984 100 0 ebis#128
xform 0 2624 1056
p 2608 976 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)RTE
p 2768 1086 100 0 1 ONAM:Run-Time Error
p 2272 926 100 0 0 ZNAM:Run-Time Error
use ebis 2504 1880 100 0 ebis#129
xform 0 2608 1952
p 2592 1872 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)PMF
p 2752 1982 100 0 1 ONAM:Pre-jog Move Flag
p 2256 1822 100 0 0 ZNAM:Pre-jog Move Flag
use ebis 2504 2136 100 0 ebis#130
xform 0 2608 2208
p 2592 2128 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)PMM
p 2752 2238 100 0 1 ONAM:PVT/SPLINE Move Mode
p 2256 2078 100 0 0 ZNAM:PVT/SPLINE Move Mode
use ebis 2520 808 100 0 ebis#165
xform 0 2624 880
p 2608 800 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)PTA
p 2768 910 100 0 1 ONAM:Program Trace Active
p 2272 750 100 0 0 ZNAM:Program Trace Active
use estatus 1592 424 100 0 estatus#94
xform 0 1776 1520
p 1648 414 100 0 -1 name:$(top)$(axis)$(ID)$(NUM)
p 1728 2430 100 0 1 PINI:YES
p 1664 2382 100 0 1 DTYP:PMAC-VME DPRAM
p 1696 2318 100 0 1 SCAN:I/O Intr
use hwin 1256 2520 100 0 hwin#2
xform 0 1328 2560
p 1232 2510 100 0 -1 val(in):#C$(CARD) S0 @$(ADDRESS2)
use bc200tr 384 200 -100 0 frame
xform 0 2064 1504
[comments]
