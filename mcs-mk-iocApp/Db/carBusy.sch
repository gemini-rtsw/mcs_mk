[schematic2]
uniq 17
[tools]
[detail]
w 3128 3147 100 0 FLNK eaos.eaos#5.FLNK 2816 3136 3488 3136 outhier.FLNK.p
w 2312 3115 100 0 SLNK inhier.SLNK.P 2112 3104 2560 3104 eaos.eaos#5.SLNK
w 2888 3083 100 0 n#10 eaos.eaos#5.OUT 2816 3072 3008 3072 hwout.hwout#9.outp
w 2478 3147 100 0 n#8 hwin.hwin#7.in 2432 3136 2560 3136 eaos.eaos#5.DOL
[cell use]
use outhier 3456 3095 100 0 FLNK
xform 0 3472 3136
use inhier 2096 3063 100 0 SLNK
xform 0 2112 3104
use hwout 3008 3031 100 0 hwout#9
xform 0 3104 3072
p 3072 3024 100 0 -1 val(outp):$(top)$(dev)C.IVAL .PP
use hwin 2240 3095 100 0 hwin#7
xform 0 2336 3136
p 2243 3128 100 0 -1 val(in):$(BUSY)
use eaos 2560 3015 100 0 eaos#5
xform 0 2688 3104
p 2304 3086 100 0 0 OMSL:closed_loop
p 2672 3008 100 1024 -1 name:$(top)$(dev)$(command)SetBusy
use bc200tr 1296 1672 -100 0 frame
xform 0 2976 2976
[comments]
