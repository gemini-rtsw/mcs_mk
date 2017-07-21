[schematic2]
uniq 124
[tools]
[detail]
w 1130 1931 100 0 n#122 ecad4.ecad4#99.VALA 752 1920 1568 1920 reloadNONE.reloadNONE#121.ID
w 1394 1515 100 0 n#118 simmDecode.simmDecode#66.NONE 1344 1504 1504 1504 1504 1728 1568 1728 reloadNONE.reloadNONE#121.SLNK
w 850 2267 100 0 n#114 ecad4.ecad4#99.VAL 752 2112 832 2112 832 2256 928 2256 engAck.engAck#59.INP
w 794 1643 100 0 n#113 ecad4.ecad4#99.FLNK 752 1632 896 1632 896 2192 928 2192 engAck.engAck#59.SLNK
w 810 1515 100 0 n#111 ecad4.ecad4#99.STLK 752 1504 928 1504 simmDecode.simmDecode#66.SLNK
w 314 1835 100 0 n#110 hwin.hwin#94.in 256 1824 432 1824 ecad4.ecad4#99.INPB
s 2720 96 200 0 AZCONFIG COMMAND
s 2784 176 100 0 MCS Level 3
s 2480 144 100 0 Andy Foster
[cell use]
use reloadNONE 1568 1671 100 0 reloadNONE#121
xform 0 1776 1840
use ecad4 456 1416 100 0 ecad4#99
xform 0 592 1792
p 528 1904 100 0 1 FTVA:LONG
p 528 1872 100 0 0 FTVB:STRING
p 528 1840 100 0 0 FTVC:STRING
p 496 2160 100 0 1 SNAM:reloadCAD
p 544 1408 100 1024 -1 name:$(top)$(command)
use hwin 88 1784 100 0 hwin#94
xform 0 160 1824
p 64 1790 100 0 -1 val(in):$(top)debugLevelL
use simmDecode 952 1464 100 0 simmDecode#66
xform 0 1136 1576
p 992 1454 100 0 -1 name:$(top)$(command)SD
use engAck 952 2056 100 0 engAck#59
xform 0 1120 2192
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
