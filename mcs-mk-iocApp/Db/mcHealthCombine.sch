[schematic2]
uniq 156
[tools]
[detail]
w 2594 1675 100 0 n#154 egenSub.healthCombine.OUTC 2400 1664 2848 1664 outhier.c#153.p
w 1442 523 100 0 n#152 mcMiscHealth.mcMiscHealth#139.FLNK 1120 512 1824 512 1824 1120 2112 1120 egenSub.healthCombine.SLNK
w 1426 651 100 0 n#151 mcMiscHealth.mcMiscHealth#139.MESS 1120 640 1792 640 1792 1344 2112 1344 egenSub.healthCombine.INPH
w 1410 1227 100 0 n#150 mcTimeHealth.mcTimeHealth#138.MESS 1120 1216 1760 1216 1760 1408 2112 1408 egenSub.healthCombine.INPG
w 1282 1899 100 0 n#149 mcMotorHealth.mcMotorHealth#155.CWMESS 992 1888 1632 1888 1632 1472 2112 1472 egenSub.healthCombine.INPF
w 1298 1835 100 0 n#148 mcMotorHealth.mcMotorHealth#155.CMESS 992 1824 1664 1824 1664 1536 2112 1536 egenSub.healthCombine.INPE
w 1394 747 100 0 n#147 mcMiscHealth.mcMiscHealth#139.VAL 1120 736 1728 736 1728 1600 2112 1600 egenSub.healthCombine.INPD
w 1378 1323 100 0 n#146 mcTimeHealth.mcTimeHealth#138.VAL 1120 1312 1696 1312 1696 1664 2112 1664 egenSub.healthCombine.INPC
w 1314 2027 100 0 n#145 mcMotorHealth.mcMotorHealth#155.CWVAL 992 2016 1696 2016 1696 1728 2112 1728 egenSub.healthCombine.INPB
w 1330 1963 100 0 n#144 mcMotorHealth.mcMotorHealth#155.CVAL 992 1952 1728 1952 1728 1792 2112 1792 egenSub.healthCombine.INPA
w 730 939 100 0 n#142 mcTimeHealth.mcTimeHealth#138.FLNK 1120 1088 1152 1088 1152 928 368 928 368 512 416 512 mcMiscHealth.mcMiscHealth#139.SLNK
w 730 1499 100 0 n#141 mcMotorHealth.mcMotorHealth#155.FLNK 992 1696 1152 1696 1152 1488 368 1488 368 1088 416 1088 mcTimeHealth.mcTimeHealth#138.SLNK
w 402 1707 100 0 n#137 eaos.scan.FLNK 384 1696 480 1696 mcMotorHealth.mcMotorHealth#155.SLNK
w 2594 1803 100 0 n#129 egenSub.healthCombine.OUTA 2400 1792 2848 1792 outhier.c#128.p
s 1008 2384 200 0 in the MCS into a single overall health
s 848 2448 200 0 This schematic combines all the individual health records
s 2352 2576 100 0 $Id: mcHealthCombine.sch,v 1.2 2001/08/20 16:54:52 gemvx Exp $
s 2624 384 100 0 Combine MCS health records
s 2368 384 100 0 Gemini
s 2368 352 100 0 Observatory
[cell use]
use mcMiscHealth 416 455 100 0 mcMiscHealth#139
xform 0 768 672
use mcMotorHealth 480 1639 100 0 mcMotorHealth#155
xform 0 736 1856
use outhier 2816 1751 100 0 c#128
xform 0 2832 1792
use outhier 2816 1623 100 0 c#153
xform 0 2832 1664
use mcTimeHealth 464 1031 100 0 mcTimeHealth#138
xform 0 768 1248
use eaos 128 1575 100 0 scan
xform 0 256 1664
p 48 1760 100 0 -1 DESC:Trigger for health calculation
p 96 1390 100 0 0 EGU:none
p 176 1520 100 0 1 SCAN:1 second
use egenSub 2112 1031 100 0 healthCombine
xform 0 2256 1456
p 2144 1904 100 0 -1 DESC:Combine health values
p 1889 805 100 0 0 FTA:STRING
p 1889 805 100 0 0 FTB:STRING
p 1889 773 100 0 0 FTC:STRING
p 1889 741 100 0 0 FTD:STRING
p 1889 709 100 0 0 FTE:STRING
p 1889 645 100 0 0 FTF:STRING
p 1889 645 100 0 0 FTG:STRING
p 1889 613 100 0 0 FTH:STRING
p 1889 805 100 0 0 FTVA:STRING
p 1889 805 100 0 0 FTVB:STRING
p 1889 773 100 0 0 FTVC:LONG
p 2336 960 100 0 1 SCAN:Passive
p 2336 1008 100 0 1 SNAM:mcHealthCombine
p 1616 1744 100 0 0 def(INPB):0.0
p 2560 1808 100 0 -1 def(OUTA):$(mc)health.IMSS
p 2544 1680 100 0 -1 def(OUTC):$(mc)healthL
p 2400 1802 75 0 -1 pproc(OUTA):NPP
p 2400 1674 75 0 -1 pproc(OUTC):PP
use bc200tr -224 104 -100 0 frame
xform 0 1456 1408
[comments]
