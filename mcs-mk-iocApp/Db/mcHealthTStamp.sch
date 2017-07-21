[schematic2]
uniq 19
[tools]
[detail]
w 656 2035 100 0 n#1 efanouts.fan.LNK2 592 2032 720 2032 720 1872 800 1872 estringouts.bad.SLNK
w 1232 1267 100 0 n#2 inhier.c#150.P 752 1264 1744 1264 1744 1664 1856 1664 egenSub.setTStampHealth.INPC
w 2192 1731 100 0 n#3 egenSub.setTStampHealth.OUTB 2144 1728 2240 1728 2240 1792 2368 1792 esirs.tstampHealth.IMSS
w 2816 1827 100 0 n#4 esirs.tstampHealth.FLNK 2784 1824 2848 1824 2848 1488 2976 1488 outhier.FLNK.p
w 1568 1539 100 0 n#5 estringouts.dtHealth.FLNK 1504 1536 1720 1536 1720 1120 1856 1120 egenSub.setTStampHealth.SLNK
w -8 1331 100 0 n#6 inhier.SLNK.P -48 1328 32 1328 32 1600 -96 1600 -96 1760 -32 1760 ecalcs.incr.SLNK
w 2832 1763 100 0 n#7 esirs.tstampHealth.OMSS 2784 1760 2880 1760 2880 1680 2976 1680 outhier.MESS.p
w 2832 1795 100 0 n#8 esirs.tstampHealth.VAL 2784 1792 2880 1792 2880 1872 2976 1872 outhier.VAL.p
w 2256 1827 100 0 n#9 egenSub.setTStampHealth.VALA 2144 1824 2368 1824 esirs.tstampHealth.INP
w 2208 1091 100 0 n#10 egenSub.setTStampHealth.FLNK 2144 1088 2272 1088 2272 1664 2368 1664 esirs.tstampHealth.SLNK
w 640 2099 100 0 n#11 efanouts.fan.FLNK 592 2096 688 2096 688 1520 1248 1520 estringouts.dtHealth.SLNK
w 1680 1467 100 0 n#12 hwinm.hwinm#153.in 1712 1472 1776 1472 1776 1728 1856 1728 egenSub.setTStampHealth.INPB
w 1000 1555 100 0 n#13 inhier.c#125.P 752 1552 1248 1552 estringouts.dtHealth.DOL
w 1104 2147 100 0 n#14 estringouts.good.OUT 1056 2144 1152 2144 1152 2000 1248 2000 estringouts.progHealth.SLNK
w 1104 1859 100 0 n#14 estringouts.bad.OUT 1056 1856 1152 1856 1152 2000 junction
w 656 2067 100 0 n#15 efanouts.fan.LNK1 592 2064 720 2064 720 2160 800 2160 estringouts.good.SLNK
w 280 1955 100 0 n#16 ecalcs.incr.VAL 256 1952 304 1952 304 2064 400 2064 efanouts.fan.SELL
w 304 1987 100 0 n#17 ecalcs.incr.FLNK 256 1984 352 1984 efanouts.fan.SLNK
w 1732 1955 100 0 n#18 hwinm.hwinm#151.in 1704 1952 1760 1952 1760 1792 1856 1792 egenSub.setTStampHealth.INPA
s 2368 384 100 0 Copyright
s 2368 352 100 0 Observatory
s 2368 320 100 0 Sciences Ltd.
s 2624 384 100 0 Combine CRCS health records
s 2352 2576 100 0 $Id: mcHealthTStamp.sch,v 1.4 2002/10/01 16:08:16 gemvx Exp $
s 1024 2448 200 0 This schematic generates the health of the
s 1184 2384 200 0 time stamping system
[cell use]
use bc200tr -224 104 -100 0 frame
xform 0 1456 1408
use inhier 736 1223 100 0 c#150
xform 0 752 1264
use inhier -64 1287 100 0 SLNK
xform 0 -48 1328
use inhier 736 1511 100 0 c#125
xform 0 752 1552
use outhier 2944 1447 100 0 FLNK
xform 0 2960 1488
use outhier 2944 1831 100 0 VAL
xform 0 2960 1872
use outhier 2944 1639 100 0 MESS
xform 0 2960 1680
use esirs 2368 1575 100 0 tstampHealth
xform 0 2576 1728
p 2416 1872 100 0 -1 DESC:Health of timestamping system
p 2304 1376 100 0 0 EGU:none
p 2304 1312 100 0 0 FDSC:Health of time stampintg system
p 2480 1632 100 0 1 SNAM:mcHealthSIR
use estringouts 1248 1447 100 0 dtHealth
xform 0 1376 1520
p 1312 1584 100 0 -1 DESC:Time difference health
p 1184 1326 100 0 0 OMSL:closed_loop
p 1424 1424 100 0 0 VAL:GOOD
p 864 1568 100 0 -1 def(DOL):$(mc)capturedPos.VALI
use estringouts 800 2087 100 0 good
xform 0 928 2160
p 864 2224 100 0 -1 DESC:Good health
p 976 2064 100 0 1 VAL:GOOD
p 1056 2144 75 768 -1 pproc(OUT):PP
use estringouts 800 1799 100 0 bad
xform 0 928 1872
p 864 1936 100 0 -1 DESC:Bad health
p 976 1776 100 0 1 VAL:BAD
p 1056 1856 75 768 -1 pproc(OUT):PP
use estringouts 1248 1927 100 0 progHealth
xform 0 1376 2000
p 1312 2064 100 0 -1 DESC:Program running health
p 1424 1904 100 0 0 VAL:GOOD
use egenSub 1856 1031 100 0 setTStampHealth
xform 0 2000 1456
p 1888 1904 100 0 -1 DESC:Combine health values
p 1633 805 100 0 0 FTA:STRING
p 1633 805 100 0 0 FTB:STRING
p 1633 773 100 0 0 FTC:STRING
p 1633 805 100 0 0 FTVA:STRING
p 1633 805 100 0 0 FTVB:STRING
p 1633 773 100 0 0 FTVC:STRING
p 2080 960 100 0 0 SCAN:Passive
p 2080 1008 100 0 1 SNAM:mcTstampHealth
p 1360 1744 100 0 0 def(INPB):0.0
p 864 1296 100 0 -1 def(INPC):$(mc)capturedPos.VALJ
p 2304 1808 100 0 0 def(OUTA):0.0
p 2144 1802 75 0 -1 pproc(OUTA):NPP
p 2144 1738 75 0 -1 pproc(OUTB):NPP
use efanouts 352 1847 100 0 fan
xform 0 472 2000
p 448 2160 100 0 -1 DESC:Select health value
p 208 1966 100 0 0 SELM:Specified
use ecalcs -32 1671 100 0 incr
xform 0 112 1936
p 48 1840 100 0 1 CALC:A+1
p -80 2208 100 0 -1 DESC:Increment time stamp status
p 112 1712 100 0 0 SCAN:Passive
p -320 1982 100 0 0 def(INPA):$(mc)azmotstat1:1:OLM
use hwinm 1424 1880 100 0 hwinm#151
xform 0 1568 1928
p 1426 1944 100 0 -1 val(in):$(top)progHealth.VAL
use hwinm 1424 1400 100 0 hwinm#153
xform 0 1568 1448
p 1426 1464 100 0 -1 val(in):$(top)dtHealth.VAL
[comments]
