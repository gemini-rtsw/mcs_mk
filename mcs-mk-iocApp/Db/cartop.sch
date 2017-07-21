[schematic2]
uniq 23
[tools]
[detail]
w 866 1928 100 0 n#18 carWeights.carWeights#3.OMSS 608 1696 864 1696 864 2112 1008 2112 egenSub.egenSub#4.INPD
w 802 1992 100 0 n#17 carWeights.carWeights#3.VAL 608 1760 800 1760 800 2176 1008 2176 egenSub.egenSub#4.INPC
w 706 1928 100 0 n#16 carAxis.carAxis#0.FLNK 608 2176 704 2176 704 1632 junction
w 784 1634 100 0 n#16 carWeights.carWeights#3.FLNK 608 1632 1008 1632 egenSub.egenSub#4.SLNK
w 1538 1880 100 0 n#15 egenSub.egenSub#4.FLNK 1296 1600 1536 1600 1536 2112 1664 2112 ecars.ecars#12.SLNK
w 1456 2242 100 0 n#14 egenSub.egenSub#4.OUTB 1296 2240 1664 2240 ecars.ecars#12.IMSS
w 1456 2306 100 0 n#13 egenSub.egenSub#4.OUTA 1296 2304 1664 2304 ecars.ecars#12.IVAL
w 790 2242 100 0 n#6 carAxis.carAxis#0.OMSS 608 2240 1008 2240 egenSub.egenSub#4.INPB
w 790 2306 100 0 n#5 carAxis.carAxis#0.VAL 608 2304 1008 2304 egenSub.egenSub#4.INPA
[cell use]
use carCommand 856 424 100 0 carCommand#22
xform 0 1152 528
p 832 384 100 0 -1 seta:command stop
use carCommand 856 744 100 0 carCommand#21
xform 0 1152 848
p 832 704 100 0 -1 seta:command move
use carPMACLogging 856 1064 100 0 carPMACLogging#19
xform 0 1152 1168
p 848 1038 100 0 -1 seta:id carPMAC
use ecars 1688 1576 100 0 ecars#1
xform 0 1824 1744
p 1776 1568 100 1024 -1 name:$(top)softC
use ecars 1688 2024 100 0 ecars#12
xform 0 1824 2192
p 1776 2016 100 1024 -1 name:$(top)activeC
use egenSub 1032 1544 100 0 egenSub#4
xform 0 1152 1968
p 1120 1536 100 1024 -1 name:$(top)$(id)combine2
p 1072 2398 100 0 1 SNAM:carCombine2
p 1104 2318 100 0 1 FTA:LONG
p 1088 2286 100 0 1 FTB:STRING
p 1104 2254 100 0 1 FTC:LONG
p 1104 2222 100 0 1 FTD:STRING
p 1104 2142 100 0 1 FTVA:LONG
p 1088 2110 100 0 1 FTVB:STRING
use carWeights 184 1512 100 0 carWeights#3
xform 0 368 1664
p 128 1472 100 0 -1 seta:id carWeights:
use carAxis 184 2056 100 0 carAxis#0
xform 0 368 2208
p 160 2016 100 0 -1 seta:id carAxes:
use bc200tr -224 24 -100 0 frame
xform 0 1456 1328
[comments]
