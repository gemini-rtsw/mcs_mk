[schematic2]
uniq 131
[tools]
[detail]
w 1362 1659 100 0 n#130 simmDecode.simmDecode#66.VSM 1344 1648 1440 1648 1440 1616 junction
w 1362 1627 100 0 n#130 simmDecode.simmDecode#66.FAST 1344 1616 1440 1616 1440 1584 junction
w 1362 1595 100 0 n#130 simmDecode.simmDecode#66.FULL 1344 1584 1440 1584 1440 1552 junction
w 1466 1563 100 0 n#130 simmDecode.simmDecode#66.NONE 1344 1552 1648 1552 esubs.esubs#110.SLNK
w 320 1810 100 0 n#99 hwin.hwin#94.in 256 1808 432 1808 ecad2.ecad2#6.INPA
w 816 1554 100 0 n#96 ecad2.ecad2#6.STLK 752 1552 928 1552 simmDecode.simmDecode#66.SLNK
w 898 1960 100 0 n#72 ecad2.ecad2#6.FLNK 752 1680 896 1680 896 2192 928 2192 engAck.engAck#59.SLNK
w 834 2168 100 0 n#71 ecad2.ecad2#6.VAL 752 2032 832 2032 832 2256 928 2256 engAck.engAck#59.INP
s 2720 96 200 0 REBOOT COMMAND
s 2784 176 100 0 MCS Level 3
s 2480 144 100 0 Andy Foster
[cell use]
use hwin 88 1768 100 0 hwin#94
xform 0 160 1808
p 64 1774 100 0 -1 val(in):$(top)debugLevelL
use esubs 1672 1464 100 0 esubs#110
xform 0 1792 1728
p 1824 1886 100 0 1 INAM:nullSub
p 1840 1854 100 0 1 SNAM:rebootSub
p 1760 1456 100 1024 -1 name:$(top)$(command)sub1
use simmDecode 952 1512 100 0 simmDecode#66
xform 0 1136 1624
p 992 1502 100 0 -1 name:$(top)$(command)SD
use engAck 952 2056 100 0 engAck#59
xform 0 1120 2192
use ecad2 456 1464 100 0 ecad2#6
xform 0 592 1776
p 512 2110 100 0 0 FTVA:STRING
p 512 2078 100 0 0 FTVB:STRING
p 512 1806 100 0 1 SNAM:rebootCAD
p 544 1456 100 1024 -1 name:$(top)$(command)
p 768 1808 75 1024 -1 pproc(OUTA):NPP
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
