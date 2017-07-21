[schematic2]
uniq 17
[tools]
[detail]
w 712 1475 100 0 n#1 inhier.c#165.P -48 1472 1472 1472 egenSub.timeHealthCombine.F
w 1008 1203 100 0 n#2 hwinl.hwinl#170.in 960 1200 1056 1200 1056 1632 1472 1632 egenSub.timeHealthCombine.INPC
w 1840 1059 100 0 n#3 egenSub.timeHealthCombine.FLNK 1760 1056 1920 1056 1920 1568 2048 1568 esirs.timeHealth.SLNK
w 1824 1763 100 0 n#4 egenSub.timeHealthCombine.OUTA 1760 1760 1888 1760 1888 1696 2048 1696 esirs.timeHealth.IMSS
w 1904 1731 100 0 n#5 egenSub.timeHealthCombine.VALB 1760 1728 2048 1728 esirs.timeHealth.INP
w 2528 1731 100 0 n#6 esirs.timeHealth.FLNK 2464 1728 2592 1728 2592 1872 2752 1872 outhier.FLNK.p
w 2528 1667 100 0 n#7 esirs.timeHealth.OMSS 2464 1664 2592 1664 2592 1552 2752 1552 outhier.MESS.p
w 2608 1699 100 0 n#8 esirs.timeHealth.VAL 2464 1696 2752 1696 outhier.VAL.p
w 1080 1923 100 0 n#9 mcHealthTStamp.mcHealthTStamp#130.FLNK 816 1920 1344 1920 1344 1088 1472 1088 egenSub.timeHealthCombine.SLNK
w 1128 579 100 0 n#10 hwinl.hwinl#174.in 976 576 1280 576 1280 1312 1472 1312 egenSub.timeHealthCombine.INPH
w 1208 811 100 0 n#11 hwinl.hwinl#172.in 976 800 1216 800 1216 1376 1472 1376 egenSub.timeHealthCombine.INPG
w 1016 2019 100 0 n#12 mcHealthTStamp.mcHealthTStamp#130.MESS 816 2016 1216 2016 1216 1504 1472 1504 egenSub.timeHealthCombine.INPE
w 1032 1027 100 0 n#13 hwinl.hwinl#168.in 976 1024 1088 1024 1088 1568 1472 1568 egenSub.timeHealthCombine.INPD
w 48 1923 100 0 n#14 inhier.SLNK.P -48 1920 144 1920 mcHealthTStamp.mcHealthTStamp#130.SLNK
w 1048 2115 100 0 n#15 mcHealthTStamp.mcHealthTStamp#130.VAL 816 2112 1280 2112 1280 1760 1472 1760 egenSub.timeHealthCombine.INPA
w 712 1699 100 0 n#16 inhier.c#125.P -48 1696 1472 1696 egenSub.timeHealthCombine.INPB
s 1008 2384 200 0 in the MCS into a single overall time health
s 848 2448 200 0 This schematic combines all the individual time health records
s 2352 2576 100 0 $Id: mcTimeHealth.sch,v 1.5 2005/11/12 01:48:33 gemvx Exp $
s 2624 384 100 0 Combine MCS health records
s 2368 384 100 0 Gemini
s 2368 352 100 0 Observatory
s 96 448 100 0 Note these dummy records are in place to provide the correct
s 96 416 100 0 inputs to the gensub. If additional time health items need to be
s 96 384 100 0 added then the dummy records can be deleted and the real ones
s 96 352 100 0 added.
[cell use]
use bc200tr -224 104 -100 0 frame
xform 0 1456 1408
use inhier -64 1431 100 0 c#165
xform 0 -48 1472
use inhier -64 1879 100 0 SLNK
xform 0 -48 1920
use inhier -64 1655 100 0 c#125
xform 0 -48 1696
use outhier 2720 1831 100 0 FLNK
xform 0 2736 1872
use outhier 2720 1511 100 0 MESS
xform 0 2736 1552
use outhier 2720 1655 100 0 VAL
xform 0 2736 1696
use esirs 2048 1479 100 0 timeHealth
xform 0 2256 1632
p 2144 1792 100 0 -1 DESC:Overall time health
p 1984 1216 100 0 0 FDSC:Combined health of the time system
p 2160 1472 100 1024 0 name:$(top)timeHealth
use estringouts 416 999 100 0 timeDummyVal2
xform 0 544 1072
p 544 1088 100 0 0 DESC:Dummy health value
p 352 1038 100 0 0 VAL:GOOD
p 384 508 100 0 0 def(DOL):
use estringouts 416 1191 100 0 timeDummyVal1
xform 0 544 1264
p 544 1280 100 0 0 DESC:Dummy health value
p 352 1230 100 0 0 VAL:GOOD
p 384 700 100 0 0 def(DOL):
use estringouts 416 551 100 0 timeDummyMess2
xform 0 544 624
p 544 640 100 0 0 DESC:Empty message
p 352 590 100 0 0 VAL:
p 384 60 100 0 0 def(DOL):
use estringouts 416 775 100 0 timeDummyMess1
xform 0 544 848
p 544 864 100 0 0 DESC:Empty message
p 352 814 100 0 0 VAL:
p 384 284 100 0 0 def(DOL):
use mcHealthTStamp 176 1863 100 0 mcHealthTStamp#130
xform 0 480 2080
use egenSub 1472 999 100 0 timeHealthCombine
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
p 192 1728 100 0 -1 def(INPB):$(mc)TIME:health
p 256 1488 100 0 -1 def(INPF):$(mc)TIME:health.OMSS
p 1920 1776 100 0 0 def(OUTA):0.0
p 1760 1770 75 0 -1 pproc(OUTA):NPP
use hwinl 592 952 100 0 hwinl#168
xform 0 784 1000
p 602 1016 100 0 -1 val(in):$(top)timeDummyVal2.VAL
use hwinl 576 1128 100 0 hwinl#170
xform 0 768 1176
p 586 1192 100 0 -1 val(in):$(top)timeDummyVal1.VAL
use hwinl 592 728 100 0 hwinl#172
xform 0 784 776
p 602 792 100 0 -1 val(in):$(top)timeDummyMess1.VAL
use hwinl 592 504 100 0 hwinl#174
xform 0 784 552
p 602 568 100 0 -1 val(in):$(top)timeDummyMess2.VAL
[comments]
