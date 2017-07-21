[schematic2]
uniq 195
[tools]
[detail]
w 1906 971 100 0 n#194 efanouts.efanouts#11.LNK3 1584 1536 1664 1536 1664 960 2208 960 carBusyIdle.carBusyIdle#161.SLNK
w 1938 1739 100 0 n#193 efanouts.efanouts#11.LNK1 1584 1600 1728 1600 1728 1728 2208 1728 moveOne.moveOne#26.SLNK
w 1938 1211 100 0 n#192 efanouts.efanouts#11.LNK2 1584 1568 1728 1568 1728 1200 2208 1200 moveOne.moveOne#162.SLNK
w 2050 1403 100 0 c#184 inhier.EL_CMD.P 1952 1392 2208 1392 moveOne.moveOne#162.CMD
w 2050 1275 100 0 c#185 inhier.ELVEL.P 1952 1264 2208 1264 moveOne.moveOne#162.VEL
w 2050 1339 100 0 c#186 inhier.EL.P 1952 1328 2208 1328 moveOne.moveOne#162.DEMAND
w 2050 1931 100 0 AZ_CMD inhier.AZ_CMD.P 1952 1920 2208 1920 moveOne.moveOne#26.CMD
w 2050 1803 100 0 AZVEL inhier.AZVEL.P 1952 1792 2208 1792 moveOne.moveOne#26.VEL
w 2050 1867 100 0 AZ inhier.AZ.P 1952 1856 2208 1856 moveOne.moveOne#26.DEMAND
w 1210 1531 100 0 SLNK inhier.SLNK.P 1136 1520 1344 1520 efanouts.efanouts#11.SLNK
w 1186 1611 100 0 c#147 inhier.MASK.P 1040 1600 1392 1600 efanouts.efanouts#11.SELL
[cell use]
use inhier 1872 1312 100 0 EL
xform 0 1952 1328
use inhier 1872 1248 100 0 ELVEL
xform 0 1952 1264
use inhier 1856 1376 100 0 EL_CMD
xform 0 1952 1392
use inhier 1024 1559 100 0 MASK
xform 0 1040 1600
use inhier 1120 1479 100 0 SLNK
xform 0 1136 1520
use inhier 1872 1840 100 0 AZ
xform 0 1952 1856
use inhier 1872 1776 100 0 AZVEL
xform 0 1952 1792
use inhier 1856 1904 100 0 AZ_CMD
xform 0 1952 1920
use moveOne 2184 1736 100 0 moveOne#26
xform 0 2368 1856
p 2336 1806 100 0 1 seta:dev az
p 2336 1774 100 0 1 setb:card 0
p 2336 1744 100 0 1 setc:park 10
use moveOne 2184 1208 100 0 moveOne#162
xform 0 2368 1328
p 2336 1294 100 0 1 seta:dev el
p 2336 1262 100 0 1 setb:card 1
p 2336 1232 100 0 1 setc:park 10
use carBusyIdle 2208 839 100 0 carBusyIdle#161
xform 0 2432 944
use efanouts 1368 1384 100 0 efanouts#11
xform 0 1464 1536
p 1440 1694 100 0 1 SELM:Mask
p 1456 1376 100 1024 -1 name:$(top)$(command)Fanout
p 1616 1600 75 1280 -1 pproc(LNK1):PP
p 1616 1568 75 1280 -1 pproc(LNK2):PP
p 1616 1536 75 1280 -1 pproc(LNK3):PP
p 1616 1504 75 1280 -1 pproc(LNK4):NPP
use bc200tr -96 -88 -100 0 frame
xform 0 1584 1216
[comments]
