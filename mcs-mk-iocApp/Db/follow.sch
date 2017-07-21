[schematic2]
uniq 363
[tools]
[detail]
w 1498 555 100 0 n#352 ecad20.ecad20#246.STLK 1408 544 1648 544 simmDecode.simmDecode#66.SLNK
w 1442 523 100 0 n#352 ecad20.ecad20#246.SPLK 1408 512 1536 512 1536 544 junction
w 2170 555 100 0 n#359 simmDecode.simmDecode#66.NONE 2064 544 2336 544 followNONE.followNONE#353.SLNK
w 954 1771 100 0 n#357 hwin.hwin#358.in 880 1760 1088 1760 ecad20.ecad20#246.INPD
w 1602 2283 100 0 n#354 ecad20.ecad20#246.VAL 1408 2176 1504 2176 1504 2272 1760 2272 engAck.engAck#59.INP
w 1634 2219 100 0 n#351 ecad20.ecad20#246.FLNK 1408 672 1568 672 1568 2208 1760 2208 engAck.engAck#59.SLNK
w 954 1643 100 0 n#349 hwin.hwin#244.in 880 1632 1088 1632 ecad20.ecad20#246.INPF
w 954 1707 100 0 n#348 hwin.hwin#241.in 880 1696 1088 1696 ecad20.ecad20#246.INPE
w 954 1835 100 0 n#347 hwin.hwin#262.in 880 1824 1088 1824 ecad20.ecad20#246.INPC
w 954 1899 100 0 n#346 hwin.hwin#261.in 880 1888 1088 1888 ecad20.ecad20#246.INPB
w 954 1963 100 0 n#345 hwin.hwin#94.in 880 1952 1088 1952 ecad20.ecad20#246.INPA
s 2816 176 100 0 Andy Foster
s 2784 176 100 0 MCS Level 3
s 2720 96 200 0 FOLLOW COMMAND
[cell use]
use continuousData 1632 183 100 0 continuousData#360
xform 0 1928 264
use hwin 712 1720 100 0 hwin#358
xform 0 784 1760
p 656 1726 100 0 -1 val(in):$(top)FollowL
use hwin 712 1912 100 0 hwin#94
xform 0 784 1952
p 656 1918 100 0 -1 val(in):$(top)debugLevelL
use hwin 712 1656 100 0 hwin#241
xform 0 784 1696
p 656 1662 100 0 -1 val(in):$(top)azStateL
use hwin 712 1592 100 0 hwin#244
xform 0 784 1632
p 656 1598 100 0 -1 val(in):$(top)elStateL
use hwin 712 1848 100 0 hwin#261
xform 0 784 1888
p 656 1854 100 0 -1 val(in):$(top)azDatumL
use hwin 712 1784 100 0 hwin#262
xform 0 784 1824
p 656 1790 100 0 -1 val(in):$(top)elDatumL
use followNONE 2336 487 100 0 followNONE#353
xform 0 2512 624
use simmDecode 1672 504 100 0 simmDecode#66
xform 0 1856 616
p 1712 494 100 0 -1 name:$(top)$(command)SD
use ecad20 1112 456 100 0 ecad20#246
xform 0 1248 1344
p 1184 1886 100 0 0 FTVA:STRING
p 1184 1854 100 0 0 FTVB:STRING
p 1184 1822 100 0 0 FTVC:STRING
p 1184 1824 100 0 0 FTVD:STRING
p 1168 1678 100 0 1 SNAM:followCAD
p 1200 448 100 1024 -1 name:$(top)$(command)
use engAck 1784 2072 100 0 engAck#59
xform 0 1952 2208
use bc200tr -128 -104 -100 0 frame
xform 0 1552 1200
[comments]
