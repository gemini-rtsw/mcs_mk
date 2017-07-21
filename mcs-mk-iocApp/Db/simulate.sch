[schematic2]
uniq 56
[tools]
[detail]
w 1640 427 100 0 n#54 efanouts.Fan.LNK2 1328 1120 1504 1120 1504 416 1824 416 egenSub.SimulateMode.SLNK
w 2192 395 100 0 n#53 egenSub.SimulateMode.FLNK 2112 384 2320 384 2320 832 2432 832 ebos.simMode.SLNK
w 2192 1067 100 0 n#52 egenSub.SimulateMode.VALB 2112 1056 2320 1056 2320 864 2432 864 ebos.simMode.DOL
w 2192 1099 100 0 c#49 egenSub.SimulateMode.OUTA 2112 1088 2320 1088 2320 1120 2496 1120 hwout.hwout#55.outp
w 1784 1451 100 0 n#48 efanouts.Fan.LNK1 1328 1152 1504 1152 1504 1440 2112 1440 eseqs.eseqs#1.SLNK
w 872 1723 100 0 n#45 ecad2.ecad2#0.STLK 832 1712 960 1712 960 1072 1088 1072 efanouts.Fan.SLNK
w 2024 1698 100 0 n#44 hwin.hwin#8.in 1984 1696 2112 1696 eseqs.eseqs#1.DOL3
w 1272 1739 100 0 n#43 ecad2.ecad2#0.VALA 832 2000 992 2000 992 1728 1600 1728 1600 1088 1824 1088 egenSub.SimulateMode.INPA
w 416 1906 100 0 n#39 hwin.hwin#38.in 368 1904 512 1904 ecad2.ecad2#0.INPB
w 2024 1764 100 0 n#34 hwin.hwin#2.in 1984 1760 2112 1760 eseqs.eseqs#1.DOL1
w 2536 1762 100 0 n#14 eseqs.eseqs#1.LNK1 2432 1760 2688 1760 hwout.hwout#13.outp
w 2488 1698 100 0 n#14 eseqs.eseqs#1.LNK3 2432 1696 2592 1696 2592 1760 junction
w 1000 2274 100 0 n#28 ecad2.ecad2#0.VAL 832 2192 896 2192 896 2272 1152 2272 engAck.engAck#22.INP
w 930 2048 100 0 n#24 ecad2.ecad2#0.FLNK 832 1840 928 1840 928 2208 1152 2208 engAck.engAck#22.SLNK
s 2768 256 100 0 MCS Level 3
s 2448 224 100 0 Andy Foster
s 2672 176 200 0 SIMULATE COMMAND
[cell use]
use hwout 2496 1079 100 0 hwout#55
xform 0 2592 1120
p 2576 1072 100 0 -1 val(outp):$(top)simLevelL PP NMS
use hwout 2712 1720 100 0 hwout#13
xform 0 2784 1760
p 2752 1806 100 0 -1 val(outp):$(top)softC.IVAL .PP
use ebos 2432 743 100 0 simMode
xform 0 2560 832
p 2496 928 100 0 -1 DESC:Simulation Mode
use egenSub 1824 327 100 0 SimulateMode
xform 0 1968 752
p 1872 1184 100 0 -1 DESC:Set Simulation Mode
p 1601 101 100 0 0 FTA:LONG
p 1601 101 100 0 0 FTB:LONG
p 1601 101 100 0 0 FTVA:LONG
p 1601 101 100 0 0 FTVB:LONG
p 1904 1008 100 0 1 FTVC:STRING
p 1856 272 100 0 1 INAM:mcInitSimMode
p 1856 176 100 0 1 PINI:YES
p 1856 224 100 0 1 SNAM:mcSimulationMode
p 2224 1136 100 0 -1 def(OUTA):$(top)simLevelL
p 2112 1098 75 0 -1 pproc(OUTA):PP
use efanouts 1088 935 100 0 Fan
xform 0 1208 1088
p 1200 928 100 1024 0 name:$(top)$(command)$(I)
use hwin 1816 1656 100 0 hwin#8
xform 0 1888 1696
p 1795 1688 100 0 -1 val(in):$(IDLE)
use hwin 1816 1720 100 0 hwin#2
xform 0 1888 1760
p 1795 1752 100 0 -1 val(in):$(BUSY)
use hwin 200 1864 100 0 hwin#38
xform 0 272 1904
p 112 1854 100 0 -1 val(in):$(top)debugLevelL
use engAck 1144 2072 100 0 engAck#22
xform 0 1344 2208
use eseqs 2136 1352 100 0 eseqs#1
xform 0 2272 1600
p 2224 1630 100 0 0 DLY2:0.0
p 2224 1534 100 0 1 DLY3:0.5
p 2224 1344 100 1024 -1 name:$(top)$(command)Seq
p 2448 1760 75 1024 -1 pproc(LNK1):NPP
p 2448 1728 75 1024 -1 pproc(LNK2):NPP
p 2448 1696 75 1024 -1 pproc(LNK3):NPP
use ecad2 536 1624 100 0 ecad2#0
xform 0 672 1936
p 608 1936 100 0 1 FTVA:LONG
p 608 1904 100 0 0 FTVB:STRING
p 608 1648 100 0 0 SNAM:simulateCAD
p 624 1616 100 1024 -1 name:$(top)simulate
use bc200tr -160 -24 -100 0 frame
xform 0 1520 1280
[comments]
