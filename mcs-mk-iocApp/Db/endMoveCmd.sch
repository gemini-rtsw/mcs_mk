[schematic2]
uniq 34
[tools]
[detail]
w 2984 2347 100 0 n#32 eseqs.eseqs#7.LNK1 2944 2336 3072 2336 hwout.hwout#31.outp
w 1784 2155 100 0 n#27 hwin.hwin#26.in 1728 2144 1888 2144 egenSub.egenSub#0.INPD
w 1784 2027 100 0 n#25 hwin.hwin#23.in 1728 2016 1888 2016 egenSub.egenSub#0.INPF
w 1784 2091 100 0 n#24 hwin.hwin#22.in 1728 2080 1888 2080 egenSub.egenSub#0.INPE
w 1784 2219 100 0 n#21 hwin.hwin#20.in 1728 2208 1888 2208 egenSub.egenSub#0.INPC
w 3032 2315 100 0 n#13 eseqs.eseqs#7.LNK2 2944 2304 3168 2304 3168 1984 3328 1984 carIdle.carIdle#10.SLNK
w 2382 2379 100 0 n#9 egenSub.egenSub#0.VALA 2176 2368 2624 2368 eseqs.eseqs#7.SELL
w 2270 1643 100 0 n#8 egenSub.egenSub#0.FLNK 2176 1632 2400 1632 2400 2016 2624 2016 eseqs.eseqs#7.SLNK
w 1790 2283 100 0 n#5 hwin.hwin#3.in 1728 2272 1888 2272 egenSub.egenSub#0.INPB
w 1790 2347 100 0 n#2 hwin.hwin#1.in 1728 2336 1888 2336 egenSub.egenSub#0.INPA
[cell use]
use carIdle 3328 1831 100 0 carIdle#10
xform 0 3552 1968
p 3456 1888 100 0 1 seta:command move
use hwout 3072 2295 100 0 hwout#31
xform 0 3168 2336
p 3072 2368 100 0 -1 val(outp):$(top)$(dev)CommandL .PP
use hwin 1536 2103 100 0 hwin#26
xform 0 1632 2144
p 1328 2144 100 0 -1 val(in):$(top)debugLevelL
use hwin 1536 2295 100 0 hwin#1
xform 0 1632 2336
p 1280 2336 100 0 -1 val(in):$(top)$(dev)CommandL
use hwin 1536 2231 100 0 hwin#3
xform 0 1632 2272
p 1280 2272 100 0 -1 val(in):$(top)$(dev)CommandL
use hwin 1536 2167 100 0 hwin#20
xform 0 1632 2208
p 1539 2200 100 0 -1 val(in):$(card)
use hwin 1536 2039 100 0 hwin#22
xform 0 1632 2080
p 1216 2064 100 0 -1 val(in):$(top)$(dev)motstat1:2:DVZ
use hwin 1536 1975 100 0 hwin#23
xform 0 1632 2016
p 1296 2000 100 0 -1 val(in):$(top)motstat2:2:IP
use eseqs 2624 1927 100 0 eseqs#7
xform 0 2784 2176
p 2736 2416 100 0 0 DLY3:0.0
p 2736 2384 100 0 1 SELM:Mask
p 2736 1920 100 1024 -1 name:$(top)$(dev)endMoveSeq
p 2960 2336 75 1024 -1 pproc(LNK1):PP
p 2960 2304 75 1024 -1 pproc(LNK2):PP
p 2960 2272 75 1024 -1 pproc(LNK3):PP
use egenSub 1888 1575 100 0 egenSub#0
xform 0 2032 2000
p 1968 2464 100 0 1 DISV:1
p 1984 2336 100 0 1 FTA:LONG
p 1984 2304 100 0 1 FTB:LONG
p 1984 2272 100 0 1 FTC:DOUBLE
p 1984 2240 100 0 1 FTD:LONG
p 1984 2208 100 0 1 FTE:LONG
p 1984 2176 100 0 1 FTF:LONG
p 1984 2144 100 0 0 FTG:DOUBLE
p 1984 2112 100 0 0 FTH:LONG
p 1984 1952 100 0 1 FTVA:LONG
p 1968 2496 100 0 1 SCAN:1 second
p 1968 2432 100 0 1 SNAM:endMove
p 2080 1840 100 1024 -1 name:$(top)$(dev)endMove
use bc200tr 976 568 -100 0 frame
xform 0 2656 1872
[comments]
