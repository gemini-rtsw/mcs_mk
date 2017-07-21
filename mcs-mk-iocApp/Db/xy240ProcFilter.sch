[schematic2]
uniq 127
[tools]
[detail]
w 2174 1707 100 0 VAL junction 1376 1696 3008 1696 outhier.VAL.p
w 2850 1346 100 0 n#125 efanouts.efanouts#111.LNK1 2752 1344 3008 1344 outhier.FLNK.p
w 1810 1346 100 0 n#123 elongins.elongins#89.FLNK 1760 1344 1920 1344 junction
w 1922 1390 100 0 n#123 elongins.elongins#87.FLNK 1760 1568 1920 1568 1920 1152 2048 1152 ecalcs.ecalcs#107.SLNK
w 1906 1506 100 0 n#122 elongins.elongins#89.VAL 1760 1312 1824 1312 1824 1504 2048 1504 ecalcs.ecalcs#107.INPB
w 1874 1538 100 0 n#121 elongins.elongins#87.VAL 1760 1536 2048 1536 ecalcs.ecalcs#107.INPA
w 1410 1586 100 0 VAL junction 1376 1584 1504 1584 elongins.elongins#87.INP
w 1378 1558 100 0 VAL inhier.INP.P 1216 1696 1376 1696 1376 1360 1504 1360 elongins.elongins#89.INP
w 1322 1426 100 0 n#119 efanouts.efanouts#85.LNK2 1264 1424 1440 1424 1440 1328 1504 1328 elongins.elongins#89.SLNK
w 1322 1458 100 0 n#118 efanouts.efanouts#85.LNK1 1264 1456 1440 1456 1440 1552 1504 1552 elongins.elongins#87.SLNK
w 258 1154 100 0 n#116 inhier.SLNK.P 128 1152 448 1152 ecalcs.ecalcs#82.SLNK
w 2434 1350 100 0 n#114 ecalcs.ecalcs#107.FLNK 2336 1376 2432 1376 2432 1264 2512 1264 efanouts.efanouts#111.SLNK
w 2418 1346 100 0 n#113 ecalcs.ecalcs#107.VAL 2336 1344 2560 1344 efanouts.efanouts#111.SELL
w 928 1458 100 0 n#83 junction 832 1456 1072 1456 efanouts.efanouts#85.SELL
w 552 1666 100 0 n#83 ecalcs.ecalcs#82.VAL 736 1344 832 1344 832 1664 320 1664 320 1536 448 1536 ecalcs.ecalcs#82.INPA
w 856 1378 100 0 n#86 ecalcs.ecalcs#82.FLNK 736 1376 1024 1376 efanouts.efanouts#85.SLNK
[cell use]
use outhier 2976 1655 100 0 VAL
xform 0 2992 1696
use outhier 3000 1304 100 0 FLNK
xform 0 2992 1344
use inhier 1224 1656 100 0 INP
xform 0 1216 1696
use inhier 136 1112 100 0 SLNK
xform 0 128 1152
use efanouts 1048 1240 100 0 efanouts#85
xform 0 1144 1392
p 1120 1550 100 0 1 SELM:Mask
p 1136 1232 100 1024 -1 name:$(top)$(dev)xy240ProcFilter2-$(id)
p 1296 1456 75 1280 -1 pproc(LNK1):PP
p 1296 1424 75 1280 -1 pproc(LNK2):PP
use efanouts 2536 1128 100 0 efanouts#111
xform 0 2632 1280
p 2608 1470 100 0 0 DISV:1
p 2608 1438 100 0 1 SELM:Mask
p 2624 1120 100 1024 -1 name:$(top)$(dev)xy240ProcFilter6-$(id)
p 2784 1344 75 1280 -1 pproc(LNK1):PP
use ecalcs 472 1064 100 0 ecalcs#82
xform 0 592 1328
p 528 1598 100 0 1 CALC:A%2+1
p 560 1056 100 1024 -1 name:$(top)$(dev)xy240ProcFilter1-$(id)
use ecalcs 2072 1064 100 0 ecalcs#107
xform 0 2192 1328
p 2080 1598 100 0 1 CALC:(A-B)?1:0
p 2160 1056 100 1024 -1 name:$(top)$(dev)xy240ProcFilter5-$(id)
use elongins 1528 1256 100 0 elongins#89
xform 0 1632 1328
p 1616 1248 100 1024 -1 name:$(top)$(dev)xy240ProcFilter4-$(id)
use elongins 1528 1480 100 0 elongins#87
xform 0 1632 1552
p 1616 1472 100 1024 -1 name:$(top)$(dev)xy240ProcFilter3-$(id)
use bc200tr -144 -24 -100 0 frame
xform 0 1536 1280
[comments]
