[schematic2]
uniq 165
[tools]
[detail]
w 2130 1611 100 0 n#164 hwin.hwin#163.in 2112 1600 2208 1600 2208 1584 2304 1584 eaos.eaos#161.DOL
w 2610 1531 100 0 n#162 eaos.eaos#161.OUT 2560 1520 2720 1520 hwout.hwout#157.outp
w 1890 1563 100 0 n#154 simmDecode.simmDecode#66.NONE 1536 1552 2304 1552 eaos.eaos#161.SLNK
w 842 1819 100 0 n#159 ecad2.ecad2#6.OUTA 752 1808 992 1808 hwout.hwout#155.outp
w 1538 1595 100 0 n#154 simmDecode.simmDecode#66.FULL 1536 1584 1600 1584 1600 1552 junction
w 1538 1627 100 0 n#154 simmDecode.simmDecode#66.FAST 1536 1616 1600 1616 1600 1584 junction
w 1538 1659 100 0 n#154 simmDecode.simmDecode#66.VSM 1536 1648 1600 1648 1600 1616 junction
w 912 1554 100 0 n#96 ecad2.ecad2#6.STLK 752 1552 1120 1552 simmDecode.simmDecode#66.SLNK
w 312 1810 100 0 n#93 hwin.hwin#92.in 240 1808 432 1808 ecad2.ecad2#6.INPA
w 898 1960 100 0 n#72 ecad2.ecad2#6.FLNK 752 1680 896 1680 896 2192 928 2192 engAck.engAck#59.SLNK
w 834 2168 100 0 n#71 ecad2.ecad2#6.VAL 752 2032 832 2032 832 2256 928 2256 engAck.engAck#59.INP
s 2720 96 200 0 INIT COMMAND
s 2784 176 100 0 MCS Level 3
s 2480 144 100 0 Andy Foster
[cell use]
use hwin 1920 1559 100 0 hwin#163
xform 0 2016 1600
p 1923 1592 100 0 -1 val(in):$(START)
use eaos 2304 1463 100 0 eaos#161
xform 0 2432 1552
p 2336 1648 100 0 1 OMSL:closed_loop
p 2416 1456 100 1024 -1 name:$(top)$(command)ao
use hwout 992 1767 100 0 hwout#155
xform 0 1088 1808
p 1200 1808 100 0 -1 val(outp):$(top)reload.A
use hwout 2720 1479 100 0 hwout#157
xform 0 2816 1520
p 2736 1568 100 0 -1 val(outp):$(top)reload.DIR .PP
use hwin 72 1768 100 0 hwin#92
xform 0 144 1808
p 48 1838 100 0 -1 val(in):$(top)debugLevelL
use simmDecode 1144 1512 100 0 simmDecode#66
xform 0 1328 1624
p 1184 1502 100 0 -1 name:$(top)$(command)SD
use engAck 952 2056 100 0 engAck#59
xform 0 1120 2192
use ecad2 456 1464 100 0 ecad2#6
xform 0 592 1776
p 528 1728 100 0 1 FTVA:STRING
p 512 2078 100 0 0 FTVB:STRING
p 528 1774 100 0 1 SNAM:initCAD
p 544 1456 100 1024 -1 name:$(top)$(command)
p 768 1808 75 1024 -1 pproc(OUTA):NPP
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
