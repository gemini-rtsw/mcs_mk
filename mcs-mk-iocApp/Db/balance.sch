[schematic2]
uniq 32
[tools]
[detail]
w 2824 1579 100 0 n#29 junction 2784 1776 2784 1568 2912 1568 eais.eais#31.INP
w 2824 2459 100 0 n#29 junction 2784 2256 2784 2448 2912 2448 eais.eais#30.INP
w 2776 2027 100 0 n#29 hwin.hwin#27.in 2688 2016 2912 2016 eais.eais#25.INP
w 2824 2267 100 0 n#29 junction 2784 2016 2784 2256 2912 2256 eais.eais#26.INP
w 2824 1787 100 0 n#29 junction 2784 2016 2784 1776 2912 1776 eais.eais#28.INP
w 2840 2699 100 0 n#22 junction 2816 2768 2816 2688 2912 2688 eais.eais#14.INP
w 2840 2939 100 0 n#22 hwin.hwin#10.in 2752 2768 2816 2768 2816 2928 2912 2928 eais.eais#9.INP
w 3288 2651 100 0 n#21 eais.eais#14.VAL 3168 2640 3456 2640 3456 2848 3616 2848 ecalcs.ecalcs#19.INPB
w 3368 2891 100 0 n#20 eais.eais#9.VAL 3168 2880 3616 2880 ecalcs.ecalcs#19.INPA
w 1678 2955 100 0 n#8 hwin.hwin#7.in 1632 2944 1760 2944 egenSub.egenSub#6.INPB
[cell use]
use eais 2912 1463 100 0 eais#31
xform 0 3040 1536
p 2976 1600 100 0 1 PREC:6
p 3024 1456 100 1024 -1 name:$(top)$(dev)TorqueMinusEnd
use eais 2912 2343 100 0 eais#30
xform 0 3040 2416
p 2976 2480 100 0 1 PREC:6
p 3056 2336 100 1024 -1 name:$(top)$(dev)TorquePlusEnd
use eais 2912 2583 100 0 eais#14
xform 0 3040 2656
p 2976 2720 100 0 1 PREC:6
p 3024 2576 100 1024 -1 name:$(top)$(dev)PinHighPos
use eais 2912 2823 100 0 eais#9
xform 0 3040 2896
p 2976 2960 100 0 1 PREC:6
p 3024 2816 100 1024 -1 name:$(top)$(dev)PinLowPos
use eais 2912 1911 100 0 eais#25
xform 0 3040 1984
p 2976 2048 100 0 1 PREC:6
p 3024 1904 100 1024 -1 name:$(top)$(dev)TorqueZero
use eais 2912 2151 100 0 eais#26
xform 0 3040 2224
p 2976 2288 100 0 1 PREC:6
p 3024 2144 100 1024 -1 name:$(top)$(dev)TorquePlus
use eais 2912 1671 100 0 eais#28
xform 0 3040 1744
p 2976 1808 100 0 1 PREC:6
p 3024 1664 100 1024 -1 name:$(top)$(dev)TorqueMinus
use hwin 2560 2727 100 0 hwin#10
xform 0 2656 2768
p 2544 2800 100 0 -1 val(in):$(top)$(dev)CurrentPos
use hwin 1440 2903 100 0 hwin#7
xform 0 1536 2944
p 1443 2936 100 0 -1 val(in):$(card)
use hwin 2496 1975 100 0 hwin#27
xform 0 2592 2016
p 2480 2048 100 0 -1 val(in):$(top)$(dev)Torque.VALA
use ecalcs 3616 2407 100 0 ecalcs#19
xform 0 3760 2672
p 3648 2928 100 0 1 CALC:(A+B)/2.0
p 3648 2960 100 0 1 PREC:6
p 3728 2400 100 1024 -1 name:$(top)$(dev)PinMiddlePos
use egenSub 1760 2247 100 0 egenSub#6
xform 0 1904 2672
p 1840 3024 100 0 1 FTA:DOUBLE
p 1840 2960 100 0 1 FTB:DOUBLE
p 1840 2464 100 0 1 FTJ:STRING
p 1840 2992 100 0 1 PREC:6
p 1808 3104 100 0 1 SNAM:speedControl
p 1872 2240 100 1024 -1 name:$(top)$(dev)SpeedControl
use bc200tr 1248 712 -100 0 frame
xform 0 2928 2016
[comments]
