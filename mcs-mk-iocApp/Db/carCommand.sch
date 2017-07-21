[schematic2]
uniq 29
[tools]
[detail]
w 920 930 100 0 n#24 ecars.ecars#1.FLNK 672 928 1216 928 egenSub.egenSub#4.SLNK
w 770 1176 100 0 n#24 ecars.ecars#0.FLNK 672 1376 768 1376 768 928 junction
w 824 1090 100 0 n#28 ecars.ecars#1.OMSS 672 1088 1024 1088 1024 1408 1216 1408 egenSub.egenSub#4.INPD
w 962 1336 100 0 n#27 ecars.ecars#1.VAL 672 1152 960 1152 960 1472 1216 1472 egenSub.egenSub#4.INPC
w 920 1538 100 0 n#26 ecars.ecars#0.OMSS 672 1536 1216 1536 egenSub.egenSub#4.INPB
w 920 1602 100 0 n#25 ecars.ecars#0.VAL 672 1600 1216 1600 egenSub.egenSub#4.INPA
w 1762 1176 100 0 n#17 egenSub.egenSub#4.FLNK 1504 896 1760 896 1760 1408 1856 1408 ecars.ecars#14.SLNK
w 1656 1538 100 0 n#16 egenSub.egenSub#4.OUTB 1504 1536 1856 1536 ecars.ecars#14.IMSS
w 1656 1602 100 0 n#15 egenSub.egenSub#4.OUTA 1504 1600 1856 1600 ecars.ecars#14.IVAL
[cell use]
use ecars 376 1320 100 0 ecars#0
xform 0 512 1488
p 464 1312 100 1024 -1 name:$(top)az$(command)C
use ecars 376 872 100 0 ecars#1
xform 0 512 1040
p 464 864 100 1024 -1 name:$(top)el$(command)C
use ecars 1880 1320 100 0 ecars#14
xform 0 2016 1488
p 1968 1312 100 1024 -1 name:$(top)$(command)C
use egenSub 1240 840 100 0 egenSub#4
xform 0 1360 1264
p 1328 832 100 1024 -1 name:$(top)$(command)combine2
p 1280 1710 100 0 1 SNAM:carCombine2
p 1312 1630 100 0 1 FTA:LONG
p 1312 1598 100 0 1 FTB:STRING
p 1312 1566 100 0 1 FTC:LONG
p 1312 1534 100 0 1 FTD:STRING
p 1312 1502 100 0 0 FTE:DOUBLE
p 1312 1470 100 0 0 FTF:DOUBLE
p 1312 1438 100 0 0 FTG:DOUBLE
p 1312 1406 100 0 0 FTH:DOUBLE
p 1312 1198 100 0 1 FTVA:LONG
p 1296 1166 100 0 1 FTVB:STRING
use bc200tr -208 -8 -100 0 frame
xform 0 1472 1296
[comments]
