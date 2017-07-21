[schematic2]
uniq 24
[tools]
[detail]
w 2784 3211 100 0 n#23 eaos.eaos#5.FLNK 2464 3200 3152 3200 eaos.eaos#19.SLNK
w 3640 3243 100 0 FLNK eaos.eaos#19.FLNK 3408 3232 3920 3232 outhier.FLNK.p
w 3480 3179 100 0 n#18 eaos.eaos#19.OUT 3408 3168 3600 3168 hwout.hwout#21.outp
w 3070 3243 100 0 n#17 hwin.hwin#20.in 3024 3232 3152 3232 eaos.eaos#19.DOL
w 1960 3179 100 0 SLNK inhier.SLNK.P 1760 3168 2208 3168 eaos.eaos#5.SLNK
w 2536 3147 100 0 n#10 eaos.eaos#5.OUT 2464 3136 2656 3136 hwout.hwout#9.outp
w 2126 3211 100 0 n#8 hwin.hwin#7.in 2080 3200 2208 3200 eaos.eaos#5.DOL
[cell use]
use hwout 2656 3095 100 0 hwout#9
xform 0 2752 3136
p 2720 3088 100 0 -1 val(outp):$(top)$(dev)C.IVAL .PP
use hwout 3600 3127 100 0 hwout#21
xform 0 3696 3168
p 3664 3120 100 0 -1 val(outp):$(top)$(dev)CommandL .PP
use hwin 1888 3159 100 0 hwin#7
xform 0 1984 3200
p 1891 3192 100 0 -1 val(in):$(IDLE)
use hwin 2832 3191 100 0 hwin#20
xform 0 2928 3232
p 2835 3224 100 0 -1 val(in):0
use eaos 2208 3079 100 0 eaos#5
xform 0 2336 3168
p 1952 3150 100 0 0 OMSL:closed_loop
p 2320 3072 100 1024 -1 name:$(top)$(dev)$(command)SetIdle
use eaos 3152 3111 100 0 eaos#19
xform 0 3280 3200
p 2896 3182 100 0 0 OMSL:closed_loop
p 3264 3104 100 1024 -1 name:$(top)$(dev)$(command)IdleSetNull
use outhier 3888 3191 100 0 FLNK
xform 0 3904 3232
use inhier 1744 3127 100 0 SLNK
xform 0 1760 3168
use bc200tr 1296 1672 -100 0 frame
xform 0 2976 2976
[comments]
