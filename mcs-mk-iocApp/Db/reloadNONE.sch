[schematic2]
uniq 57
[tools]
[detail]
w 2030 3595 100 0 n#2 eseqs.eseqs#0.LNK3 1984 3584 2112 3584 2112 3648 junction
w 2126 3659 100 0 n#2 eseqs.eseqs#0.LNK1 1984 3648 2304 3648 hwout.hwout#1.outp
w 2552 2507 100 0 n#56 eseqs.eseqs#0.LNK2 1984 3616 2176 3616 2176 2496 2976 2496 egenSub.egenSub#41.SLNK
w 2904 3115 100 0 n#48 hwin.hwin#47.in 2880 3104 2976 3104 egenSub.egenSub#41.INPB
w 2904 3179 100 0 n#46 hwin.hwin#45.in 2880 3168 2976 3168 egenSub.egenSub#41.INPA
w 2840 3051 100 0 ID inhier.ID.P 2752 3040 2976 3040 egenSub.egenSub#41.INPC
w 1528 3595 100 0 n#20 hwin.hwin#4.in 1440 3584 1664 3584 eseqs.eseqs#0.DOL3
w 1464 3339 100 0 SLNK inhier.SLNK.P 1312 3328 1664 3328 eseqs.eseqs#0.SLNK
w 1534 3659 100 0 n#5 hwin.hwin#3.in 1440 3648 1664 3648 eseqs.eseqs#0.DOL1
[cell use]
use inhier 1296 3287 100 0 SLNK
xform 0 1312 3328
use inhier 2736 2999 100 0 ID
xform 0 2752 3040
use hwin 2688 3063 100 0 hwin#47
xform 0 2784 3104
p 2432 3104 100 0 -1 val(in):$(top)pwdCommand.VALA
use hwin 2688 3127 100 0 hwin#45
xform 0 2784 3168
p 2480 3168 100 0 -1 val(in):$(top)debugLevelL
use hwin 1248 3543 100 0 hwin#4
xform 0 1344 3584
p 1251 3576 100 0 -1 val(in):$(IDLE)
use hwin 1248 3607 100 0 hwin#3
xform 0 1344 3648
p 1251 3640 100 0 -1 val(in):$(BUSY)
use egenSub 2976 2407 100 0 egenSub#41
xform 0 3120 2832
p 3056 3184 100 0 1 FTA:LONG
p 3056 3152 100 0 1 FTB:STRING
p 3056 3120 100 0 1 FTC:LONG
p 3040 3264 100 0 1 SNAM:loadPars
p 3088 2400 100 1024 -1 name:$(top)loadPars
use hwout 2304 3607 100 0 hwout#1
xform 0 2400 3648
p 2384 3696 100 0 -1 val(outp):$(top)softC.IVAL .PP
use eseqs 1664 3239 100 0 eseqs#0
xform 0 1824 3488
p 1776 3696 100 0 0 DLY2:0.0
p 1776 3680 100 0 1 DLY3:10.0
p 1760 3728 100 0 0 DLY5:0.0
p 1776 3712 100 0 0 DLY6:0.0
p 1776 3232 100 1024 -1 name:$(top)$(command)Seq
p 1632 3616 75 1280 -1 pproc(DOL2):NPP
p 2000 3616 75 1024 -1 pproc(LNK2):PP
p 2000 3584 75 1024 -1 pproc(LNK3):NPP
p 2000 3552 75 1024 -1 pproc(LNK4):NPP
use bc200tr 912 1432 -100 0 frame
xform 0 2592 2736
[comments]
