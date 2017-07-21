[schematic2]
uniq 110
[tools]
[detail]
w 1042 1067 100 0 n#109 estringouts.estringouts#104.FLNK 1184 1216 1312 1216 1312 1056 832 1056 832 880 928 880 estringouts.estringouts#108.SLNK
w 1296 1195 100 0 n#89 estringouts.estringouts#104.OUT 1184 1184 1456 1184 1456 1456 junction
w 1296 1787 100 0 n#89 estringouts.estringouts#9.OUT 1184 1776 1456 1776 1456 1968 junction
w 1296 2091 100 0 n#89 estringouts.estringouts#4.OUT 1184 2080 1456 2080 1456 1968 1520 1968 hwout.hwout#6.outp
w 1296 1467 100 0 n#89 estringouts.estringouts#98.OUT 1184 1456 1456 1456 1456 1776 junction
w 1296 875 100 0 n#89 estringouts.estringouts#108.OUT 1184 864 1456 864 1456 1184 junction
w 766 916 100 0 n#106 hwin.hwin#107.in 640 912 928 912 estringouts.estringouts#108.DOL
w 1042 1371 100 0 n#105 estringouts.estringouts#98.FLNK 1184 1488 1312 1488 1312 1360 832 1360 832 1200 928 1200 estringouts.estringouts#104.SLNK
w 766 1236 100 0 n#102 hwin.hwin#103.in 640 1232 928 1232 estringouts.estringouts#104.DOL
w 1410 907 100 0 FLNK estringouts.estringouts#108.FLNK 1184 896 1696 896 outhier.FLNK.p
w 1042 1675 100 0 n#100 estringouts.estringouts#9.FLNK 1184 1808 1312 1808 1312 1664 832 1664 832 1472 928 1472 estringouts.estringouts#98.SLNK
w 766 1508 100 0 n#99 hwin.hwin#97.in 640 1504 928 1504 estringouts.estringouts#98.DOL
w 760 2107 100 0 c#90 inhier.SLNK.P 640 2096 928 2096 estringouts.estringouts#4.SLNK
w 1048 1970 100 0 n#11 estringouts.estringouts#4.FLNK 1184 2112 1312 2112 1312 1968 832 1968 832 1792 928 1792 estringouts.estringouts#9.SLNK
w 766 1828 100 0 n#8 hwin.hwin#18.in 640 1824 928 1824 estringouts.estringouts#9.DOL
w 766 2132 100 0 n#5 hwin.hwin#17.in 640 2128 928 2128 estringouts.estringouts#4.DOL
[cell use]
use estringouts 952 1128 100 0 estringouts#104
xform 0 1056 1200
p 960 1310 100 0 1 DTYP:PMAC-VME ASCII
p 960 1278 100 0 1 OMSL:closed_loop
p 864 1166 100 0 0 VAL:
p 1040 1120 100 1024 -1 name:$(top)$(axis)PMAC_I206S
use estringouts 952 1720 100 0 estringouts#9
xform 0 1056 1792
p 960 1902 100 0 1 DTYP:PMAC-VME ASCII
p 960 1870 100 0 1 OMSL:closed_loop
p 864 1758 100 0 0 VAL:
p 1040 1712 100 1024 -1 name:$(top)$(axis)PMAC_P102S
use estringouts 952 2024 100 0 estringouts#4
xform 0 1056 2096
p 960 2206 100 0 1 DTYP:PMAC-VME ASCII
p 960 2174 100 0 1 OMSL:closed_loop
p 864 2062 100 0 0 VAL:
p 1040 2016 100 1024 -1 name:$(top)$(axis)PMAC_P101S
use estringouts 952 1400 100 0 estringouts#98
xform 0 1056 1472
p 960 1582 100 0 1 DTYP:PMAC-VME ASCII
p 960 1550 100 0 1 OMSL:closed_loop
p 864 1438 100 0 0 VAL:
p 1040 1392 100 1024 -1 name:$(top)$(axis)PMAC_MPscaleS
use estringouts 952 808 100 0 estringouts#108
xform 0 1056 880
p 960 990 100 0 1 DTYP:PMAC-VME ASCII
p 960 958 100 0 1 OMSL:closed_loop
p 864 846 100 0 0 VAL:
p 1040 800 100 1024 -1 name:$(top)$(axis)PMAC_DefineM150S
use hwin 472 1192 100 0 hwin#103
xform 0 544 1232
p 400 1262 100 0 -1 val(in):$(top)PmacCmd_I206
use hwin 472 1784 100 0 hwin#18
xform 0 544 1824
p 400 1854 100 0 -1 val(in):$(top)PmacCmd_P102_OFF
use hwin 472 2088 100 0 hwin#17
xform 0 544 2128
p 400 2158 100 0 -1 val(in):$(top)PmacCmd_P101
use hwin 472 1464 100 0 hwin#97
xform 0 544 1504
p 400 1534 100 0 -1 val(in):$(top)PmacCmd_MPscale
use hwin 472 872 100 0 hwin#107
xform 0 544 912
p 400 942 100 0 -1 val(in):$(top)PmacCmd_DefineM150
use outhier 1664 855 100 0 FLNK
xform 0 1680 896
use inhier 624 2055 100 0 SLNK
xform 0 640 2096
use hwout 1544 1928 100 0 hwout#6
xform 0 1616 1968
p 1584 1998 100 0 -1 val(outp):#C$(CARD) S1
use bc200tr -64 -136 -100 0 frame
xform 0 1616 1168
[comments]
