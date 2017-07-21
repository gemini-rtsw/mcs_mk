[schematic2]
uniq 315
[tools]
[detail]
w 2036 1691 100 2 n#314 hwin.hwin#307.in 2032 1696 2032 1696 egenSubD.egenSubD#294.INPL
w 2036 1723 100 2 n#313 hwin.hwin#306.in 2032 1728 2032 1728 egenSubD.egenSubD#294.INPK
w 2036 1787 100 2 n#312 hwin.hwin#305.in 2032 1792 2032 1792 egenSubD.egenSubD#294.INPI
w 2036 1819 100 2 n#311 hwin.hwin#304.in 2032 1824 2032 1824 egenSubD.egenSubD#294.INPH
w 2036 1851 100 2 n#310 hwin.hwin#303.in 2032 1856 2032 1856 egenSubD.egenSubD#294.INPG
w 2036 1883 100 2 n#309 hwin.hwin#302.in 2032 1888 2032 1888 egenSubD.egenSubD#294.INPF
w 2036 1915 100 2 n#308 hwin.hwin#301.in 2032 1920 2032 1920 egenSubD.egenSubD#294.INPE
w 2036 1755 100 2 n#297 egenSubD.egenSubD#294.INPJ 2032 1760 2032 1760 hwin.hwin#286.in
w 1594 1355 100 0 n#284 egenSub.egenSub#4.FLNK 864 1312 1216 1312 1216 1344 2032 1344 egenSubD.egenSubD#294.SLNK
w 2506 2059 100 0 n#283 egenSubD.egenSubD#294.VALA 2320 2048 2752 2048 tracking.tracking#236.DEMANDS1
w 2506 1995 100 0 n#282 egenSubD.egenSubD#294.VALB 2320 1984 2752 1984 tracking.tracking#236.DEMANDS2
w 2506 1931 100 0 n#281 egenSubD.egenSubD#294.VALC 2320 1920 2752 1920 tracking.tracking#236.DEMANDS3
w 2506 1867 100 0 n#280 egenSubD.egenSubD#294.VALD 2320 1856 2752 1856 tracking.tracking#236.SWITCH
w 1610 1963 100 0 n#279 egenSub.egenSub#4.VALD 864 1856 1248 1856 1248 1952 2032 1952 egenSubD.egenSubD#294.INPD
w 1594 1995 100 0 n#278 egenSub.egenSub#4.VALC 864 1920 1216 1920 1216 1984 2032 1984 egenSubD.egenSubD#294.INPC
w 1578 2027 100 0 n#277 egenSub.egenSub#4.VALB 864 1984 1184 1984 1184 2016 2032 2016 egenSubD.egenSubD#294.INPB
w 1418 2059 100 0 n#276 egenSub.egenSub#4.VALA 864 2048 2032 2048 egenSubD.egenSubD#294.INPA
w 418 1611 100 0 n#266 hwin.hwin#264.in 384 1600 512 1600 512 1760 576 1760 egenSub.egenSub#4.INPE
w 402 1707 100 0 n#265 hwin.hwin#263.in 384 1696 480 1696 480 1824 576 1824 egenSub.egenSub#4.INPD
w 482 1899 100 0 n#262 hwin.hwin#261.in 384 1792 448 1792 448 1888 576 1888 egenSub.egenSub#4.INPC
w 466 1963 100 0 n#260 hwin.hwin#259.in 384 1888 416 1888 416 1952 576 1952 egenSub.egenSub#4.INPB
w 466 2027 100 0 n#258 ebis.ebis#257.VAL 416 2016 576 2016 egenSub.egenSub#4.INPA
w 874 1707 100 0 n#245 egenSub.egenSub#4.OUTF 864 1696 944 1696 hwout.hwout#241.outp
w 874 1643 100 0 n#244 egenSub.egenSub#4.OUTG 864 1632 944 1632 hwout.hwout#243.outp
[cell use]
use hwin 1840 1719 100 0 hwin#286
xform 0 1936 1760
p 1584 1744 100 0 -1 val(in):$(top)elCurrentMaxVel
use hwin 192 1559 100 0 hwin#264
xform 0 288 1600
p 176 1552 100 0 -1 val(in):$(top)elUpperLimit
use hwin 192 1655 100 0 hwin#263
xform 0 288 1696
p 176 1648 100 0 -1 val(in):$(top)elLowerLimit
use hwin 192 1751 100 0 hwin#261
xform 0 288 1792
p 176 1744 100 0 -1 val(in):$(top)azUpperLimit
use hwin 192 1847 100 0 hwin#259
xform 0 288 1888
p 176 1840 100 0 -1 val(in):$(top)azLowerLimit
use hwin 1840 1879 100 0 hwin#301
xform 0 1936 1920
p 1616 1904 100 0 -1 val(in):$(top)FollowL
use hwin 1840 1847 100 0 hwin#302
xform 0 1936 1888
p 1616 1872 100 0 -1 val(in):$(top)TrajectoryL
use hwin 1840 1815 100 0 hwin#303
xform 0 1936 1856
p 1616 1840 100 0 -1 val(in):$(top)azCurrentPos
use hwin 1840 1783 100 0 hwin#304
xform 0 1936 1824
p 1616 1808 100 0 -1 val(in):$(top)elCurrentPos
use hwin 1840 1751 100 0 hwin#305
xform 0 1936 1792
p 1584 1776 100 0 -1 val(in):$(top)azCurrentMaxVel
use hwin 1840 1687 100 0 hwin#306
xform 0 1936 1728
p 1616 1712 100 0 -1 val(in):$(top)azMaxAccel
use hwin 1840 1655 100 0 hwin#307
xform 0 1936 1696
p 1616 1680 100 0 -1 val(in):$(top)elMaxAccel
use egenSubD 2032 1255 100 0 egenSubD#294
xform 0 2176 1680
p 1809 965 100 0 0 FTD:LONG
p 1809 933 100 0 0 FTE:LONG
p 1809 869 100 0 0 FTF:LONG
p 1809 965 100 0 0 FTVD:LONG
p 1744 1662 100 0 0 INAM:
p 1809 677 100 0 0 NOA:5
p 1809 645 100 0 0 NOB:5
p 1809 613 100 0 0 NOC:5
p 1809 389 100 0 0 NOU:1
p 1809 677 100 0 0 NOVA:5
p 1809 645 100 0 0 NOVB:5
p 1809 613 100 0 0 NOVC:5
p 2096 2096 100 0 1 SNAM:TrajecCalc
p 2144 1248 100 1024 1 name:$(top)trajecCalc
use egenSub 600 1256 100 0 egenSub#4
xform 0 720 1680
p 656 1664 100 0 1 FTA:LONG
p 656 1632 100 0 1 FTB:DOUBLE
p 656 1600 100 0 1 FTC:DOUBLE
p 656 1568 100 0 1 FTD:DOUBLE
p 656 1536 100 0 1 FTE:DOUBLE
p 656 1488 100 0 1 FTJ:DOUBLE
p 656 2016 100 0 1 FTVA:DOUBLE
p 656 1952 100 0 1 FTVB:DOUBLE
p 656 1888 100 0 1 FTVC:DOUBLE
p 656 1824 100 0 1 FTVD:LONG
p 656 1792 100 0 1 FTVE:LONG
p 656 2128 100 0 1 INAM:initFollowA
p 656 1456 100 0 1 NOJ:5
p 656 1984 100 0 1 NOVA:5
p 656 1920 100 0 1 NOVB:5
p 656 1856 100 0 1 NOVC:5
p 656 2096 100 0 1 SNAM:FollowA
p 688 1248 100 1024 -1 name:$(top)followA
use ebis 160 1959 100 0 ebis#257
xform 0 288 2032
p 224 2112 100 0 1 ONAM:ON
p 224 2144 100 0 1 ZNAM:OFF
p 272 1952 100 1024 -1 name:$(top)TCSLogging
use hwout 944 1591 100 0 hwout#243
xform 0 1040 1632
p 1152 1632 100 0 -1 val(outp):$(top)elDemandPos .PP
use hwout 944 1655 100 0 hwout#241
xform 0 1040 1696
p 1152 1696 100 0 -1 val(outp):$(top)azDemandPos .PP
use tracking 2752 1799 100 0 tracking#236
xform 0 2928 1952
use bc200tr -48 -24 -100 0 frame
xform 0 1632 1280
[comments]
