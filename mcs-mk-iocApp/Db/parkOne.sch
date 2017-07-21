[schematic2]
uniq 240
[tools]
[detail]
w 1794 1387 100 0 n#239 setCommand.setCommand#194.FLNK 1600 1376 2048 1376 eaos.eaos#233.SLNK
w 2354 1355 100 0 n#238 eaos.eaos#233.OUT 2304 1344 2464 1344 hwout.hwout#237.outp
w 1938 1419 100 0 DEMAND inhier.DEMAND.P 1888 1408 2048 1408 eaos.eaos#233.DOL
w 962 1387 100 0 n#232 carBusy.carBusy#184.FLNK 832 1376 1152 1376 setCommand.setCommand#194.SLNK
w 1042 1323 100 0 CMD inhier.CMD.P 992 1312 1152 1312 setCommand.setCommand#194.CMD
w 258 1387 100 0 SLNK inhier.SLNK.P 192 1376 384 1376 carBusy.carBusy#184.SLNK
[cell use]
use hwout 2464 1303 100 0 hwout#237
xform 0 2560 1344
p 2528 1296 100 0 -1 val(outp):$(top)move.$(field)
use inhier 1840 1440 100 0 DEMAND
xform 0 1888 1408
use inhier 1000 1272 100 0 CMD
xform 0 992 1312
use inhier 176 1335 100 0 SLNK
xform 0 192 1376
use eaos 2048 1287 100 0 eaos#233
xform 0 2176 1376
p 2080 1472 100 0 1 OMSL:closed_loop
p 2160 1280 100 1024 -1 name:$(top)$(command)$(dev)SetField
use setCommand 1152 1223 100 0 setCommand#194
xform 0 1376 1360
p 1172 1196 100 0 0 seta:id
use carBusy 384 1223 100 0 carBusy#184
xform 0 608 1360
use bc200tr -160 -88 -100 0 frame
xform 0 1520 1216
[comments]
