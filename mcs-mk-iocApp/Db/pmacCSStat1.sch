[schematic2]
uniq 157
[tools]
[detail]
w 2146 2070 100 0 n#156 estatus.estatus#94.LK04 1984 2208 2144 2208 2144 1872 2480 1872 ebis.ebis#128.SLNK
w 2178 2102 100 0 n#155 estatus.estatus#94.BI04 1984 2240 2176 2240 2176 1904 2480 1904 ebis.ebis#128.INP
w 2314 2034 100 0 n#154 estatus.estatus#94.LK03 1984 2272 2208 2272 2208 2032 2480 2032 ebis.ebis#129.SLNK
w 2082 2306 100 0 n#153 estatus.estatus#94.BI03 1984 2304 2240 2304 2240 2064 2480 2064 ebis.ebis#129.INP
w 2098 2338 100 0 n#152 estatus.estatus#94.LK02 1984 2336 2272 2336 2272 2208 2480 2208 ebis.ebis#130.SLNK
w 2114 2370 100 0 n#151 estatus.estatus#94.BI02 1984 2368 2304 2368 2304 2240 2480 2240 ebis.ebis#130.INP
w 2130 2402 100 0 n#150 estatus.estatus#94.LK01 1984 2400 2336 2400 2336 2384 2480 2384 ebis.ebis#131.SLNK
w 2146 2434 100 0 n#149 estatus.estatus#94.BI01 1984 2432 2368 2432 2368 2416 2480 2416 ebis.ebis#131.INP
w 2266 2546 100 0 n#148 estatus.estatus#94.LK00 1984 2464 2112 2464 2112 2544 2480 2544 ebis.ebis#132.SLNK
w 2250 2578 100 0 n#147 estatus.estatus#94.BI00 1984 2496 2080 2496 2080 2576 2480 2576 ebis.ebis#132.INP
w 1478 2562 100 0 n#3 hwin.hwin#2.in 1424 2560 1568 2560 estatus.estatus#94.INP
s 1248 2432 100 0 Status Word 1
s 1216 2368 100 0 Use's PMAC Background
s 1232 2336 100 0 Fixed Data Buffer
[cell use]
use ebis 2504 2472 100 0 ebis#132
xform 0 2608 2544
p 2592 2464 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)RP
p 2752 2526 100 0 1 ONAM:Running Program
p 2256 2414 100 0 0 ZNAM:Running Program
use ebis 2504 2312 100 0 ebis#131
xform 0 2608 2384
p 2592 2304 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)SSM
p 2752 2414 100 0 1 ONAM:Single-Step Mode
p 2256 2254 100 0 0 ZNAM:Single-Step Mode
use ebis 2504 2136 100 0 ebis#130
xform 0 2608 2208
p 2592 2128 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)CMM
p 2752 2238 100 0 1 ONAM:Continuous Motion Mode
p 2256 2078 100 0 0 ZNAM:Continuous Motion Mode
use ebis 2504 1960 100 0 ebis#129
xform 0 2608 2032
p 2592 1952 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)MBTM
p 2752 2062 100 0 1 ONAM:Move-by-Time Mode
p 2256 1902 100 0 0 ZNAM:Move-by-Time Mode
use ebis 2504 1800 100 0 ebis#128
xform 0 2608 1872
p 2592 1792 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)CMR
p 2752 1902 100 0 1 ONAM:Continuous Motion Request
p 2256 1742 100 0 0 ZNAM:Continuous Motion Request
use estatus 1592 424 100 0 estatus#94
xform 0 1776 1520
p 1648 414 100 0 -1 name:$(top)$(axis)$(ID)$(NUM)
p 1728 2430 100 0 1 PINI:YES
p 1664 2382 100 0 1 DTYP:PMAC-VME DPRAM
p 1696 2318 100 0 1 SCAN:I/O Intr
use hwin 1256 2520 100 0 hwin#2
xform 0 1328 2560
p 1232 2510 100 0 -1 val(in):#C$(CARD) S0 @$(ADDRESS1)
use bc200tr 384 200 -100 0 frame
xform 0 2064 1504
[comments]
