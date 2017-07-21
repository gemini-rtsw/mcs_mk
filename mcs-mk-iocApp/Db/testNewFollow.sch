[schematic2]
uniq 112
[tools]
[detail]
w 3682 3595 100 0 n#111 eaos.eaos#105.OUT 3680 3584 3744 3584 hwout.hwout#100.outp
w 3314 3563 100 0 n#109 ecalcs.ecalcs#99.FLNK 3264 3552 3424 3552 eaos.eaos#105.SLNK
w 3042 3819 100 0 n#104 ecalcs.ecalcs#99.VAL 3264 3520 3296 3520 3296 3808 2848 3808 2848 3712 2976 3712 ecalcs.ecalcs#99.INPA
w 3330 3531 100 0 n#104 junction 3296 3520 3424 3520 eaos.eaos#105.DOL
w 2642 2859 100 0 n#108 embbos.embbos#56.FLNK 2560 2848 2784 2848 2784 3328 2976 3328 ecalcs.ecalcs#99.SLNK
w 3640 2923 100 0 n#97 egenSub.egenSub#0.OUTA 3616 2912 3712 2912 hwout.hwout#1.outp
w 2616 3371 100 0 n#96 eaos.eaos#91.OUT 2560 3360 2720 3360 2720 2784 junction
w 2616 2315 100 0 n#96 eaos.eaos#93.OUT 2560 2304 2720 2304 2720 2784 2560 2784 embbos.embbos#56.VAL
w 1832 2091 100 0 n#95 trackingOff.trackingOff#54.FLNK 2080 1920 2112 1920 2112 2080 1600 2080 1600 2336 1632 2336 trackingOff.trackingOff#65.SLNK
w 2308 2363 100 2 n#94 eaos.eaos#93.DOL 2304 2368 2304 2368 hwin.hwin#81.in
w 2308 3419 100 2 n#92 eaos.eaos#91.DOL 2304 3424 2304 3424 hwin.hwin#77.in
w 2168 2347 100 0 n#83 trackingOff.trackingOff#65.FLNK 2080 2336 2304 2336 eaos.eaos#93.SLNK
w 2168 3403 100 0 n#79 testNewFollowTon.testNewFollowTon#98.FLNK 2080 3392 2304 3392 eaos.eaos#91.SLNK
w 3256 2955 100 0 n#74 embbos.embbos#9.OUT 3232 2944 3328 2944 egenSub.egenSub#0.A
w 1528 3403 100 0 n#73 ecad2.ecad2#18.FLNK 1472 3392 1632 3392 testNewFollowTon.testNewFollowTon#98.SLNK
w 1528 1931 100 0 n#70 ecad2.ecad2#43.FLNK 1472 1920 1632 1920 trackingOff.trackingOff#54.SLNK
w 2888 2827 100 0 n#58 embbos.embbos#56.OUT 2560 2816 3264 2816 3264 2880 3328 2880 egenSub.egenSub#0.B
[cell use]
use eaos 2304 2247 100 0 eaos#93
xform 0 2432 2336
p 2416 2240 100 1024 -1 name:$(top)testFollowEnbOff
p 2560 2304 75 768 -1 pproc(OUT):PP
use eaos 2304 3303 100 0 eaos#91
xform 0 2432 3392
p 2416 3296 100 1024 -1 name:$(top)testFollowEnbOn
p 2560 3360 75 768 -1 pproc(OUT):PP
use eaos 3424 3641 100 0 eaos#105
xform 6 3552 3552
p 3168 3570 100 0 0 OMSL:closed_loop
p 3552 3456 100 1024 -1 name:$(top)testFollowAo
p 3392 3520 75 1280 -1 pproc(DOL):NPP
p 3680 3584 75 768 -1 pproc(OUT):NPP
use hwout 3712 2871 100 0 hwout#1
xform 0 3808 2912
p 3776 2944 100 0 -1 val(outp):$(top)followA.J .PP
use hwout 3744 3543 100 0 hwout#100
xform 0 3840 3584
p 3808 3536 100 0 -1 val(outp):$(top)trackId
use ecalcs 2976 3239 100 0 ecalcs#99
xform 0 3120 3504
p 3088 3536 100 0 1 CALC:A+1
p 3120 3232 100 1024 -1 name:$(top)testFollowCalc
use testNewFollowTon 1632 3239 100 0 testNewFollowTon#98
xform 0 1856 3376
use hwin 2112 3383 100 0 hwin#77
xform 0 2208 3424
p 2144 3424 100 0 -1 val(in):1
use hwin 2112 2327 100 0 hwin#81
xform 0 2208 2368
p 2144 2368 100 0 -1 val(in):0
use trackingOff 1632 1767 100 0 trackingOff#54
xform 0 1856 1904
p 1728 1760 100 0 1 seta:card 0
p 1728 1728 100 0 1 setb:dev az
use trackingOff 1632 2183 100 0 trackingOff#65
xform 0 1856 2320
p 1728 2176 100 0 1 seta:card 1
p 1728 2144 100 0 1 setb:dev el
use embbos 2976 2855 100 0 embbos#9
xform 0 3104 2944
p 3040 3104 100 0 1 NOBT:1
p 3136 3040 100 0 1 ONST:CONTROLLED
p 3040 3040 100 0 1 ONVL:1
p 3136 3072 100 0 1 ZRST:CONTINUOUS
p 3040 3072 100 0 1 ZRVL:0
p 3088 2848 100 1024 -1 name:$(top)testFollowMode
use embbos 2304 2727 100 0 embbos#56
xform 0 2432 2816
p 2384 2976 100 0 1 NOBT:1
p 2480 2912 100 0 1 ONST:ENABLE
p 2384 2912 100 0 1 ONVL:1
p 2480 2944 100 0 1 ZRST:DISABLE
p 2384 2944 100 0 1 ZRVL:0
p 2448 2720 100 1024 -1 name:$(top)testFollowEnable
use ecad2 1152 1703 100 0 ecad2#43
xform 0 1312 2016
p 1312 1696 100 1024 -1 name:$(top)testFollowOff
use ecad2 1152 3175 100 0 ecad2#18
xform 0 1312 3488
p 1328 3168 100 1024 -1 name:$(top)testFollowOn
use bc200tr 832 1448 -100 0 frame
xform 0 2512 2752
use egenSub 3328 2151 100 0 egenSub#0
xform 0 3472 2576
p 3040 2590 100 0 0 EFLG:ALWAYS
p 3408 2912 100 0 1 FTA:DOUBLE
p 3408 2816 100 0 1 FTVA:DOUBLE
p 3408 2784 100 0 1 NOVA:5
p 3408 3072 100 0 1 PREC:14
p 3408 3040 100 0 1 SCAN:Passive
p 3408 3008 100 0 1 SNAM:testFollow
p 3440 2144 100 1024 -1 name:$(top)testFollowProc
[comments]
