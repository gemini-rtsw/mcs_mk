[schematic2]
uniq 107
[tools]
[detail]
w 1538 1563 100 0 n#100 simmDecode.simmDecode#66.NONE 1536 1552 1600 1552 1600 1648 junction
w 2122 2210 100 0 n#106 eseqs.eseqs#99.LNK1 2032 2208 2272 2208 hwout.hwout#105.outp
w 2074 2178 100 0 n#106 eseqs.eseqs#99.LNK2 2032 2176 2176 2176 2176 2208 junction
w 1618 2180 100 0 n#104 hwin.hwin#102.in 1584 2176 1712 2176 eseqs.eseqs#99.DOL2
w 1642 2212 100 0 n#103 hwin.hwin#101.in 1584 2240 1632 2240 1632 2208 1712 2208 eseqs.eseqs#99.DOL1
w 1602 1798 100 0 n#100 simmDecode.simmDecode#66.VSM 1536 1648 1600 1648 1600 1888 1712 1888 eseqs.eseqs#99.SLNK
w 912 1554 100 0 n#96 ecad2.ecad2#6.STLK 752 1552 1120 1552 simmDecode.simmDecode#66.SLNK
w 312 1810 100 0 n#93 hwin.hwin#92.in 240 1808 432 1808 ecad2.ecad2#6.INPA
w 898 1960 100 0 n#72 ecad2.ecad2#6.FLNK 752 1680 896 1680 896 2192 928 2192 engAck.engAck#59.SLNK
w 834 2168 100 0 n#71 ecad2.ecad2#6.VAL 752 2032 832 2032 832 2256 928 2256 engAck.engAck#59.INP
s 2720 96 200 0 TEST COMMAND
s 2784 176 100 0 MCS Level 3
s 2480 144 100 0 Andy Foster
[cell use]
use hwout 2296 2168 100 0 hwout#105
xform 0 2368 2208
p 2496 2206 100 0 -1 val(outp):$(top)softC.IVAL .PP
use hwin 72 1768 100 0 hwin#92
xform 0 144 1808
p 48 1838 100 0 -1 val(in):$(top)debugLevelL
use hwin 1416 2200 100 0 hwin#101
xform 0 1488 2240
p 1395 2232 100 0 -1 val(in):$(BUSY)
use hwin 1416 2136 100 0 hwin#102
xform 0 1488 2176
p 1395 2168 100 0 -1 val(in):$(IDLE)
use eseqs 1736 1800 100 0 eseqs#99
xform 0 1872 2048
p 1824 2254 100 0 1 DLY2:1.0
p 1824 1792 100 1024 -1 name:$(top)$(command)seq
use simmDecode 1144 1512 100 0 simmDecode#66
xform 0 1328 1624
p 1184 1502 100 0 -1 name:$(top)$(command)SD
use engAck 952 2056 100 0 engAck#59
xform 0 1120 2192
use ecad2 456 1464 100 0 ecad2#6
xform 0 592 1776
p 512 2110 100 0 0 FTVA:STRING
p 512 2078 100 0 0 FTVB:STRING
p 528 1806 100 0 1 SNAM:testCAD
p 544 1456 100 1024 -1 name:$(top)$(command)
p 768 1808 75 1024 -1 pproc(OUTA):NPP
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
