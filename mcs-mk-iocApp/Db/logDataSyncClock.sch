[schematic2]
uniq 15
[tools]
[detail]
w 272 2283 100 0 n#1 hwin.hwin#1.in 208 2272 384 2272 eais.eais#0.INP
w 832 1899 100 0 n#2 eais.eais#0.FLNK 640 2256 768 2256 768 1888 944 1888 ecalcs.ecalcs#3.SLNK
w 2080 1323 100 0 n#3 junction 2016 1312 2192 1312 estringouts.estringouts#28.DOL
w 1968 1349 100 0 n#3 hwin.hwin#45.in 1920 1344 2016 1344 2016 1072 2192 1072 estringouts.estringouts#24.DOL
w 1904 1051 100 0 n#4 eais.eais#15.FLNK 1664 1040 2192 1040 estringouts.estringouts#24.SLNK
w 1904 1291 100 0 n#5 eais.eais#14.FLNK 1664 1280 2192 1280 estringouts.estringouts#28.SLNK
w 2504 1266 100 0 n#6 estringouts.estringouts#28.OUT 2448 1264 2608 1264 hwout.hwout#29.outp
w 2504 1026 100 0 n#7 estringouts.estringouts#24.OUT 2448 1024 2608 1024 hwout.hwout#26.outp
w 760 1122 100 0 n#8 junction 672 1152 672 1120 896 1120 eseqs.eseqs#8.DOL2
w 674 1712 100 0 n#8 eais.eais#0.VAL 640 2224 672 2224 672 1152 896 1152 eseqs.eseqs#8.DOL1
w 1416 1474 100 0 n#9 ecalcs.ecalcs#6.FLNK 1904 1920 2080 1920 2080 1472 800 1472 800 832 896 832 eseqs.eseqs#8.SLNK
w 1352 1538 100 0 n#10 ecalcs.ecalcs#6.VAL 1904 1888 2016 1888 2016 1536 736 1536 736 1184 896 1184 eseqs.eseqs#8.SELL
w 1240 1131 100 0 n#11 eseqs.eseqs#8.LNK2 1216 1120 1312 1120 1312 1024 1408 1024 eais.eais#15.SLNK
w 1314 1232 100 0 n#12 eseqs.eseqs#8.LNK1 1216 1152 1312 1152 1312 1264 1408 1264 eais.eais#14.SLNK
w 1458 1922 100 0 n#13 ecalcs.ecalcs#3.FLNK 1232 2112 1456 2112 1456 1696 1616 1696 ecalcs.ecalcs#6.SLNK
w 1438 2082 100 0 n#14 junction 1296 2080 1616 2080 ecalcs.ecalcs#6.INPA
w 1054 2370 100 0 n#14 ecalcs.ecalcs#3.VAL 1232 2080 1296 2080 1296 2368 848 2368 848 2272 944 2272 ecalcs.ecalcs#3.INPA
s 2224 1440 200 0 RESET TIME TRIGGER BY SETTING M1=1
[cell use]
use bc200tr -128 -24 -100 0 frame
xform 0 1552 1280
use eais 1432 952 100 0 eais#15
xform 0 1536 1024
p 1152 862 100 0 0 PREC:14
p 1520 944 100 1024 -1 name:$(top)$(command)elTime
use eais 1432 1192 100 0 eais#14
xform 0 1536 1264
p 1152 1102 100 0 0 PREC:14
p 1520 1184 100 1024 -1 name:$(top)$(command)azTime
use eais 408 2168 100 0 eais#0
xform 0 512 2240
p 173 2313 100 0 0 DESC:TAI time
p 432 2318 100 0 1 DTYP:Bancomm 635
p 128 1982 100 0 0 EGU:seconds
p 432 2382 100 0 1 PREC:6
p 432 2350 100 0 1 SCAN:.1 second
p 496 2160 100 1024 -1 name:$(top)bancommExtEvent
use hwin 40 2232 100 0 hwin#1
xform 0 112 2272
p 19 2264 100 0 -1 val(in):#C0 S3
use hwin 1752 1304 100 0 hwin#45
xform 0 1824 1344
p 1728 1374 100 0 -1 val(in):$(top)PmacCmd_M1
use estringouts 2216 1208 100 0 estringouts#28
xform 0 2320 1280
p 2240 1358 100 0 1 DTYP:PMAC-VME ASCII
p 2128 1086 100 0 0 OMSL:closed_loop
p 2128 1246 100 0 0 VAL:
p 2304 1200 100 1024 -1 name:$(top)$(command)elReset
use estringouts 2216 968 100 0 estringouts#24
xform 0 2320 1040
p 2240 1118 100 0 1 DTYP:PMAC-VME ASCII
p 2128 846 100 0 0 OMSL:closed_loop
p 2128 1006 100 0 0 VAL:
p 2304 960 100 1024 -1 name:$(top)$(command)azReset
use hwout 2632 1224 100 0 hwout#29
xform 0 2704 1264
p 2672 1310 100 0 -1 val(outp):#C$(ELCARD) S3
use hwout 2632 984 100 0 hwout#26
xform 0 2704 1024
p 2672 1070 100 0 -1 val(outp):#C$(AZCARD) S3
use eseqs 920 744 100 0 eseqs#8
xform 0 1056 992
p 512 156 100 0 0 PREC:14
p 1008 1198 100 0 1 SELM:Mask
p 1008 736 100 1024 -1 name:$(top)bancommSeq
p 1232 1152 75 1024 -1 pproc(LNK1):PP
p 1232 1120 75 1024 -1 pproc(LNK2):PP
p 1232 1088 75 1024 -1 pproc(LNK3):PP
use ecalcs 1640 1608 100 0 ecalcs#6
xform 0 1760 1872
p 1744 2062 100 0 1 CALC:2**(A-1)
p 1728 1600 100 1024 -1 name:$(top)bancommMask
use ecalcs 968 1800 100 0 ecalcs#3
xform 0 1088 2064
p 1088 2254 100 0 1 CALC:1+A%2
p 1056 1792 100 1024 -1 name:$(top)bancommEventCounter
[comments]
