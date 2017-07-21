[schematic2]
uniq 229
[tools]
[detail]
w 1490 907 100 0 n#225 GISassert.GISassert#171.FAIL 1792 1008 1856 1008 1856 896 1184 896 1184 736 1344 736 carError.carError#173.SLNK
w 2066 1083 100 0 n#224 GISassert.GISassert#171.OK 1792 1072 2400 1072 egenSub.egenSub#175.SLNK
w 210 2219 100 0 n#222 hwin.hwin#221.in 192 2208 288 2208 ecalcs.ecalcs#209.INPA
w 1490 1163 100 0 n#218 trackingOff.trackingOff#189.FLNK 1792 1376 1856 1376 1856 1152 1184 1152 1184 1040 1344 1040 GISassert.GISassert#171.SLNK
w 1050 2107 100 0 n#217 efanouts.efanouts#210.LNK2 1040 2096 1120 2096 1120 1376 1184 1376 junction
w 1490 1547 100 0 n#217 setCommand.setCommand#194.FLNK 1792 1760 1856 1760 1856 1536 1184 1536 1184 1376 1344 1376 trackingOff.trackingOff#189.SLNK
w 1490 1931 100 0 n#216 carBusy.carBusy#184.FLNK 1792 2128 1856 2128 1856 1920 1184 1920 1184 1760 1344 1760 setCommand.setCommand#194.SLNK
w 1266 1707 100 0 CMD inhier.CMD.P 1248 1696 1344 1696 setCommand.setCommand#194.CMD
w 1162 2139 100 0 n#213 efanouts.efanouts#210.LNK1 1040 2128 1344 2128 carBusy.carBusy#184.SLNK
w 746 2139 100 0 n#212 ecalcs.ecalcs#209.VAL 576 2016 704 2016 704 2128 848 2128 efanouts.efanouts#210.SELL
w 658 2059 100 0 n#211 ecalcs.ecalcs#209.FLNK 576 2048 800 2048 efanouts.efanouts#210.SLNK
w 178 1835 100 0 SLNK inhier.SLNK.P 128 1824 288 1824 ecalcs.ecalcs#209.SLNK
w 2306 1563 100 0 n#193 hwin.hwin#192.in 2272 1552 2400 1552 egenSub.egenSub#175.INPD
w 2306 1627 100 0 n#183 hwin.hwin#182.in 2272 1616 2400 1616 egenSub.egenSub#175.INPC
w 2218 1691 100 0 c#180 inhier.VEL.P 2096 1680 2400 1680 egenSub.egenSub#175.INPB
w 2212 1755 100 0 DEMAND inhier.DEMAND.P 2096 1744 2400 1744 egenSub.egenSub#175.INPA
[cell use]
use hwin 2080 1575 100 0 hwin#182
xform 0 2176 1616
p 2083 1608 100 0 -1 val(in):$(card)
use hwin 2080 1511 100 0 hwin#192
xform 0 2176 1552
p 2048 1504 100 0 -1 val(in):$(top)debugLevelL
use hwin 0 2167 100 0 hwin#221
xform 0 96 2208
p -16 2256 100 0 -1 val(in):$(top)$(dev)CommandL
use efanouts 800 1911 100 0 efanouts#210
xform 0 920 2064
p 880 2224 100 0 1 SELM:Mask
p 912 1904 100 1024 -1 name:$(top)$(command)$(dev)FO
p 1072 2128 75 1280 -1 pproc(LNK1):PP
p 1072 2096 75 1280 -1 pproc(LNK2):PP
use ecalcs 288 1735 100 0 ecalcs#209
xform 0 432 2000
p 320 2272 100 0 1 CALC:(A=$(park))?2:1
p 400 1728 100 1024 -1 name:$(top)$(command)$(dev)Calc
use inhier 2000 1664 100 0 VEL
xform 0 2096 1680
use inhier 2000 1728 100 0 DEMAND
xform 0 2096 1744
use inhier 136 1784 100 0 SLNK
xform 0 128 1824
use inhier 1256 1656 100 0 CMD
xform 0 1248 1696
use setCommand 1344 1607 100 0 setCommand#194
xform 0 1568 1744
p 1364 1580 100 0 0 seta:id
use trackingOff 1344 1223 100 0 trackingOff#189
xform 0 1568 1360
use carBusy 1344 1975 100 0 carBusy#184
xform 0 1568 2112
use egenSub 2400 983 100 0 egenSub#175
xform 0 2544 1408
p 2496 1712 100 0 1 FTA:STRING
p 2496 1680 100 0 1 FTB:STRING
p 2496 1648 100 0 1 FTC:DOUBLE
p 2496 1616 100 0 1 FTD:DOUBLE
p 2480 1376 100 0 1 FTVA:LONG
p 2480 1824 100 0 1 SNAM:SendJog
p 2512 976 100 1024 -1 name:$(top)$(command)$(dev)SendJog
use carError 1376 583 100 0 carError#173
xform 0 1568 720
p 1440 672 100 0 1 seta:errno 1
p 1440 640 100 0 1 setb:id 1
use GISassert 1344 951 100 0 GISassert#171
xform 0 1568 1032
p 1488 992 100 0 1 seta:id 1
use bc200tr -160 -88 -100 0 frame
xform 0 1520 1216
[comments]
