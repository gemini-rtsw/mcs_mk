[schematic2]
uniq 301
[tools]
[detail]
w 2420 2011 100 2 n#300 hwout.hwout#205.outp 2416 2016 2416 2016 eseqs.eseqs#139.LNK2
w 2420 2043 100 2 n#299 hwout.hwout#288.outp 2416 2048 2416 2048 eseqs.eseqs#139.LNK1
w 2010 2027 100 0 n#298 hwin.hwin#227.in 1984 2016 2096 2016 eseqs.eseqs#139.DOL2
w 2010 2059 100 0 n#297 hwin.hwin#279.in 1984 2048 2096 2048 eseqs.eseqs#139.DOL1
w 2354 555 100 0 n#296 efanouts.efanouts#232.LNK3 2272 1024 2528 1024 2528 544 2240 544 elongouts.elongouts#290.SLNK
w 1988 507 100 2 n#295 hwout.hwout#294.outp 1984 512 1984 512 elongouts.elongouts#290.OUT
w 2244 571 100 2 n#292 hwin.hwin#291.in 2240 576 2240 576 elongouts.elongouts#290.DOL
w 130 1803 100 0 n#278 hwin.hwin#277.in 192 1856 224 1856 224 1792 96 1792 96 1696 224 1696 efanouts.efanouts#269.SELL
w 642 2091 100 0 n#224 hwin.hwin#222.in 608 2080 736 2080 ecalcs.ecalcs#223.INPA
w 1034 1179 100 0 n#224 junction 640 2080 640 1168 1488 1168 ecalcs.ecalcs#230.INPA
w 1938 1323 100 0 n#276 eseqs.eseqs#139.LNK3 2416 1984 2560 1984 2560 1312 1376 1312 1376 784 1488 784 ecalcs.ecalcs#230.SLNK
w 2418 1099 100 0 OK efanouts.efanouts#232.LNK1 2272 1088 2624 1088 2624 1408 2976 1408 outhier.OK.p
w 2508 1963 100 0 OK eseqs.eseqs#139.LNK4 2416 1952 2624 1952 2624 1408 junction
w 1572 1419 100 0 OK efanouts.efanouts#269.LNK2 416 1664 544 1664 544 1408 2624 1408 junction
w 2418 1067 100 0 FAIL efanouts.efanouts#232.LNK2 2272 1056 2624 1056 2624 976 2976 976 outhier.FAIL.p
w 1074 2283 100 0 n#272 ecalcs.ecalcs#223.FLNK 1024 1920 1056 1920 1056 2272 1152 2272 eaos.eaos#245.SLNK
w 546 1707 100 0 n#271 efanouts.efanouts#269.LNK1 416 1696 736 1696 ecalcs.ecalcs#223.SLNK
w 74 1627 100 0 SLNK inhier.SLNK.P 32 1616 176 1616 efanouts.efanouts#269.SLNK
w 1298 1899 100 0 n#268 ecalcs.ecalcs#223.VAL 1024 1888 1632 1888 1632 2080 2096 2080 eseqs.eseqs#139.SELL
w 1650 2315 100 0 n#265 eaos.eaos#245.FLNK 1408 2304 1952 2304 1952 1728 2096 1728 eseqs.eseqs#139.SLNK
w 1426 2251 100 0 n#249 eaos.eaos#245.OUT 1408 2240 1504 2240 hwout.hwout#247.outp
w 1074 2315 100 0 n#246 hwin.hwin#244.in 1056 2304 1152 2304 eaos.eaos#245.DOL
w 1826 987 100 0 n#234 ecalcs.ecalcs#230.VAL 1776 976 1936 976 1936 1088 2080 1088 efanouts.efanouts#232.SELL
w 1874 1019 100 0 n#233 ecalcs.ecalcs#230.FLNK 1776 1008 2032 1008 efanouts.efanouts#232.SLNK
s 128 752 100 0 It will only respond if waiting for a response (only time that the record will process due to DISA)
s 128 704 100 0 The timout will still occor as before and keep the sequence moving.
s 128 800 100 0 When the DriveCondition changes, this record will be triggered.
[cell use]
use hwout 1984 471 100 0 hwout#294
xform 4 1888 512
p 1760 512 100 0 -1 val(outp):$(top)$(dev)$(command)GIS4-$(id).DISA
use hwout 2416 2007 100 0 hwout#288
xform 0 2512 2048
p 2624 2048 100 0 -1 val(outp):$(top)$(dev)$(command)GIS4-$(id).DISA
use hwout 1504 2199 100 0 hwout#247
xform 0 1600 2240
p 1392 2128 100 0 -1 val(outp):$(top)$(dev)$(command)GIS3-$(id).DLY3
use hwout 2440 1976 100 0 hwout#205
xform 0 2512 2016
p 2624 2000 100 0 -1 val(outp):$(top)$(dev)DriveEnable .PP
use hwin 2432 535 100 0 hwin#291
xform 4 2336 576
p 2429 568 100 0 -1 val(in):0
use hwin 1792 2007 100 0 hwin#279
xform 0 1888 2048
p 1760 2048 100 0 -1 val(in):1
use hwin 0 1815 100 0 hwin#277
xform 0 96 1856
p -16 1904 100 0 -1 val(in):$(top)GISbypassCalc
use hwin 864 2263 100 0 hwin#244
xform 0 960 2304
p 848 2352 100 0 -1 val(in):$(top)GIStimeout
use hwin 416 2039 100 0 hwin#222
xform 0 512 2080
p 320 2128 100 0 -1 val(in):$(top)$(dev)DriveCondition
use hwin 1792 1975 100 0 hwin#227
xform 0 1888 2016
p 1792 1968 100 0 -1 val(in):$(ASSERT)
use elongouts 2240 455 100 0 elongouts#290
xform 4 2112 544
p 2128 416 100 0 1 OMSL:closed_loop
p 2128 448 100 1024 -1 name:$(top)$(dev)$(command)DisableScan
use efanouts 2032 871 100 0 efanouts#232
xform 0 2152 1024
p 2128 1168 100 0 1 SELM:Mask
p 2144 864 100 1024 -1 name:$(top)$(dev)$(command)GIS5-$(id)
p 2304 1088 75 1280 -1 pproc(LNK1):PP
p 2304 1056 75 1280 -1 pproc(LNK2):PP
p 2304 1024 75 1280 -1 pproc(LNK3):PP
use efanouts 176 1479 100 0 efanouts#269
xform 0 296 1632
p 256 1776 100 0 1 SELM:Mask
p 288 1472 100 1024 -1 name:$(top)$(dev)$(command)GIS0-$(id)
p 448 1696 75 1280 -1 pproc(LNK1):PP
p 448 1664 75 1280 -1 pproc(LNK2):PP
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
p 768 2144 100 0 1 CALC:(A=2)?8:7
p 848 1600 100 1024 -1 name:$(top)$(dev)$(command)GIS1-$(id)
use ecalcs 1488 695 100 0 ecalcs#230
xform 0 1632 960
p 1536 1216 100 0 1 CALC:(A=2)?5:3
p 1424 656 100 0 1 DISV:0
p 1600 688 100 1024 -1 name:$(top)$(dev)$(command)GIS4-$(id)
use eseqs 2120 1640 100 0 eseqs#139
xform 0 2256 1888
p 2176 2126 100 0 0 DLY1:0.0
p 2192 2160 100 0 0 DLY2:0.0
p 2208 2112 100 0 1 SELM:Mask
p 1408 1840 100 0 -1 def(DOL2):0.0000
p 2208 1632 100 1024 -1 name:$(top)$(dev)$(command)GIS3-$(id)
p 2432 2048 75 1024 -1 pproc(LNK1):NPP
p 2432 2016 75 1024 -1 pproc(LNK2):NPP
p 2432 1984 75 1024 -1 pproc(LNK3):PP
p 2432 1952 75 1024 -1 pproc(LNK4):PP
p 1712 892 100 0 0 typ(DOL2):path
use bc200tr -144 -24 -100 0 frame
xform 0 1536 1280
[comments]
