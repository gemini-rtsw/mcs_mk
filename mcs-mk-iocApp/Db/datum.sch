[schematic2]
uniq 319
[tools]
[detail]
w 1834 1803 100 0 n#302 simmDecode.simmDecode#66.FULL 1744 1792 1984 1792 junction
w 1834 1835 100 0 n#302 simmDecode.simmDecode#66.FAST 1744 1824 1984 1824 junction
w 1834 1771 100 0 n#302 simmDecode.simmDecode#66.NONE 1744 1760 1984 1760 1984 1920 2080 1920 datumNONE.datumNONE#274.SLNK
w 1834 1867 100 0 n#302 simmDecode.simmDecode#66.VSM 1744 1856 1984 1856 junction
w 1666 1995 100 0 n#315 ecad8.ecad8#236.VALE 1088 2176 1312 2176 1312 1984 2080 1984 datumNONE.datumNONE#274.EL_CMD
w 1698 2059 100 0 n#314 ecad8.ecad8#236.VALD 1088 2240 1376 2240 1376 2048 2080 2048 datumNONE.datumNONE#274.AZ_CMD
w 1170 2283 100 0 n#310 ecad8.ecad8#236.OUTC 1088 2272 1312 2272 hwout.hwout#309.outp
w 1170 2347 100 0 n#308 ecad8.ecad8#236.OUTB 1088 2336 1312 2336 hwout.hwout#307.outp
w 1554 2443 100 0 n#294 ecad8.ecad8#236.VALA 1088 2432 2080 2432 datumNONE.datumNONE#274.MASK
w 650 2082 100 0 n#256 hwin.hwin#244.in 592 2080 768 2080 ecad8.ecad8#236.INPF
w 650 2146 100 0 n#255 hwin.hwin#241.in 592 2144 768 2144 ecad8.ecad8#236.INPE
w 1178 1762 100 0 n#246 ecad8.ecad8#236.STLK 1088 1760 1328 1760 simmDecode.simmDecode#66.SLNK
w 1234 2326 100 0 n#240 ecad8.ecad8#236.FLNK 1088 1888 1232 1888 1232 2704 1264 2704 engAck.engAck#59.SLNK
w 1170 2726 100 0 n#106 ecad8.ecad8#236.VAL 1088 2624 1168 2624 1168 2768 1264 2768 engAck.engAck#59.INP
w 650 2212 100 0 n#103 hwin.hwin#94.in 592 2208 768 2208 ecad8.ecad8#236.INPD
[cell use]
use hwin 424 2040 100 0 hwin#244
xform 0 496 2080
p 224 2078 100 0 -1 val(in):$(top)elStateL
use hwin 424 2104 100 0 hwin#241
xform 0 496 2144
p 224 2142 100 0 -1 val(in):$(top)azStateL
use hwin 424 2168 100 0 hwin#94
xform 0 496 2208
p 192 2206 100 0 -1 val(in):$(top)debugLevelL
use hwout 1312 2231 100 0 hwout#309
xform 0 1408 2272
p 1520 2272 100 0 -1 val(outp):$(top)elDatumMechL .PP
use hwout 1312 2295 100 0 hwout#307
xform 0 1408 2336
p 1520 2336 100 0 -1 val(outp):$(top)azDatumMechL .PP
use datumNONE 2104 1999 100 0 datumNONE#274
xform 0 2272 2176
use bc200tr -272 600 -100 0 frame
xform 0 1408 1904
use ecad8 792 1672 100 0 ecad8#236
xform 0 928 2176
p 864 2478 100 0 1 FTVA:LONG
p 864 2446 100 0 1 FTVB:LONG
p 864 2416 100 0 1 FTVC:LONG
p 864 2384 100 0 1 FTVD:LONG
p 864 2352 100 0 1 FTVE:LONG
p 864 2320 100 0 0 FTVF:LONG
p 864 2288 100 0 0 FTVG:LONG
p 864 2256 100 0 0 FTVH:LONG
p 864 2526 100 0 1 SNAM:datumCAD
p 880 1664 100 1024 -1 name:$(top)$(command)
use simmDecode 1352 1720 100 0 simmDecode#66
xform 0 1536 1832
p 1392 1710 100 0 -1 name:$(top)$(command)SD
use engAck 1288 2568 100 0 engAck#59
xform 0 1456 2704
[comments]
