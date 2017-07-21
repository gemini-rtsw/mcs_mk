[schematic2]
uniq 116
[tools]
[detail]
w 1778 1778 100 0 n#115 eseqs.eseqs#104.LNK2 1696 1776 1920 1776 1920 1728 2016 1728 hwout.hwout#114.outp
w 1730 1746 100 0 n#113 eseqs.eseqs#104.LNK3 1696 1744 1824 1744 1824 1808 junction
w 1826 1810 100 0 n#113 eseqs.eseqs#104.LNK1 1696 1808 2016 1808 hwout.hwout#107.outp
w 1106 1762 100 0 n#112 ecad4.ecad4#99.VALA 752 1904 992 1904 992 1760 1280 1760 1280 1776 1376 1776 eseqs.eseqs#104.DOL2
w 1314 1746 100 0 n#111 hwin.hwin#109.in 1264 1728 1312 1728 1312 1744 1376 1744 eseqs.eseqs#104.DOL3
w 1290 1810 100 0 n#110 hwin.hwin#108.in 1264 1808 1376 1808 eseqs.eseqs#104.DOL1
w 1034 1490 100 0 n#105 ecad4.ecad4#99.STLK 752 1488 1376 1488 eseqs.eseqs#104.SLNK
w 898 1934 100 0 n#103 ecad4.ecad4#99.FLNK 752 1616 896 1616 896 2192 928 2192 engAck.engAck#59.SLNK
w 834 2206 100 0 n#102 ecad4.ecad4#99.VAL 752 2096 832 2096 832 2256 928 2256 engAck.engAck#59.INP
w 314 1810 100 0 n#101 hwin.hwin#94.in 256 1808 432 1808 ecad4.ecad4#99.INPB
s 2720 96 200 0 DEBUG COMMAND
s 2784 176 100 0 MCS Level 3
s 2480 144 100 0 Andy Foster
[cell use]
use hwout 2040 1688 100 0 hwout#114
xform 0 2112 1728
p 2032 1678 100 0 -1 val(outp):$(top)debugLevelL .PP
use hwout 2040 1768 100 0 hwout#107
xform 0 2112 1808
p 2032 1838 100 0 -1 val(outp):$(top)softC.IVAL .PP
use hwin 1096 1688 100 0 hwin#109
xform 0 1168 1728
p 1075 1720 100 0 -1 val(in):$(IDLE)
use hwin 1096 1768 100 0 hwin#108
xform 0 1168 1808
p 1075 1800 100 0 -1 val(in):$(BUSY)
use hwin 88 1768 100 0 hwin#94
xform 0 160 1808
p 64 1774 100 0 -1 val(in):$(top)debugLevelL
use eseqs 1400 1400 100 0 eseqs#104
xform 0 1536 1648
p 1488 1392 100 1024 -1 name:$(top)$(command)seq
p 1488 1598 100 0 1 DLY3:0.5
use ecad4 456 1400 100 0 ecad4#99
xform 0 592 1776
p 544 1392 100 1024 -1 name:$(top)$(command)
p 512 2238 100 0 1 SNAM:debugCAD
p 512 2206 100 0 1 FTVA:LONG
p 512 2174 100 0 0 FTVB:STRING
p 512 2142 100 0 0 FTVC:STRING
use engAck 952 2056 100 0 engAck#59
xform 0 1120 2192
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
