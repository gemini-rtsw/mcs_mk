[schematic2]
uniq 2
[tools]
[detail]
w 1170 1195 100 0 c inhier.CMD.P 1120 1184 1280 1184 eaos.eaos#172.DOL
w 1714 1195 100 0 FLNK eaos.eaos#172.FLNK 1536 1184 1952 1184 outhier.FLNK.p
w 1570 1131 100 0 n#1 eaos.eaos#172.OUT 1536 1120 1664 1120 hwout.hwout#144.outp
w 1112 1163 100 0 SLNK inhier.SLNK.P 992 1152 1280 1152 eaos.eaos#172.SLNK
[cell use]
use bc200tr -96 -88 -100 0 frame
xform 0 1584 1216
use eaos 1280 1063 100 0 eaos#172
xform 0 1408 1152
p 1328 1248 100 0 1 OMSL:closed_loop
p 1278 1068 100 1024 -1 name:$(top)$(dev)$(command)Set$(id)
use inhier 1088 1216 100 0 CMD
xform 0 1120 1184
use inhier 976 1111 100 0 SLNK
xform 0 992 1152
use hwout 1664 1079 100 0 hwout#144
xform 0 1760 1120
p 1696 1056 100 0 -1 val(outp):$(top)$(dev)CommandL .PP
use outhier 1920 1143 100 0 FLNK
xform 0 1936 1184
[comments]
