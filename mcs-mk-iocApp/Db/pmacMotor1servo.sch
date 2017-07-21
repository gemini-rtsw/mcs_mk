[schematic2]
uniq 4
[tools]
[detail]
w 2082 1314 100 0 n#1 estatus.estatus#94.BI18 1360 1344 1792 1344 1792 1312 2432 1312 ebis.ebis#124.INP
w 2066 1282 100 0 n#2 estatus.estatus#94.LK18 1360 1312 1760 1312 1760 1280 2432 1280 ebis.ebis#124.SLNK
w 854 2562 100 0 n#3 hwin.hwin#2.in 800 2560 944 2560 estatus.estatus#94.INP
s 624 2432 100 0 Status Word 1
s 544 2368 100 0 Use's PMAC Background
s 544 2320 100 0 Variable Data Buffer
[cell use]
use bc200tr 384 200 -100 0 frame
xform 0 2064 1504
use ebis 2456 1208 100 0 ebis#124
xform 0 2560 1280
p 2496 1392 100 0 1 ONAM:OFF
p 2496 1360 100 0 1 ZNAM:ON
p 2544 1200 100 1024 -1 name:$(top)$(axis)$(ID)$(NUM)OLM
use estatus 968 424 100 0 estatus#94
xform 0 1152 1520
p 1040 2382 100 0 1 DTYP:PMAC-VME DPRAM
p 1104 2430 100 0 1 PINI:YES
p 1072 2318 100 0 1 SCAN:I/O Intr
p 560 2176 100 0 1 SIML:
p 560 2224 100 0 1 SIOL:$(top)$(axis)Sim$(ID)$(NUM)
p 1024 414 100 0 -1 name:$(top)$(axis)$(ID)$(NUM)
use hwin 632 2520 100 0 hwin#2
xform 0 704 2560
p 608 2510 100 0 -1 val(in):#C$(CARD) S0 @$(ADDRESS1)
[comments]
