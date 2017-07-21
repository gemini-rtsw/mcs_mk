[schematic2]
uniq 120
[tools]
[detail]
w 1650 1858 100 0 n#119 eseqs.eseqs#103.LNK3 1600 1856 1760 1856 1760 1792 1856 1792 hwout.hwout#117.outp
w 1666 1890 100 0 n#118 eseqs.eseqs#103.LNK2 1600 1888 1792 1888 1792 1856 1856 1856 hwout.hwout#116.outp
w 1698 1922 100 0 n#115 eseqs.eseqs#103.LNK1 1600 1920 1856 1920 hwout.hwout#114.outp
w 1618 1826 100 0 n#115 eseqs.eseqs#103.LNK4 1600 1824 1696 1824 1696 1920 junction
w 1058 1954 100 0 n#113 ecad4.ecad4#99.VALC 752 1760 896 1760 896 1952 1280 1952 eseqs.eseqs#103.SELL
w 866 1926 100 0 n#112 ecad4.ecad4#99.FLNK 752 1600 864 1600 864 2192 928 2192 engAck.engAck#59.SLNK
w 834 2198 100 0 n#111 ecad4.ecad4#99.VAL 752 2080 832 2080 832 2256 928 2256 engAck.engAck#59.INP
w 1186 1828 100 0 n#110 hwin.hwin#109.in 1152 1824 1280 1824 eseqs.eseqs#103.DOL4
w 1186 1922 100 0 n#108 hwin.hwin#107.in 1152 1920 1280 1920 eseqs.eseqs#103.DOL1
w 1074 1860 100 0 n#106 ecad4.ecad4#99.VALB 752 1824 928 1824 928 1856 1280 1856 eseqs.eseqs#103.DOL3
w 986 1890 100 0 n#105 ecad4.ecad4#99.VALA 752 1888 1280 1888 eseqs.eseqs#103.DOL2
w 938 1474 100 0 n#104 ecad4.ecad4#99.STLK 752 1472 1184 1472 1184 1600 1280 1600 eseqs.eseqs#103.SLNK
w 312 1732 100 0 n#95 hwin.hwin#94.in 240 1728 432 1728 ecad4.ecad4#99.INPC
s 2720 96 200 0 TOLERANCE COMMAND
s 2784 176 100 0 MCS Level 3
s 2480 144 100 0 Andy Foster
[cell use]
use hwout 1880 1880 100 0 hwout#114
xform 0 1952 1920
p 2064 1918 100 0 -1 val(outp):$(top)softC.IVAL .PP
use hwout 1880 1816 100 0 hwout#116
xform 0 1952 1856
p 2064 1854 100 0 -1 val(outp):$(top)positionTol .PP
use hwout 1880 1752 100 0 hwout#117
xform 0 1952 1792
p 2064 1790 100 0 -1 val(outp):$(top)velocityTol .PP
use hwin 984 1784 100 0 hwin#109
xform 0 1056 1824
p 963 1816 100 0 -1 val(in):$(IDLE)
use hwin 984 1880 100 0 hwin#107
xform 0 1056 1920
p 963 1912 100 0 -1 val(in):$(BUSY)
use hwin 72 1688 100 0 hwin#94
xform 0 144 1728
p 48 1694 100 0 -1 val(in):$(top)debugLevelL
use eseqs 1304 1512 100 0 eseqs#103
xform 0 1440 1760
p 1392 1504 100 1024 -1 name:$(top)$(command)Seq
p 1392 1726 100 0 1 SELM:Mask
p 1392 1950 100 0 1 DLY4:1.0
use ecad4 456 1384 100 0 ecad4#99
xform 0 592 1760
p 544 1376 100 1024 -1 name:$(top)$(command)
p 512 2222 100 0 1 SNAM:toleranceCAD
p 512 2190 100 0 1 FTVA:DOUBLE
p 512 2158 100 0 1 FTVB:DOUBLE
p 512 2126 100 0 1 FTVC:LONG
use engAck 952 2056 100 0 engAck#59
xform 0 1120 2192
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
