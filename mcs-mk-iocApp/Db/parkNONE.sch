[schematic2]
uniq 28
[tools]
[detail]
w 2856 2251 100 0 n#27 efanouts.efanouts#0.LNK2 2624 2688 2784 2688 2784 2240 2976 2240 parkOne.parkOne#4.SLNK
w 3656 1931 100 0 n#23 eaos.eaos#17.OUT 3616 1920 3744 1920 hwout.hwout#22.outp
w 3016 1963 100 0 n#21 efanouts.efanouts#0.LNK3 2624 2656 2720 2656 2720 1952 3360 1952 eaos.eaos#17.SLNK
w 3272 1995 100 0 n#20 hwin.hwin#18.in 3232 1984 3360 1984 eaos.eaos#17.DOL
w 2888 2443 100 0 c#15 inhier.EL_CMD.P 2848 2432 2976 2432 parkOne.parkOne#4.CMD
w 2888 2923 100 0 AZ_CMD inhier.AZ_CMD.P 2848 2912 2976 2912 parkOne.parkOne#3.CMD
w 2888 2379 100 0 EL inhier.EL.P 2848 2368 2976 2368 parkOne.parkOne#4.DEMAND
w 2894 2859 100 0 AZ inhier.AZ.P 2848 2848 2976 2848 parkOne.parkOne#3.DEMAND
w 2782 2731 100 0 n#5 efanouts.efanouts#0.LNK1 2624 2720 2976 2720 parkOne.parkOne#3.SLNK
w 2262 2651 100 0 SLNK inhier.SLNK.P 2176 2640 2384 2640 efanouts.efanouts#0.SLNK
[cell use]
use hwout 3744 1879 100 0 hwout#22
xform 0 3840 1920
p 3792 1872 100 0 -1 val(outp):$(top)move.DIR .PP
use hwin 3040 1943 100 0 hwin#18
xform 0 3136 1984
p 3043 1976 100 0 -1 val(in):$(START)
use eaos 3360 1863 100 0 eaos#17
xform 0 3488 1952
p 3408 2048 100 0 1 OMSL:closed_loop
p 3472 1856 100 1024 -1 name:$(top)$(command)SendStart
use inhier 2160 2599 100 0 SLNK
xform 0 2176 2640
use inhier 2832 2807 100 0 AZ
xform 0 2848 2848
use inhier 2832 2327 100 0 EL
xform 0 2848 2368
use inhier 2816 2944 100 0 AZ_CMD
xform 0 2848 2912
use inhier 2816 2464 100 0 EL_CMD
xform 0 2848 2432
use parkOne 2976 2183 100 0 parkOne#4
xform 0 3136 2368
p 3088 2320 100 0 1 seta:field D
p 3088 2288 100 0 1 setb:dev el
use parkOne 2976 2663 100 0 parkOne#3
xform 0 3136 2848
p 3088 2800 100 0 1 seta:field C
p 3088 2768 100 0 1 setb:dev az
use efanouts 2384 2503 100 0 efanouts#0
xform 0 2504 2656
p 2496 2496 100 1024 -1 name:$(top)$(command)Fanout
p 2656 2720 75 1280 -1 pproc(LNK1):PP
p 2656 2688 75 1280 -1 pproc(LNK2):PP
p 2656 2656 75 1280 -1 pproc(LNK3):PP
use bc200tr 1568 1112 -100 0 frame
xform 0 3248 2416
[comments]
