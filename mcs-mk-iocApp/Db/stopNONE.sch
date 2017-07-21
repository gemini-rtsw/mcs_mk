[schematic2]
uniq 139
[tools]
[detail]
w 1746 1099 100 0 n#138 efanouts.efanouts#97.LNK3 1408 1632 1504 1632 1504 1088 2048 1088 carBusyIdle.carBusyIdle#104.SLNK
w 1778 1387 100 0 n#137 efanouts.efanouts#97.LNK2 1408 1664 1568 1664 1568 1376 2048 1376 stopOne.stopOne#81.SLNK
w 1746 1835 100 0 n#136 efanouts.efanouts#97.LNK1 1408 1696 1504 1696 1504 1824 2048 1824 stopOne.stopOne#80.SLNK
w 1922 1515 100 0 c#132 inhier.EL_CMD.P 1856 1504 2048 1504 stopOne.stopOne#81.CMD
w 1910 1451 100 0 c#131 inhier.EL_MASK.P 1856 1440 2048 1440 stopOne.stopOne#81.MASK
w 1922 1963 100 0 AZ_CMD inhier.AZ_CMD.P 1856 1952 2048 1952 stopOne.stopOne#80.CMD
w 1910 1899 100 0 AZ_MASK inhier.AZ_MASK.P 1856 1888 2048 1888 stopOne.stopOne#80.MASK
w 1002 1627 100 0 SLNK inhier.SLNK.P 896 1616 1168 1616 efanouts.efanouts#97.SLNK
w 1026 1707 100 0 MASK inhier.MASK.P 896 1696 1216 1696 efanouts.efanouts#97.SELL
[cell use]
use inhier 1760 1504 100 0 EL_CMD
xform 0 1856 1504
use inhier 1744 1440 100 0 EL_MASK
xform 0 1856 1440
use inhier 1760 1952 100 0 AZ_CMD
xform 0 1856 1952
use inhier 880 1655 100 0 MASK
xform 0 896 1696
use inhier 880 1575 100 0 SLNK
xform 0 896 1616
use inhier 1744 1888 100 0 AZ_MASK
xform 0 1856 1888
use carBusyIdle 2048 967 100 0 carBusyIdle#104
xform 0 2272 1072
use efanouts 1168 1479 100 0 efanouts#97
xform 0 1288 1632
p 1248 1792 100 0 1 SELM:Mask
p 1280 1472 100 1024 -1 name:$(top)$(command)Fanout
p 1440 1696 75 1280 -1 pproc(LNK1):PP
p 1440 1664 75 1280 -1 pproc(LNK2):PP
p 1440 1632 75 1280 -1 pproc(LNK3):PP
use stopOne 2008 1800 100 0 stopOne#80
xform 0 2192 1920
p 2144 1886 100 0 1 seta:dev az
p 2144 1854 100 0 1 setb:card 0
p 2144 1824 100 0 1 setc:park 10
use stopOne 2008 1352 100 0 stopOne#81
xform 0 2192 1472
p 2144 1438 100 0 1 seta:dev el
p 2144 1406 100 0 1 setb:card 1
p 2144 1376 100 0 1 setc:park 10
use bc200tr -96 -88 -100 0 frame
xform 0 1584 1216
[comments]
