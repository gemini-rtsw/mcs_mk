[schematic2]
uniq 14
[tools]
[detail]
w 1672 1931 100 0 n#13 ebis.ebis#11.FLNK 1536 2336 1632 2336 1632 1920 1760 1920 ecalcs.ecalcs#10.SLNK
w 1624 2315 100 0 n#12 ebis.ebis#11.VAL 1536 2304 1760 2304 ecalcs.ecalcs#10.INPA
[cell use]
use ebis 1280 2247 100 0 ebis#11
xform 0 1408 2320
p 1344 2400 100 0 1 ONAM:ON
p 1344 2432 100 0 1 ZNAM:OFF
p 1392 2240 100 1024 -1 name:$(top)GISbypass
use ecalcs 1760 1831 100 0 ecalcs#10
xform 0 1904 2096
p 1808 2368 100 0 1 CALC:A+1
p 1872 1824 100 1024 -1 name:$(top)GISbypassCalc
use eais 96 2215 100 0 eais#8
xform 0 224 2288
p 208 2208 100 1024 -1 name:$(top)GIStimeout
use gisAxis 248 1464 100 0 gisAxis#0
xform 0 592 1704
p 1008 1884 200 0 1 seta:dev az
p 1008 1820 200 0 1 setb:DC_SIGNAL 24
p 1008 1758 200 0 1 setc:DE_SIGNAL 24
p 1008 1692 200 0 1 setd:card 0
p 1008 1628 200 0 1 sete:GISIN_SIGNAL 19
p 1008 1564 200 0 1 setf:GISOUT_SIGNAL 28
p 1008 1504 200 0 1 setg:id 1
p 1008 1440 200 0 1 seth:command
p 1008 1376 200 0 1 seti:timeout 60
use gisAxis 248 792 100 0 gisAxis#7
xform 0 592 1032
p 1008 1212 200 0 1 seta:dev el
p 1008 1148 200 0 1 setb:DC_SIGNAL 26
p 1008 1086 200 0 1 setc:DE_SIGNAL 26
p 1008 1020 200 0 1 setd:card 1
p 1008 956 200 0 1 sete:GISIN_SIGNAL 21
p 1008 892 200 0 1 setf:GISOUT_SIGNAL 30
p 1008 832 200 0 1 setg:id 2
p 1008 768 200 0 1 seth:command
p 1008 704 200 0 1 seti:timeout 60
use bc200tr -192 8 -100 0 frame
xform 0 1488 1312
[comments]
