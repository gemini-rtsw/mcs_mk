[schematic2]
uniq 2
[tools]
[detail]
w 2446 1787 100 0 n#1 ecalcs.ecalcs#5.VAL 2560 2144 2784 2144 2784 1776 2144 1776 2144 2336 2272 2336 ecalcs.ecalcs#5.INPA
[cell use]
use bc200tr -160 -24 -100 0 frame
xform 0 1520 1280
use mcHealthCombine 2016 1175 100 0 mcHealthCombine#17
xform 0 2384 1416
p 2176 1328 200 0 1 seta:mc $(mc)
p 2176 1264 200 0 1 setb:top $(mc)health:
use generalStat1 1088 1783 100 0 generalStat1#15
xform 0 1456 2024
use axisStatus2 216 568 100 0 axisStatus2#11
xform 0 560 808
p 304 734 200 0 1 seta:card 0
p 304 684 200 0 1 setb:dev az
use axisStatus2 1112 568 100 0 axisStatus2#14
xform 0 1456 808
p 1200 734 200 0 1 seta:card 1
p 1200 684 200 0 1 setb:dev el
use axisStatus1 216 1176 100 0 axisStatus1#9
xform 0 560 1416
p 272 1342 200 0 1 seta:card 0
p 272 1292 200 0 1 setb:dev az
use axisStatus1 1112 1176 100 0 axisStatus1#13
xform 0 1456 1416
p 1168 1342 200 0 1 seta:card 1
p 1168 1292 200 0 1 setb:dev el
use ecalcs 2296 1864 100 0 ecalcs#5
xform 0 2416 2128
p 2448 1934 100 0 1 CALC:(A%100)+1
p 2448 1966 100 0 1 SCAN:1 second
p 2384 1856 100 1024 -1 name:$(top)present
use generalStat 216 1784 100 0 generalStat#0
xform 0 560 2024
[comments]
