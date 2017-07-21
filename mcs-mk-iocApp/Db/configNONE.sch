[schematic2]
uniq 41
[tools]
[detail]
w 2024 2923 100 0 n#40 hwin.hwin#39.in 2016 2912 2080 2912 eseqs.eseqs#0.DOL5
w 2680 2923 100 0 n#38 eseqs.eseqs#0.LNK5 2400 2912 3008 2912 hwout.hwout#37.outp
w 2430 2891 100 0 n#2 eseqs.eseqs#0.LNK6 2400 2880 2496 2880 2496 3040 junction
w 3024 2683 100 0 n#36 efanouts.efanouts#34.LNK1 2896 2672 3200 2672 estringouts.estringouts#7.SLNK
w 2456 2955 100 0 n#35 eseqs.eseqs#0.LNK4 2400 2944 2560 2944 2560 2592 2656 2592 efanouts.efanouts#34.SLNK
w 3120 2715 100 0 c#30 inhier.CMD.P 3088 2704 3200 2704 estringouts.estringouts#7.DOL
w 1768 2987 100 0 c#22 inhier.HEADS.P 1504 2976 2080 2976 eseqs.eseqs#0.DOL3
w 1800 3019 100 0 c#21 inhier.ALGO.P 1568 3008 2080 3008 eseqs.eseqs#0.DOL2
w 1944 2891 100 0 n#20 hwin.hwin#4.in 1856 2880 2080 2880 eseqs.eseqs#0.DOL6
w 2542 3051 100 0 n#2 eseqs.eseqs#0.LNK1 2400 3040 2720 3040 hwout.hwout#1.outp
w 2536 2987 100 0 n#18 eseqs.eseqs#0.LNK3 2400 2976 2720 2976 hwout.hwout#16.outp
w 2680 3019 100 0 n#17 eseqs.eseqs#0.LNK2 2400 3008 3008 3008 hwout.hwout#15.outp
w 1880 2731 100 0 SLNK inhier.SLNK.P 1728 2720 2080 2720 eseqs.eseqs#0.SLNK
w 3512 2667 100 0 n#10 estringouts.estringouts#7.OUT 3456 2656 3616 2656 hwout.hwout#9.outp
w 1950 3051 100 0 n#5 hwin.hwin#3.in 1856 3040 2080 3040 eseqs.eseqs#0.DOL1
[cell use]
use hwin 1824 2871 100 0 hwin#39
xform 0 1920 2912
p 1827 2904 100 0 -1 val(in):0
use hwout 3008 2871 100 0 hwout#37
xform 0 3104 2912
p 3024 2864 100 0 -1 val(outp):$(top)$(dev)DatumL .PP
use efanouts 2656 2455 100 0 efanouts#34
xform 0 2776 2608
p 2768 2448 100 1024 -1 name:$(top)$(command)Fanout
p 2928 2672 75 1280 -1 pproc(LNK1):PP
use inhier 1712 2679 100 0 SLNK
xform 0 1728 2720
use inhier 1536 3040 100 0 ALGO
xform 0 1568 3008
use inhier 1488 2935 100 0 HEADS
xform 0 1504 2976
use inhier 3056 2736 100 0 CMD
xform 0 3088 2704
use estringouts 3200 2599 100 0 estringouts#7
xform 0 3328 2672
p 3264 2736 100 0 1 DTYP:PMAC-VME ASCII
p 3264 2768 100 0 1 OMSL:closed_loop
p 3312 2592 100 1024 -1 name:$(top)$(command)SendToPMAC
use hwin 1664 2839 100 0 hwin#4
xform 0 1760 2880
p 1667 2872 100 0 -1 val(in):$(IDLE)
use hwin 1664 2999 100 0 hwin#3
xform 0 1760 3040
p 1667 3032 100 0 -1 val(in):$(BUSY)
use hwout 3616 2615 100 0 hwout#9
xform 0 3712 2656
p 3696 2688 100 0 -1 val(outp):#C$(card) S1
use hwout 2720 2999 100 0 hwout#1
xform 0 2816 3040
p 2800 3088 100 0 -1 val(outp):$(top)softC.IVAL .PP
use hwout 3008 2967 100 0 hwout#15
xform 0 3104 3008
p 3072 3040 100 0 -1 val(outp):$(top)$(dev)VEalgorithmL .PP
use hwout 2720 2935 100 0 hwout#16
xform 0 2816 2976
p 2736 2928 100 0 -1 val(outp):$(top)$(dev)VEheadsL .PP
use eseqs 2080 2631 100 0 eseqs#0
xform 0 2240 2880
p 2176 3120 100 0 0 DLY3:0.0
p 2176 3120 100 0 0 DLY5:0.0
p 2192 3104 100 0 1 DLY6:0.25
p 2192 2624 100 1024 -1 name:$(top)$(command)Seq
p 2416 2944 75 1024 -1 pproc(LNK4):PP
use bc200tr 912 1432 -100 0 frame
xform 0 2592 2736
[comments]
