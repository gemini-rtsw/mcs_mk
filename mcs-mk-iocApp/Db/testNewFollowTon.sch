[schematic2]
uniq 20
[tools]
[detail]
w 2432 2315 100 0 n#18 efanouts.efanouts#15.LNK1 2336 2304 2576 2304 hwout.hwout#19.outp
w 1944 2795 100 0 n#16 eseqs.eseqs#9.LNK2 1920 2784 2016 2784 2016 2224 2096 2224 efanouts.efanouts#15.SLNK
w 2040 2827 100 0 n#14 eseqs.eseqs#9.LNK1 1920 2816 2208 2816 hwout.hwout#2.outp
w 2120 2507 100 0 FLNK eseqs.eseqs#9.FLNK 1920 2496 2368 2496 outhier.FLNK.p
w 1400 2507 100 0 SLNK inhier.SLNK.P 1248 2496 1600 2496 eseqs.eseqs#9.SLNK
w 1518 2827 100 0 n#3 hwin.hwin#0.in 1472 2816 1600 2816 eseqs.eseqs#9.DOL1
[cell use]
use hwout 2576 2263 100 0 hwout#19
xform 0 2672 2304
p 2640 2256 100 0 -1 val(outp):$(top)motionProgFO
use efanouts 2096 2087 100 0 efanouts#15
xform 0 2216 2240
p 2176 2384 100 0 1 SELM:All
p 2208 2080 100 1024 -1 name:$(top)$(command)TrackingOnFO
p 2368 2304 75 1280 -1 pproc(LNK1):PP
use eseqs 1600 2407 100 0 eseqs#9
xform 0 1760 2656
p 1712 2880 100 0 0 DLY2:0.0
p 1712 2864 100 0 1 DLY3:0.1
p 1712 2400 100 1024 -1 name:$(top)$(command)TrackingOn
p 1936 2784 75 1024 -1 pproc(LNK2):PP
use outhier 2336 2455 100 0 FLNK
xform 0 2352 2496
use inhier 1232 2455 100 0 SLNK
xform 0 1248 2496
use hwout 2208 2775 100 0 hwout#2
xform 0 2304 2816
p 2256 2752 100 0 -1 val(outp):$(top)FollowL .PP
use hwin 1280 2775 100 0 hwin#0
xform 0 1376 2816
p 1283 2808 100 0 -1 val(in):1
use bc200tr 352 1192 -100 0 frame
xform 0 2032 2496
[comments]
