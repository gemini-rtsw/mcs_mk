[schematic2]
uniq 11
[tools]
[detail]
w 2840 3115 100 0 n#10 esirs.esirs#5.FLNK 2752 3264 2816 3264 2816 3104 2912 3104 esirs.esirs#6.SLNK
w 2782 3243 100 0 n#9 esirs.esirs#5.VAL 2752 3232 2848 3232 2848 3264 2912 3264 esirs.esirs#6.INP
w 2254 3115 100 0 n#8 ecalcs.ecalcs#0.FLNK 2112 3296 2208 3296 2208 3104 2336 3104 esirs.esirs#5.SLNK
w 2206 3275 100 0 n#7 ecalcs.ecalcs#0.VAL 2112 3264 2336 3264 esirs.esirs#5.INP
w 1726 3435 100 0 n#4 hwin.hwin#2.in 1600 3392 1664 3392 1664 3424 1824 3424 ecalcs.ecalcs#0.INPB
w 1694 3467 100 0 n#3 hwin.hwin#1.in 1600 3456 1824 3456 ecalcs.ecalcs#0.INPA
[cell use]
use esirs 2336 3015 100 0 esirs#5
xform 0 2544 3168
p 2480 3152 100 0 1 FTVL:LONG
p 2448 3008 100 1024 -1 name:$(top)mcDatumL
use esirs 2912 3015 100 0 esirs#6
xform 0 3120 3168
p 3056 3152 100 0 1 FTVL:STRING
p 3056 3120 100 0 1 SNAM:datumSIR
p 3024 3008 100 1024 -1 name:$(top)mcDatumS
use hwin 1408 3415 100 0 hwin#1
xform 0 1504 3456
p 1216 3456 100 0 -1 val(in):$(top)azDatumL
use hwin 1408 3351 100 0 hwin#2
xform 0 1504 3392
p 1216 3392 100 0 -1 val(in):$(top)elDatumL
use ecalcs 1824 2983 100 0 ecalcs#0
xform 0 1968 3248
p 1824 3504 100 0 1 CALC:((A=1)&&(B=1))?1:0
p 1824 3536 100 0 1 SCAN:1 second
p 1936 2976 100 1024 -1 name:$(top)datumCalc
use bc200tr 864 1272 -100 0 frame
xform 0 2544 2576
[comments]
