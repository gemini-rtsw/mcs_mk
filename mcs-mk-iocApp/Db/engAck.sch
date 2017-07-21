[schematic2]
uniq 11
[tools]
[detail]
w 454 3138 100 0 n#7 inhier.SLNK.P 352 3136 592 3136 ecalcs.ecalcs#0.SLNK
w 454 3522 100 0 n#5 inhier.INP.P 352 3520 592 3520 ecalcs.ecalcs#0.INPA
w 918 3362 100 0 n#3 ecalcs.ecalcs#0.FLNK 880 3360 992 3360 992 3296 1088 3296 ebis.ebis#1.SLNK
w 966 3330 100 0 n#2 ecalcs.ecalcs#0.VAL 880 3328 1088 3328 ebis.ebis#1.INP
[cell use]
use inhier 360 3096 100 0 SLNK
xform 0 352 3136
use inhier 360 3480 100 0 INP
xform 0 352 3520
use ebis 1112 3224 100 0 ebis#1
xform 0 1216 3296
p 1152 3374 100 0 1 ONAM:REJECTED
p 1152 3406 100 0 1 ZNAM:ACCEPTED
p 1200 3216 100 1024 -1 name:$(top)$(command)Bi
use ecalcs 616 3048 100 0 ecalcs#0
xform 0 736 3312
p 624 3598 100 0 1 CALC:(A<0)?1:0
p 704 3040 100 1024 -1 name:$(top)$(command)Ack
use bc200tr -64 1400 -100 0 frame
xform 0 1616 2704
[comments]
