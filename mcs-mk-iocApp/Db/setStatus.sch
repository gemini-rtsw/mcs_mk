[schematic2]
uniq 198
[tools]
[detail]
w 1034 1259 100 0 n#197 hwin.hwin#189.in 928 1248 1200 1248 egenSub.egenSub#176.INPH
w 1034 1451 100 0 n#195 hwin.hwin#187.in 928 1440 1200 1440 egenSub.egenSub#176.INPE
w 1034 1515 100 0 n#194 hwin.hwin#182.in 928 1504 1200 1504 egenSub.egenSub#176.INPD
w 1034 1579 100 0 n#193 hwin.hwin#180.in 928 1568 1200 1568 egenSub.egenSub#176.INPC
w 1034 1643 100 0 n#192 hwin.hwin#112.in 928 1632 1200 1632 egenSub.egenSub#176.INPB
w 1034 1707 100 0 n#191 hwin.hwin#107.in 928 1696 1200 1696 egenSub.egenSub#176.INPA
w 1562 1707 100 0 n#177 egenSub.egenSub#176.OUTA 1488 1696 1696 1696 hwout.hwout#83.outp
[cell use]
use hwin 736 1207 100 0 hwin#189
xform 0 832 1248
p 640 1248 100 0 -1 val(in):$(card)
use hwin 736 1463 100 0 hwin#182
xform 0 832 1504
p 416 1504 100 0 -1 val(in):$(top)$(dev)DriveCondition
use hwin 760 1656 100 0 hwin#107
xform 0 832 1696
p 400 1696 100 0 -1 val(in):$(top)$(dev)motstat1:2:DVZ
use hwin 760 1592 100 0 hwin#112
xform 0 832 1632
p 400 1632 100 0 -1 val(in):$(top)$(dev)motstat1:2:OLM
use hwin 736 1527 100 0 hwin#180
xform 0 832 1568
p 496 1568 100 0 -1 val(in):$(top)FollowL
use hwin 736 1399 100 0 hwin#187
xform 0 832 1440
p 416 1440 100 0 -1 val(in):$(top)$(dev)DriveEnable
use egenSub 1200 935 100 0 egenSub#176
xform 0 1344 1360
p 1280 1680 100 0 1 FTA:LONG
p 1280 1648 100 0 1 FTB:LONG
p 1280 1616 100 0 1 FTC:LONG
p 1280 1584 100 0 1 FTD:LONG
p 1280 1552 100 0 1 FTE:LONG
p 1280 1520 100 0 1 FTF:LONG
p 1280 1488 100 0 1 FTG:LONG
p 1280 1456 100 0 1 FTH:DOUBLE
p 1296 1280 100 0 1 FTVA:LONG
p 1248 1824 100 0 1 SCAN:.1 second
p 1248 1792 100 0 1 SNAM:setAxisState
p 1312 928 100 1024 -1 name:$(top)$(dev)setAxisState
use hwout 1720 1656 100 0 hwout#83
xform 0 1792 1696
p 1904 1694 100 0 -1 val(outp):$(top)$(dev)StateL .PP
use bc200tr -208 56 -100 0 frame
xform 0 1472 1360
[comments]
