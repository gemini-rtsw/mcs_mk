[schematic2]
uniq 32
[tools]
[detail]
w 424 1643 100 0 n#31 hwin.hwin#29.in 416 1632 480 1632 egenSub.egenSub#18.INPB
w 424 1707 100 0 n#30 hwin.hwin#28.in 416 1696 480 1696 egenSub.egenSub#18.INPA
w 2224 1323 100 0 n#27 eseqs.eseqs#12.LNK1 2128 1312 2368 1312 hwout.hwout#26.outp
w 848 1579 100 0 n#25 egenSub.egenSub#18.OUTC 768 1568 976 1568 hwout.hwout#22.outp
w 848 1643 100 0 n#24 egenSub.egenSub#18.OUTB 768 1632 976 1632 hwout.hwout#21.outp
w 848 1707 100 0 n#23 egenSub.egenSub#18.OUTA 768 1696 976 1696 hwout.hwout#20.outp
w 1264 1003 100 0 n#19 egenSub.egenSub#18.FLNK 768 992 1808 992 eseqs.eseqs#12.SLNK
w 1688 1314 100 0 n#15 hwin.hwin#14.in 1616 1312 1808 1312 eseqs.eseqs#12.DOL1
[cell use]
use hwin 224 1591 100 0 hwin#29
xform 0 320 1632
p 32 1616 100 0 -1 val(in):$(top)elStateL
use hwin 224 1655 100 0 hwin#28
xform 0 320 1696
p 32 1680 100 0 -1 val(in):$(top)azStateL
use hwout 976 1527 100 0 hwout#22
xform 0 1072 1568
p 1184 1568 100 0 -1 val(outp):$(top)stop.C
use hwout 976 1591 100 0 hwout#21
xform 0 1072 1632
p 1184 1632 100 0 -1 val(outp):$(top)stop.B
use hwout 976 1655 100 0 hwout#20
xform 0 1072 1696
p 1184 1696 100 0 -1 val(outp):$(top)stop.A 
use hwout 2368 1271 100 0 hwout#26
xform 0 2464 1312
p 2608 1312 100 0 -1 val(outp):$(top)stop.DIR .PP
use egenSub 480 935 100 0 egenSub#18
xform 0 624 1360
p 576 1504 100 0 1 FTA:LONG
p 576 1472 100 0 1 FTB:LONG
p 560 1696 100 0 1 FTVA:STRING
p 560 1648 100 0 1 FTVB:STRING
p 560 1600 100 0 1 FTVC:STRING
p 528 1792 100 0 1 SNAM:handPaddleStop
p 592 928 100 1024 -1 name:$(top)handPaddleStop
use hwin 1448 1272 100 0 hwin#14
xform 0 1520 1312
p 1427 1304 100 0 -1 val(in):$(START)
use eseqs 1832 904 100 0 eseqs#12
xform 0 1968 1152
p 1920 1374 100 0 1 DLY1:0.25
p 1920 896 100 1024 -1 name:$(top)handPaddleDIR
p 2144 1312 75 1024 -1 pproc(LNK1):NPP
use bc200tr -128 -88 -100 0 frame
xform 0 1552 1216
[comments]
