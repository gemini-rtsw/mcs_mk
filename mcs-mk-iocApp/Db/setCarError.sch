[schematic2]
uniq 29
[tools]
[detail]
w 2632 3995 100 0 c#27 inhier.ERRSTR.P 2400 3984 2912 3984 egenSub.egenSub#22.INPA
w 3096 3083 100 0 n#24 egenSub.egenSub#22.FLNK 3200 3280 3744 3280 3744 3072 2496 3072 2496 2912 2912 2912 eaos.eaos#5.SLNK
w 3288 3995 100 0 n#23 egenSub.egenSub#22.OUTA 3200 3984 3424 3984 hwout.hwout#3.outp
w 3464 2539 100 0 FLNK eaos.eaos#15.FLNK 3168 2528 3808 2528 outhier.FLNK.p
w 3096 2667 100 0 n#19 eaos.eaos#5.FLNK 3168 2944 3744 2944 3744 2656 2496 2656 2496 2496 2912 2496 eaos.eaos#15.SLNK
w 3240 2475 100 0 n#14 eaos.eaos#15.OUT 3168 2464 3360 2464 hwout.hwout#17.outp
w 2830 2539 100 0 n#13 hwin.hwin#16.in 2784 2528 2912 2528 eaos.eaos#15.DOL
w 2632 3323 100 0 c#11 inhier.SLNK.P 2400 3312 2912 3312 egenSub.egenSub#22.SLNK
w 3240 2891 100 0 n#10 eaos.eaos#5.OUT 3168 2880 3360 2880 hwout.hwout#9.outp
w 2830 2955 100 0 n#8 hwin.hwin#7.in 2784 2944 2912 2944 eaos.eaos#5.DOL
[cell use]
use inhier 2384 3943 100 0 ERRSTR
xform 0 2400 3984
use hwin 2592 2487 100 0 hwin#16
xform 0 2688 2528
p 2595 2520 100 0 -1 val(in):0
use hwin 2592 2903 100 0 hwin#7
xform 0 2688 2944
p 2595 2936 100 0 -1 val(in):$(ERROR)
use egenSub 2912 3223 100 0 egenSub#22
xform 0 3056 3648
p 3008 3984 100 0 1 FTA:STRING
p 2992 3936 100 0 1 FTVA:STRING
p 2960 4080 100 0 1 SNAM:setErrorString1
p 3024 3216 100 1024 -1 name:$(top)$(dev)$(command)SetErrorString$(id)
use outhier 3776 2487 100 0 FLNK
xform 0 3792 2528
use hwout 3360 2423 100 0 hwout#17
xform 0 3456 2464
p 3424 2416 100 0 -1 val(outp):$(top)$(dev)CommandL .PP
use hwout 3360 2839 100 0 hwout#9
xform 0 3456 2880
p 3424 2832 100 0 -1 val(outp):$(top)$(dev)C.IVAL .PP
use hwout 3424 3943 100 0 hwout#3
xform 0 3520 3984
p 3488 3936 100 0 -1 val(outp):$(top)$(dev)C.IMSS
use eaos 2912 2407 100 0 eaos#15
xform 0 3040 2496
p 2656 2478 100 0 0 OMSL:closed_loop
p 3024 2400 100 1024 -1 name:$(top)$(dev)$(command)ErrorSetNull$(id)
use eaos 2912 2823 100 0 eaos#5
xform 0 3040 2912
p 2656 2894 100 0 0 OMSL:closed_loop
p 3024 2816 100 1024 -1 name:$(top)$(dev)$(command)SetError$(id)
use inhier 2384 3271 100 0 SLNK
xform 0 2400 3312
use bc200tr 1296 1672 -100 0 frame
xform 0 2976 2976
[comments]
