[schematic2]
uniq 316
[tools]
[detail]
w 2898 3051 100 0 n#314 egenSub.egenSub#0.OUTB 2848 3040 3008 3040 hwout.hwout#315.outp
w 4580 3099 100 2 n#313 hwin.hwin#312.in 4576 3104 4576 3104 egenSub.egenSub#310.INPA
w 4658 2315 100 0 n#311 carIdle.carIdle#216.FLNK 4896 1536 4928 1536 4928 2304 4448 2304 4448 2432 4576 2432 egenSub.egenSub#310.SLNK
w 4434 1771 100 0 n#309 eseqs.eseqs#271.LNK3 4512 2144 4608 2144 4608 1760 4320 1760 4320 1248 4448 1248 carError.carError#308.SLNK
w 4498 1707 100 0 n#307 eseqs.eseqs#271.LNK2 4512 2176 4672 2176 4672 1696 4384 1696 4384 1536 4448 1536 carIdle.carIdle#216.SLNK
w 3570 1739 100 0 n#306 hwin.hwin#305.in 3520 1728 3680 1728 egenSubD.egenSubD#285.INPP
w 3330 1771 100 0 n#304 hwin.hwin#303.in 3040 1760 3680 1760 egenSubD.egenSubD#285.INPO
w 2994 2059 100 0 n#302 eais.eais#301.VAL 2368 2048 3680 2048 egenSubD.egenSubD#285.INPF
w 3570 1803 100 0 n#300 hwin.hwin#299.in 3520 1792 3680 1792 egenSubD.egenSubD#285.INPN
w 3330 1835 100 0 n#298 hwin.hwin#297.in 3040 1824 3680 1824 egenSubD.egenSubD#285.INPM
w 3570 1867 100 0 n#296 hwin.hwin#295.in 3520 1856 3680 1856 egenSubD.egenSubD#285.INPL
w 3330 2091 100 0 n#292 hwin.hwin#278.in 3040 2080 3680 2080 egenSubD.egenSubD#285.INPE
w 3570 2123 100 0 n#291 hwin.hwin#259.in 3520 2112 3680 2112 egenSubD.egenSubD#285.INPD
w 3330 2155 100 0 n#290 hwin.hwin#229.in 3040 2144 3680 2144 egenSubD.egenSubD#285.INPC
w 3570 2187 100 0 n#289 hwin.hwin#268.in 3520 2176 3680 2176 egenSubD.egenSubD#285.INPB
w 4098 2219 100 0 n#288 egenSubD.egenSubD#285.VALB 3968 2144 4064 2144 4064 2208 4192 2208 eseqs.eseqs#271.DOL1
w 4082 2251 100 0 n#287 egenSubD.egenSubD#285.VALA 3968 2208 4032 2208 4032 2240 4192 2240 eseqs.eseqs#271.SELL
w 4002 1483 100 0 n#286 egenSubD.egenSubD#285.FLNK 3968 1472 4096 1472 4096 1888 4192 1888 eseqs.eseqs#271.SLNK
w 2482 2859 100 0 n#282 hwin.hwin#281.in 2464 2848 2560 2848 egenSub.egenSub#0.INPE
w 4562 2219 100 0 n#274 eseqs.eseqs#271.LNK1 4512 2208 4672 2208 hwout.hwout#255.outp
w 3106 3147 100 0 n#270 egenSub.egenSub#0.VALA 2848 3136 3424 3136 3424 2208 3680 2208 egenSubD.egenSubD#285.INPA
w 2482 2923 100 0 n#254 hwin.hwin#253.in 2464 2912 2560 2912 egenSub.egenSub#0.INPD
w 2482 2987 100 0 n#244 hwin.hwin#243.in 2464 2976 2560 2976 egenSub.egenSub#0.INPC
w 2482 3051 100 0 n#241 hwin.hwin#242.in 2464 3040 2560 3040 egenSub.egenSub#0.INPB
w 2482 3115 100 0 n#231 hwin.hwin#232.in 2464 3104 2560 3104 egenSub.egenSub#0.INPA
w 2402 2443 100 0 SLNK inhier.SLNK.P 2304 2432 2560 2432 egenSub.egenSub#0.SLNK
s 2976 3168 200 0 DIRECTION OF HOMING MOVE
[cell use]
use hwout 3008 2999 100 0 hwout#315
xform 0 3104 3040
p 2976 3072 100 0 -1 val(outp):$(top)$(dev)DatumL .PP
use hwin 2848 1719 100 0 hwin#303
xform 0 2944 1760
p 2544 1760 100 0 -1 val(in):$(top)$(dev)RefMarkWidth
use hwin 2848 1783 100 0 hwin#297
xform 0 2944 1824
p 2544 1824 100 0 -1 val(in):$(top)$(dev)FirstRefCnts
use hwin 2272 2807 100 0 hwin#281
xform 0 2368 2848
p 2000 2848 100 0 -1 val(in):$(top)$(dev)DatumMechL
use hwin 3328 2135 100 0 hwin#268
xform 0 3424 2176
p 3072 2176 100 0 -1 val(in):$(top)$(dev)CommandL
use hwin 2272 3063 100 0 hwin#232
xform 0 2368 3104
p 2275 3096 100 0 -1 val(in):$(card)
use hwin 2848 2103 100 0 hwin#229
xform 0 2944 2144
p 2752 2144 100 0 -1 val(in):$(card)
use hwin 2272 2999 100 0 hwin#242
xform 0 2368 3040
p 2064 3040 100 0 -1 val(in):$(top)TiltSwitch
use hwin 2272 2935 100 0 hwin#243
xform 0 2368 2976
p 2128 2976 100 0 -1 val(in):$(top)wrapL
use hwin 2272 2871 100 0 hwin#253
xform 0 2368 2912
p 2000 2912 100 0 -1 val(in):$(top)$(dev)CurrentPos
use hwin 3328 2071 100 0 hwin#259
xform 0 3424 2112
p 3104 2112 100 0 -1 val(in):$(top)debugLevelL
use hwin 2848 2039 100 0 hwin#278
xform 0 2944 2080
p 2576 2080 100 0 -1 val(in):$(top)$(dev)DatumMechL
use hwin 3328 1815 100 0 hwin#295
xform 0 3424 1856
p 3040 1856 100 0 -1 val(in):$(top)$(dev)PitchesToEC
use hwin 3328 1751 100 0 hwin#299
xform 0 3424 1792
p 3120 1776 100 0 -1 val(in):$(top)OuterTopple
use hwin 3328 1687 100 0 hwin#305
xform 0 3424 1728
p 2992 1728 100 0 -1 val(in):$(top)$(dev)CountsPerDegree
use hwin 4384 3063 100 0 hwin#312
xform 0 4480 3104
p 4288 3088 100 0 -1 val(in):$(card)
use egenSub 2560 2343 100 0 egenSub#0
xform 0 2704 2768
p 2656 3104 100 0 1 FTA:DOUBLE
p 2656 3072 100 0 1 FTB:LONG
p 2656 3040 100 0 1 FTC:LONG
p 2656 3008 100 0 1 FTD:DOUBLE
p 2656 2976 100 0 1 FTE:LONG
p 2640 2720 100 0 1 FTVA:DOUBLE
p 2624 3200 100 0 1 SNAM:startDatumH
p 2672 2336 100 1024 -1 name:$(top)$(dev)startDatumH
use egenSub 4576 2343 100 0 egenSub#310
xform 0 4720 2768
p 4640 2848 100 0 1 SNAM:closeLoop
p 4720 2336 100 1024 -1 name:$(top)$(dev)closeLoopHead
use carError 4448 1095 100 0 carError#308
xform 0 4672 1232
p 4240 1184 100 0 1 seta:command datumH
p 4240 1152 100 0 1 setb:id 0
p 4240 1120 100 0 1 setc:errno 4
use eais 2112 1991 100 0 eais#301
xform 0 2240 2064
p 2176 2128 100 0 1 PREC:6
p 2224 1984 100 1024 -1 name:$(top)$(dev)OuterTopplePos
use egenSubD 3680 1415 100 0 egenSubD#285
xform 0 3824 1840
p 3760 2192 100 0 1 FTA:DOUBLE
p 3760 2160 100 0 1 FTB:LONG
p 3760 2128 100 0 1 FTC:DOUBLE
p 3760 2096 100 0 1 FTD:LONG
p 3760 2064 100 0 1 FTE:LONG
p 3760 2032 100 0 1 FTF:DOUBLE
p 3760 2000 100 0 1 FTG:DOUBLE
p 3760 1936 100 0 1 FTH:DOUBLE
p 3760 1824 100 0 1 FTI:DOUBLE
p 3760 1760 100 0 1 FTK:DOUBLE
p 3760 1696 100 0 1 FTL:DOUBLE
p 3760 1664 100 0 1 FTM:DOUBLE
p 3760 1600 100 0 1 FTN:LONG
p 3760 1568 100 0 1 FTO:DOUBLE
p 3760 1536 100 0 1 FTP:DOUBLE
p 3760 1504 100 0 1 FTVA:LONG
p 3760 1472 100 0 1 FTVB:LONG
p 3760 1968 100 0 1 NOG:11
p 3760 1904 100 0 1 NOH:11
p 3760 1792 100 0 1 NOI:11
p 3760 1728 100 0 1 NOK:11
p 3760 1632 100 0 1 NOM:4
p 3760 2304 100 0 1 SCAN:5 second
p 3760 2272 100 0 1 SNAM:endDatumH
p 3792 1408 100 1024 -1 name:$(top)$(dev)endDatumH
use eseqs 4192 1799 100 0 eseqs#271
xform 0 4352 2048
p 4304 2272 100 0 1 SELM:Mask
p 4304 1792 100 1024 -1 name:$(top)$(dev)endDatumSeqH
p 4528 2176 75 1024 -1 pproc(LNK2):PP
p 4528 2144 75 1024 -1 pproc(LNK3):PP
use hwout 4672 2167 100 0 hwout#255
xform 0 4768 2208
p 4640 2240 100 0 -1 val(outp):$(top)$(dev)DatumL .PP
use inhier 2288 2391 100 0 SLNK
xform 0 2304 2432
use carIdle 4448 1383 100 0 carIdle#216
xform 0 4672 1520
p 4560 1456 100 0 1 seta:command datumH
use bc200tr 1696 760 -100 0 frame
xform 0 3376 2064
[comments]
