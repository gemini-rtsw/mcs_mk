[schematic2]
uniq 8
[tools]
[detail]
w 2244 1437 100 0 n#1 eaos.eaos#0.FLNK 2208 1432 2280 1432 2280 1792 2432 1792 esubs.esubs#27.SLNK
w 1808 2627 100 0 n#2 efanouts.efanouts#55.LNK4 1760 2624 1856 2624 1856 1400 1952 1400 eaos.eaos#0.SLNK
w 1408 2643 100 0 c inhier.SLNK.P 1296 2640 1520 2640 efanouts.efanouts#55.SLNK
w 1840 2659 100 0 n#3 efanouts.efanouts#55.LNK3 1760 2656 1920 2656 1920 2400 2432 2400 estringouts.estringouts#42.SLNK
w 1928 2691 100 0 n#4 efanouts.efanouts#55.LNK2 1760 2688 2096 2688 2096 2720 2432 2720 estringouts.estringouts#37.SLNK
w 2200 2579 100 0 n#5 hwin.hwin#38.in 2160 2576 2240 2576 2240 2752 2432 2752 estringouts.estringouts#37.DOL
w 2243 2504 100 0 n#5 junction 2240 2576 2240 2432 2432 2432 estringouts.estringouts#42.DOL
w 2784 2387 100 0 n#6 estringouts.estringouts#42.OUT 2688 2384 2880 2384 hwout.hwout#43.outp
w 2784 2707 100 0 n#7 estringouts.estringouts#37.OUT 2688 2704 2880 2704 hwout.hwout#40.outp
w 1392 1541 100 0 c inhier.TIME.P 1312 1536 1472 1536 1472 2720 1568 2720 efanouts.efanouts#55.SELL
[cell use]
use bc200tr 1072 888 -100 0 frame
xform 0 2752 2192
use inhier 1296 1495 100 0 TIME
xform 0 1312 1536
use inhier 1280 2599 100 0 SLNK
xform 0 1296 2640
use efanouts 1520 2503 100 0 efanouts#55
xform 0 1640 2656
p 1616 2816 100 0 1 SELM:Mask
p 1632 2496 100 1024 -1 name:$(top)TimeInterruptFO
p 1792 2720 75 1280 -1 pproc(LNK1):PP
p 1792 2688 75 1280 -1 pproc(LNK2):PP
p 1792 2656 75 1280 -1 pproc(LNK3):PP
use hwin 1968 2535 100 0 hwin#38
xform 0 2064 2576
p 1968 2608 100 0 -1 val(in):$(top)PmacCmd_Run
use hwout 2880 2663 100 0 hwout#40
xform 0 2976 2704
p 2976 2695 100 0 -1 val(outp):#C0 S1
use hwout 2880 2343 100 0 hwout#43
xform 0 2976 2384
p 2976 2375 100 0 -1 val(outp):#C1 S1
use estringouts 2432 2647 100 0 estringouts#37
xform 0 2560 2720
p 2496 2832 100 0 1 DTYP:PMAC-VME ASCII
p 2496 2800 100 0 1 OMSL:closed_loop
p 2368 2686 100 0 0 VAL:
p 2544 2640 100 1024 -1 name:$(top)azPMAC_RunS
use estringouts 2432 2327 100 0 estringouts#42
xform 0 2560 2400
p 2496 2512 100 0 1 DTYP:PMAC-VME ASCII
p 2496 2480 100 0 1 OMSL:closed_loop
p 2368 2366 100 0 0 VAL:
p 2544 2320 100 1024 -1 name:$(top)elPMAC_RunS
use esubs 2432 1703 100 0 esubs#27
xform 0 2576 1968
p 2144 1822 100 0 0 INAM:nullSub
p 2480 2224 100 0 1 SNAM:readTime
p 2544 1696 100 1024 -1 name:$(top)readTime
use eaos 1952 1311 100 0 eaos#0
xform 0 2080 1400
p 2016 1496 100 0 1 DTYP:Soft Channel
p 2016 1528 100 0 1 OMSL:closed_loop
p 2016 1560 100 0 1 PREC:12
p 2064 1304 100 1024 -1 name:$(top)TODinterrupt
p 1696 1510 100 0 1 SCAN:Passive
[comments]
