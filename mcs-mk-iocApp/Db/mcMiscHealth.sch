[schematic2]
uniq 17
[tools]
[detail]
w 1840 1763 100 0 n#1 egenSub.miscHealthCombine.OUTA 1760 1760 1920 1760 1920 1696 2048 1696 esirs.miscHealth.IMSS
w 168 1443 100 0 n#2 inhier.c#182.P -48 1440 384 1440 esirs.tcsDataHealth.INP
w 880 1379 100 0 n#3 esirs.tcsDataHealth.OMSS 800 1376 960 1376 960 1504 1472 1504 egenSub.miscHealthCombine.INPE
w 864 1411 100 0 n#4 esirs.tcsDataHealth.VAL 800 1408 928 1408 928 1760 1472 1760 egenSub.miscHealthCombine.INPA
w 1840 1059 100 0 n#5 egenSub.miscHealthCombine.FLNK 1760 1056 1920 1056 1920 1568 2048 1568 esirs.miscHealth.SLNK
w 1904 1731 100 0 n#6 egenSub.miscHealthCombine.VALB 1760 1728 2048 1728 esirs.miscHealth.INP
w 888 339 100 0 n#7 inhier.SLNK.P 496 336 1280 336 1280 1088 1472 1088 egenSub.miscHealthCombine.SLNK
w 928 515 100 0 n#8 hwinl.hwinl#193.in 976 512 1216 512 1216 1312 1472 1312 egenSub.miscHealthCombine.INPH
w 896 771 100 0 n#9 hwinl.hwinl#191.in 976 768 1152 768 1152 1360 1472 1360 1472 1376 egenSub.miscHealthCombine.INPG
w 1032 1027 100 0 n#10 hwinl.hwinl#189.in 976 1024 1088 1024 1088 1440 1472 1440 egenSub.miscHealthCombine.INPF
w 1224 1571 100 0 n#11 hwinl.hwinl#187.in 976 1568 1472 1568 egenSub.miscHealthCombine.INPD
w 1000 1827 100 0 n#12 hwinl.hwinl#185.in 976 1824 1024 1824 1024 1632 1472 1632 egenSub.miscHealthCombine.INPC
w 1032 2051 100 0 n#13 hwinl.hwinl#183.in 976 2048 1088 2048 1088 1696 1472 1696 egenSub.miscHealthCombine.INPB
w 2528 1731 100 0 n#14 esirs.miscHealth.FLNK 2464 1728 2592 1728 2592 1872 2752 1872 outhier.FLNK.p
w 2528 1667 100 0 n#15 esirs.miscHealth.OMSS 2464 1664 2592 1664 2592 1552 2752 1552 outhier.MESS.p
w 2608 1699 100 0 n#16 esirs.miscHealth.VAL 2464 1696 2752 1696 outhier.VAL.p
s 1520 544 100 0 added.
s 1520 576 100 0 added then the dummy records can be deleted and the real ones
s 1520 608 100 0 inputs to the gensub. If additional time health items need to be
s 1520 640 100 0 Note these dummy records are in place to provide the correct
s 2368 352 100 0 Gemini
s 2368 320 100 0 Observatory
s 2624 384 100 0 Combine MCS health records
s 2352 2576 100 0 $Id: mcMiscHealth.sch,v 1.3 2001/10/22 17:54:45 gemvx Exp $
s 848 2448 200 0 This schematic combines all the individual miscellaneous health records
s 1008 2384 200 0 in the MCS into a single overall miscellaneous health
[cell use]
use bc200tr -224 104 -100 0 frame
xform 0 1456 1408
use inhier -64 1399 100 0 c#182
xform 0 -48 1440
use inhier 480 295 100 0 SLNK
xform 0 496 336
use esirs 2048 1479 100 0 miscHealth
xform 0 2256 1632
p 2144 1792 100 0 -1 DESC:Overall miscellaneous health
p 1984 1216 100 0 0 FDSC:Combined miscellaneous health records
use esirs 384 1191 100 0 tcsDataHealth
xform 0 592 1344
p 480 1488 100 0 -1 DESC:Health of TCS data
p 320 928 100 0 0 FDSC:Health of data stream from TCS
p 480 1248 100 0 1 SNAM:mcDataHealth
p 32 1456 100 0 -1 def(INP):$(mc)arrayS
p 496 1184 100 1024 0 name:$(top)tcsDataHealth
use estringouts 416 743 100 0 miscDummyMess3
xform 0 544 816
p 544 832 100 0 0 DESC:Empty message
p 352 782 100 0 0 VAL:
p 384 252 100 0 0 def(DOL):
use estringouts 416 487 100 0 miscDummyMess4
xform 0 544 560
p 544 576 100 0 0 DESC:Empty message
p 352 526 100 0 0 VAL:
p 384 -4 100 0 0 def(DOL):
use estringouts 416 1799 100 0 miscDummyVal3
xform 0 544 1872
p 544 1888 100 0 0 DESC:Dummy health value
p 352 1838 100 0 0 VAL:GOOD
p 384 1308 100 0 0 def(DOL):
use estringouts 416 1543 100 0 miscDummyVal4
xform 0 544 1616
p 544 1632 100 0 0 DESC:Dummy health value
p 352 1582 100 0 0 VAL:GOOD
p 384 1052 100 0 0 def(DOL):
use estringouts 416 999 100 0 miscDummyMess2
xform 0 544 1072
p 544 1088 100 0 0 DESC:Empty message
p 352 1038 100 0 0 VAL:
p 384 508 100 0 0 def(DOL):
use estringouts 416 2023 100 0 miscDummyVal2
xform 0 544 2096
p 544 2112 100 0 0 DESC:Dummy health value
p 352 2062 100 0 0 VAL:GOOD
p 384 1532 100 0 0 def(DOL):
use outhier 2720 1655 100 0 VAL
xform 0 2736 1696
use outhier 2720 1511 100 0 MESS
xform 0 2736 1552
use outhier 2720 1831 100 0 FLNK
xform 0 2736 1872
use egenSub 1472 999 100 0 miscHealthCombine
xform 0 1616 1424
p 1504 1872 100 0 -1 DESC:Combine health values
p 1249 773 100 0 0 FTA:STRING
p 1249 773 100 0 0 FTB:STRING
p 1249 741 100 0 0 FTC:STRING
p 1249 709 100 0 0 FTD:STRING
p 1249 677 100 0 0 FTE:STRING
p 1249 613 100 0 0 FTF:STRING
p 1249 613 100 0 0 FTG:STRING
p 1249 581 100 0 0 FTH:STRING
p 1249 773 100 0 0 FTVA:STRING
p 1249 773 100 0 0 FTVB:STRING
p 1249 741 100 0 0 FTVC:LONG
p 1696 928 100 0 0 SCAN:Passive
p 1696 976 100 0 1 SNAM:mcHealthCombine
p 192 1728 100 0 0 def(INPB):0.0
p 1920 1776 100 0 0 def(OUTA):0.0
p 1424 1770 75 0 -1 pproc(INPA):PP
p 1760 1770 75 0 -1 pproc(OUTA):NPP
use hwinl 592 1976 100 0 hwinl#183
xform 0 784 2024
p 602 2040 100 0 -1 val(in):$(top)miscDummyVal2.VAL
use hwinl 592 1752 100 0 hwinl#185
xform 0 784 1800
p 602 1816 100 0 -1 val(in):$(top)miscDummyVal3.VAL
use hwinl 592 1496 100 0 hwinl#187
xform 0 784 1544
p 602 1560 100 0 -1 val(in):$(top)miscDummyVal4.VAL
use hwinl 592 952 100 0 hwinl#189
xform 0 784 1000
p 602 1016 100 0 -1 val(in):$(top)miscDummyMess2.VAL
use hwinl 592 696 100 0 hwinl#191
xform 0 784 744
p 602 760 100 0 -1 val(in):$(top)miscDummyMess3.VAL
use hwinl 592 440 100 0 hwinl#193
xform 0 784 488
p 602 504 100 0 -1 val(in):$(top)miscDummyMess4.VAL
[comments]
