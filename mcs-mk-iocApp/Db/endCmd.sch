[schematic2]
uniq 34
[tools]
[detail]
w 3208 1707 100 0 n#33 eseqs.eseqs#7.LNK3 2784 2304 2944 2304 2944 1696 3520 1696 eaos.eaos#28.SLNK
w 3816 1675 100 0 n#32 eaos.eaos#28.OUT 3776 1664 3904 1664 hwout.hwout#31.outp
w 3448 1739 100 0 n#30 hwin.hwin#29.in 3424 1728 3520 1728 eaos.eaos#28.DOL
w 1624 1931 100 0 n#27 hwin.hwin#26.in 1568 1920 1728 1920 egenSub.egenSub#0.INPH
w 1624 2059 100 0 n#25 hwin.hwin#23.in 1568 2048 1728 2048 egenSub.egenSub#0.INPF
w 1624 2123 100 0 n#24 hwin.hwin#22.in 1568 2112 1728 2112 egenSub.egenSub#0.INPE
w 1624 1995 100 0 n#21 hwin.hwin#20.in 1568 1984 1728 1984 egenSub.egenSub#0.INPG
w 2872 2347 100 0 n#13 eseqs.eseqs#7.LNK2 2784 2336 3008 2336 3008 2016 3168 2016 carError.carError#11.SLNK
w 2952 2379 100 0 n#12 eseqs.eseqs#7.LNK1 2784 2368 3168 2368 carIdle.carIdle#10.SLNK
w 2222 2411 100 0 n#9 egenSub.egenSub#0.VALA 2016 2400 2464 2400 eseqs.eseqs#7.SELL
w 2110 1675 100 0 n#8 egenSub.egenSub#0.FLNK 2016 1664 2240 1664 2240 2048 2464 2048 eseqs.eseqs#7.SLNK
w 1630 2251 100 0 n#6 hwin.hwin#4.in 1568 2240 1728 2240 egenSub.egenSub#0.INPC
w 1630 2315 100 0 n#5 hwin.hwin#3.in 1568 2304 1728 2304 egenSub.egenSub#0.INPB
w 1630 2379 100 0 n#2 hwin.hwin#1.in 1568 2368 1728 2368 egenSub.egenSub#0.INPA
[cell use]
use hwout 3904 1623 100 0 hwout#31
xform 0 4000 1664
p 3904 1696 100 0 -1 val(outp):$(top)azEstop.PROC .PP
use hwin 3232 1687 100 0 hwin#29
xform 0 3328 1728
p 3235 1720 100 0 -1 val(in):1
use eaos 3520 1607 100 0 eaos#28
xform 0 3648 1696
p 3568 1792 100 0 1 OMSL:closed_loop
p 3632 1600 100 1024 -1 name:$(top)$(dev)applyBrakes
use hwin 1376 2007 100 0 hwin#23
xform 0 1472 2048
p 1168 2048 100 0 -1 val(in):$(top)stop.VALC
use hwin 1376 2071 100 0 hwin#22
xform 0 1472 2112
p 1168 2112 100 0 -1 val(in):$(top)stop.VALB
use hwin 1376 1943 100 0 hwin#20
xform 0 1472 1984
p 1379 1976 100 0 -1 val(in):$(card)
use hwin 1376 2199 100 0 hwin#4
xform 0 1472 2240
p 1120 2240 100 0 -1 val(in):$(top)$(dev)StateL
use hwin 1376 2263 100 0 hwin#3
xform 0 1472 2304
p 1120 2304 100 0 -1 val(in):$(top)$(dev)C
use hwin 1376 2327 100 0 hwin#1
xform 0 1472 2368
p 1120 2368 100 0 -1 val(in):$(top)$(dev)CommandL
use hwin 1376 1879 100 0 hwin#26
xform 0 1472 1920
p 1168 1920 100 0 -1 val(in):$(top)debugLevelL
use carError 3168 1863 100 0 carError#11
xform 0 3392 2000
p 3328 1952 100 0 1 seta:errno 1
p 3328 1920 100 0 1 setb:id 2
use carIdle 3168 2215 100 0 carIdle#10
xform 0 3392 2352
use eseqs 2464 1959 100 0 eseqs#7
xform 0 2624 2208
p 2576 2448 100 0 0 DLY3:0.0
p 2576 2416 100 0 1 SELM:Mask
p 2576 1952 100 1024 -1 name:$(top)$(dev)endSeq
p 2800 2368 75 1024 -1 pproc(LNK1):PP
p 2800 2336 75 1024 -1 pproc(LNK2):PP
p 2800 2304 75 1024 -1 pproc(LNK3):PP
use egenSub 1728 1607 100 0 egenSub#0
xform 0 1872 2032
p 1808 2496 100 0 1 DISV:1
p 1824 2368 100 0 1 FTA:LONG
p 1824 2336 100 0 1 FTB:LONG
p 1824 2304 100 0 1 FTC:LONG
p 1824 2272 100 0 1 FTD:LONG
p 1824 2240 100 0 1 FTE:LONG
p 1824 2208 100 0 1 FTF:LONG
p 1824 2176 100 0 1 FTG:DOUBLE
p 1824 2144 100 0 1 FTH:LONG
p 1824 1984 100 0 1 FTVA:LONG
p 1808 2528 100 0 1 SCAN:1 second
p 1808 2464 100 0 1 SNAM:endCommand
p 1840 1600 100 1024 -1 name:$(top)$(dev)endCommand
use bc200tr 976 568 -100 0 frame
xform 0 2656 1872
[comments]
