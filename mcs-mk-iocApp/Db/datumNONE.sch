[schematic2]
uniq 154
[tools]
[detail]
w 1530 3467 100 0 SLNK inhier.SLNK.P 1472 3456 1648 3456 efanouts.efanouts#97.SLNK
w 2194 3211 100 0 n#150 efanouts.efanouts#97.LNK2 1888 3504 2016 3504 2016 3200 2432 3200 datumOne.datumOne#119.SLNK
w 2306 3403 100 0 c#148 inhier.EL_CMD.P 2240 3392 2432 3392 datumOne.datumOne#119.CMD
w 2306 3915 100 0 c#144 inhier.AZ_CMD.P 2240 3904 2432 3904 datumOne.datumOne#117.CMD
w 2178 3723 100 0 n#139 efanouts.efanouts#97.LNK1 1888 3536 1984 3536 1984 3712 2432 3712 datumOne.datumOne#117.SLNK
w 1506 3547 100 0 MASK inhier.MASK.P 1376 3536 1696 3536 efanouts.efanouts#97.SELL
[cell use]
use inhier 1456 3415 100 0 SLNK
xform 0 1472 3456
use inhier 1360 3495 100 0 MASK
xform 0 1376 3536
use inhier 2224 3863 100 0 AZ_CMD
xform 0 2240 3904
use inhier 2224 3351 100 0 EL_CMD
xform 0 2240 3392
use bc200tr 672 1944 -100 0 frame
xform 0 2352 3248
use efanouts 1648 3319 100 0 efanouts#97
xform 0 1768 3472
p 1728 3632 100 0 1 SELM:Mask
p 1760 3312 100 1024 -1 name:$(top)$(command)Fanout
p 1920 3536 75 1280 -1 pproc(LNK1):PP
p 1920 3504 75 1280 -1 pproc(LNK2):PP
p 1920 3472 75 1280 -1 pproc(LNK3):NPP
use datumOne 2384 3207 100 0 datumOne#119
xform 0 2592 3328
p 2544 3272 100 0 1 seta:dev el
p 2544 3240 100 0 1 setb:card 1
use datumOne 2384 3719 100 0 datumOne#117
xform 0 2592 3840
p 2528 3784 100 0 1 seta:dev az
p 2528 3752 100 0 1 setb:card 0
[comments]
