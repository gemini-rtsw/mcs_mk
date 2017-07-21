[schematic2]
uniq 113
[tools]
[detail]
w 1074 1611 100 0 n#112 esubs.esubs#92.FLNK 896 1600 1312 1600 1312 1488 1584 1488 efanouts.efanouts#110.SLNK
w 1234 1570 100 0 n#111 esubs.esubs#92.VAL 896 1568 1632 1568 efanouts.efanouts#110.SELL
w 2018 1390 100 0 n#109 efanouts.efanouts#110.LNK4 1824 1472 2016 1472 2016 1248 2176 1248 outhier.NONE.p
w 1906 1506 100 0 n#108 efanouts.efanouts#110.LNK3 1824 1504 2048 1504 2048 1328 2176 1328 outhier.FULL.p
w 1922 1538 100 0 n#107 efanouts.efanouts#110.LNK2 1824 1536 2080 1536 2080 1408 2176 1408 outhier.FAST.p
w 1938 1570 100 0 n#106 efanouts.efanouts#110.LNK1 1824 1568 2112 1568 2112 1488 2176 1488 outhier.VSM.p
w 530 1730 100 0 n#104 hwin.hwin#103.in 448 1696 512 1696 512 1728 608 1728 esubs.esubs#92.INPB
w 498 1762 100 0 n#102 hwin.hwin#101.in 448 1760 608 1760 esubs.esubs#92.INPA
w 464 1378 100 0 n#94 inhier.SLNK.P 368 1376 608 1376 esubs.esubs#92.SLNK
s 2480 144 100 0 AWE
s 2784 176 100 0 MCS Level 3
s 2720 96 200 0 Check simulate level
[cell use]
use efanouts 1608 1352 100 0 efanouts#110
xform 0 1704 1504
p 1664 1646 100 0 1 EVNT:0
p 1664 1678 100 0 1 SCAN:Passive
p 1664 1710 100 0 1 SELM:Mask
p 1696 1344 100 1024 -1 name:$(top)$(dev)Decode2Fan
p 1856 1568 75 1280 -1 pproc(LNK1):PP
p 1856 1536 75 1280 -1 pproc(LNK2):PP
p 1856 1504 75 1280 -1 pproc(LNK3):PP
p 1856 1472 75 1280 -1 pproc(LNK4):PP
use hwin 280 1656 100 0 hwin#103
xform 0 352 1696
p 48 1694 100 0 -1 val(in):$(top)debugLevelL
use hwin 280 1720 100 0 hwin#101
xform 0 352 1760
p 64 1758 100 0 -1 val(in):$(top)simLevelL
use inhier 376 1336 100 0 SLNK
xform 0 368 1376
use esubs 632 1288 100 0 esubs#92
xform 0 752 1552
p 640 1246 100 0 1 INAM:nullSub
p 640 1214 100 0 1 SNAM:setMask
p 720 1280 100 1024 -1 name:$(top)$(dev)Decode2Sub
use outhier 2168 1448 100 0 VSM
xform 0 2160 1488
use outhier 2168 1368 100 0 FAST
xform 0 2160 1408
use outhier 2168 1288 100 0 FULL
xform 0 2160 1328
use outhier 2168 1208 100 0 NONE
xform 0 2160 1248
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
