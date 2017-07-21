[schematic2]
uniq 279
[tools]
[detail]
w 130 1835 100 0 n#278 hwin.hwin#277.in 192 1888 256 1888 256 1824 64 1824 64 1696 224 1696 efanouts.efanouts#269.SELL
w 642 2091 100 0 n#224 hwin.hwin#222.in 608 2080 736 2080 ecalcs.ecalcs#223.INPA
w 1034 1179 100 0 n#224 junction 640 2080 640 1168 1488 1168 ecalcs.ecalcs#230.INPA
w 1938 1323 100 0 n#276 eseqs.eseqs#139.LNK2 2416 2016 2560 2016 2560 1312 1376 1312 1376 784 1488 784 ecalcs.ecalcs#230.SLNK
w 2418 1099 100 0 OK efanouts.efanouts#232.LNK1 2272 1088 2624 1088 2624 1408 2976 1408 outhier.OK.p
w 2508 1995 100 0 OK eseqs.eseqs#139.LNK3 2416 1984 2624 1984 2624 1408 junction
w 1572 1419 100 0 OK efanouts.efanouts#269.LNK2 416 1664 544 1664 544 1408 2624 1408 junction
w 2418 1067 100 0 FAIL efanouts.efanouts#232.LNK2 2272 1056 2624 1056 2624 976 2976 976 outhier.FAIL.p
w 1074 2283 100 0 n#272 ecalcs.ecalcs#223.FLNK 1024 1920 1056 1920 1056 2272 1152 2272 eaos.eaos#245.SLNK
w 546 1707 100 0 n#271 efanouts.efanouts#269.LNK1 416 1696 736 1696 ecalcs.ecalcs#223.SLNK
w 74 1627 100 0 SLNK inhier.SLNK.P 32 1616 176 1616 efanouts.efanouts#269.SLNK
w 1298 1899 100 0 n#268 ecalcs.ecalcs#223.VAL 1024 1888 1632 1888 1632 2080 2096 2080 eseqs.eseqs#139.SELL
w 1650 2315 100 0 n#265 eaos.eaos#245.FLNK 1408 2304 1952 2304 1952 1728 2096 1728 eseqs.eseqs#139.SLNK
w 1978 2059 100 0 n#263 hwin.hwin#227.in 1920 2048 2096 2048 eseqs.eseqs#139.DOL1
w 1426 2251 100 0 n#249 eaos.eaos#245.OUT 1408 2240 1504 2240 hwout.hwout#247.outp
w 1074 2315 100 0 n#246 hwin.hwin#244.in 1056 2304 1152 2304 eaos.eaos#245.DOL
w 1826 987 100 0 n#234 ecalcs.ecalcs#230.VAL 1776 976 1936 976 1936 1088 2080 1088 efanouts.efanouts#232.SELL
w 1874 1019 100 0 n#233 ecalcs.ecalcs#230.FLNK 1776 1008 2032 1008 efanouts.efanouts#232.SLNK
w 2530 2059 100 0 n#229 eseqs.eseqs#139.LNK1 2416 2048 2704 2048 hwout.hwout#205.outp
[cell use]
use hwin 864 2263 100 0 hwin#244
xform 0 960 2304
p 848 2352 100 0 -1 val(in):$(top)GIStimeout
use hwin 416 2039 100 0 hwin#222
xform 0 512 2080
p 320 2128 100 0 -1 val(in):$(top)$(dev)DriveCondition
use hwin 1728 2007 100 0 hwin#227
xform 0 1824 2048
p 1728 2000 100 0 -1 val(in):$(DISASSERT)
use hwin 0 1847 100 0 hwin#277
xform 0 96 1888
p -16 1936 100 0 -1 val(in):$(top)GISbypassCalc
use efanouts 2032 871 100 0 efanouts#232
xform 0 2152 1024
p 2128 1168 100 0 1 SELM:Mask
p 2144 864 100 1024 -1 name:$(top)$(dev)$(command)GIS5-$(id)
p 2304 1088 75 1280 -1 pproc(LNK1):PP
p 2304 1056 75 1280 -1 pproc(LNK2):PP
use efanouts 176 1479 100 0 efanouts#269
xform 0 296 1632
p 256 1776 100 0 1 SELM:Mask
p 288 1472 100 1024 -1 name:$(top)$(dev)$(command)GIS0-$(id)
p 448 1696 75 1280 -1 pproc(LNK1):PP
p 448 1664 75 1280 -1 pproc(LNK2):PP
use hwout 1504 2199 100 0 hwout#247
xform 0 1600 2240
p 1392 2128 100 0 -1 val(outp):$(top)$(dev)$(command)GIS3-$(id).DLY2
use hwout 2728 2008 100 0 hwout#205
xform 0 2800 2048
p 2736 2078 100 0 -1 val(outp):$(top)$(dev)DriveEnable .PP
use eaos 1152 2183 100 0 eaos#245
xform 0 1280 2272
p 896 2254 100 0 0 OMSL:closed_loop
p 1264 2176 100 1024 -1 name:$(top)$(dev)$(command)GIS2-$(id)
use inhier 16 1575 100 0 SLNK
xform 0 32 1616
use outhier 2944 1367 100 0 OK
xform 0 2960 1408
use outhier 2944 935 100 0 FAIL
xform 0 2960 976
use ecalcs 736 1607 100 0 ecalcs#223
xform 0 880 1872
p 768 2144 100 0 1 CALC:(A=1)?4:3
p 848 1600 100 1024 -1 name:$(top)$(dev)$(command)GIS1-$(id)
use ecalcs 1488 695 100 0 ecalcs#230
xform 0 1632 960
p 1536 1216 100 0 1 CALC:(A=1)?1:2
p 1600 688 100 1024 -1 name:$(top)$(dev)$(command)GIS4-$(id)
use eseqs 2120 1640 100 0 eseqs#139
xform 0 2256 1888
p 2176 2126 100 0 0 DLY1:0.0
p 2192 2160 100 0 0 DLY2:0.0
p 2208 2112 100 0 1 SELM:Mask
p 2208 1632 100 1024 -1 name:$(top)$(dev)$(command)GIS3-$(id)
p 2432 2048 75 1024 -1 pproc(LNK1):NPP
p 2432 2016 75 1024 -1 pproc(LNK2):PP
p 2432 1984 75 1024 -1 pproc(LNK3):PP
use bc200tr -144 -24 -100 0 frame
xform 0 1536 1280
[comments]
