[schematic2]
uniq 24
[tools]
[detail]
w 1506 1368 100 0 n#17 egenSub.egenSub#4.FLNK 1248 1088 1504 1088 1504 1600 1600 1600 ecars.ecars#14.SLNK
w 1400 1730 100 0 n#16 egenSub.egenSub#4.OUTB 1248 1728 1600 1728 ecars.ecars#14.IMSS
w 1400 1794 100 0 n#15 egenSub.egenSub#4.OUTA 1248 1792 1600 1792 ecars.ecars#14.IVAL
w 610 1600 100 0 n#13 ecars.ecars#0.FLNK 400 2032 608 2032 608 1120 960 1120 egenSub.egenSub#4.SLNK
w 480 1586 100 0 n#13 ecars.ecars#1.FLNK 400 1584 608 1584 junction
w 480 1122 100 0 n#13 ecars.ecars#2.FLNK 400 1120 608 1120 junction
w 560 1282 100 0 n#10 ecars.ecars#2.OMSS 400 1280 768 1280 768 1472 960 1472 egenSub.egenSub#4.INPF
w 550 1346 100 0 n#9 ecars.ecars#2.VAL 400 1344 736 1344 736 1536 960 1536 egenSub.egenSub#4.INPE
w 550 1746 100 0 n#8 ecars.ecars#1.OMSS 400 1744 736 1744 736 1600 960 1600 egenSub.egenSub#4.INPD
w 566 1810 100 0 n#7 ecars.ecars#1.VAL 400 1808 768 1808 768 1664 960 1664 egenSub.egenSub#4.INPC
w 802 1978 100 0 n#6 ecars.ecars#0.OMSS 400 2192 800 2192 800 1728 960 1728 egenSub.egenSub#4.INPB
w 834 2042 100 0 n#5 ecars.ecars#0.VAL 400 2256 832 2256 832 1792 960 1792 egenSub.egenSub#4.INPA
[cell use]
use ecars 104 1976 100 0 ecars#0
xform 0 240 2144
p 192 1968 100 1024 -1 name:$(top)logDataazC
use ecars 104 1528 100 0 ecars#1
xform 0 240 1696
p 192 1520 100 1024 -1 name:$(top)logDataelC
use ecars 104 1064 100 0 ecars#2
xform 0 240 1232
p 192 1056 100 1024 -1 name:$(top)logDatacwC
use ecars 1624 1512 100 0 ecars#14
xform 0 1760 1680
p 1712 1504 100 1024 -1 name:$(top)logDataC
use egenSub 984 1032 100 0 egenSub#4
xform 0 1104 1456
p 1072 1024 100 1024 -1 name:$(top)$(id)combine3
p 1024 1902 100 0 1 SNAM:carCombine3
p 1056 1822 100 0 1 FTA:LONG
p 1056 1790 100 0 1 FTB:STRING
p 1056 1758 100 0 1 FTC:LONG
p 1056 1726 100 0 1 FTD:STRING
p 1056 1694 100 0 1 FTE:LONG
p 1056 1662 100 0 1 FTF:STRING
p 1056 1630 100 0 0 FTG:DOUBLE
p 1056 1598 100 0 0 FTH:DOUBLE
p 1056 1390 100 0 1 FTVA:LONG
p 1040 1358 100 0 1 FTVB:STRING
use bc200tr -208 -8 -100 0 frame
xform 0 1472 1296
[comments]
