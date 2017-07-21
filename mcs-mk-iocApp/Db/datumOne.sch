[schematic2]
uniq 315
[tools]
[detail]
w 1426 1867 100 0 n#314 setCommand.setCommand#255.FLNK 2272 2144 2432 2144 2432 1856 480 1856 480 1184 640 1184 GISassert.GISassert#232.SLNK
w 1202 1163 100 0 n#313 GISassert.GISassert#232.FAIL 1088 1152 1376 1152 1376 864 1600 864 carError.carError#238.SLNK
w 1314 1227 100 0 n#312 GISassert.GISassert#232.OK 1088 1216 1600 1216 ecalcs.ecalcs#298.SLNK
w 2386 1499 100 0 n#311 efanouts.efanouts#290.LNK2 2336 1488 2496 1488 2496 1184 2560 1184 datumHead.datumHead#236.SLNK
w 2418 1531 100 0 n#310 efanouts.efanouts#290.LNK1 2336 1520 2560 1520 datumSwitch.datumSwitch#237.SLNK
w 1490 1611 100 0 n#305 hwin.hwin#304.in 1440 1600 1600 1600 ecalcs.ecalcs#298.INPA
w 2018 1531 100 0 n#301 ecalcs.ecalcs#298.VAL 1888 1408 1952 1408 1952 1520 2144 1520 efanouts.efanouts#290.SELL
w 1962 1451 100 0 n#300 ecalcs.ecalcs#298.FLNK 1888 1440 2096 1440 efanouts.efanouts#290.SLNK
w 202 2155 100 0 SLNK inhier.SLNK.P 160 2144 304 2144 carBusy.carBusy#205.SLNK
w 850 2155 100 0 n#285 carBusy.carBusy#205.FLNK 752 2144 1008 2144 trackingOff.trackingOff#212.SLNK
w 1610 2155 100 0 n#284 trackingOff.trackingOff#212.FLNK 1456 2144 1824 2144 setCommand.setCommand#255.SLNK
w 1718 2091 100 0 CMD inhier.CMD.P 1648 2080 1824 2080 setCommand.setCommand#255.CMD
[cell use]
use hwin 1248 1559 100 0 hwin#304
xform 0 1344 1600
p 1152 1552 100 0 -1 val(in):$(top)$(dev)DatumMechL
use ecalcs 1600 1127 100 0 ecalcs#298
xform 0 1744 1392
p 1744 1584 100 0 1 CALC:(A=12)?1:2
p 1712 1120 100 1024 -1 name:$(top)$(command)$(dev)Calc
use efanouts 2096 1303 100 0 efanouts#290
xform 0 2216 1456
p 2176 1616 100 0 1 SELM:Mask
p 2128 1280 100 1024 -1 name:$(top)$(command)$(dev)ChooseDatum2
p 2368 1520 75 1280 -1 pproc(LNK1):PP
p 2368 1488 75 1280 -1 pproc(LNK2):PP
p 2368 1456 75 1280 -1 pproc(LNK3):NPP
use inhier 144 2103 100 0 SLNK
xform 0 160 2144
use inhier 1632 2039 100 0 CMD
xform 0 1648 2080
use setCommand 1824 1991 100 0 setCommand#255
xform 0 2048 2128
p 1920 2080 100 0 1 seta:id 1
use carError 1600 711 100 0 carError#238
xform 0 1824 848
p 1760 800 100 0 1 seta:errno 1
p 1760 768 100 0 1 setb:id 1
use datumSwitch 2560 1367 100 0 datumSwitch#237
xform 0 2784 1504
use datumHead 2560 1031 100 0 datumHead#236
xform 0 2784 1168
use GISassert 640 1095 100 0 GISassert#232
xform 0 864 1176
p 704 1088 100 0 1 seta:id 9
use trackingOff 1008 1991 100 0 trackingOff#212
xform 0 1232 2128
use carBusy 336 1991 100 0 carBusy#205
xform 0 528 2128
use bc200tr -160 -88 -100 0 frame
xform 0 1520 1216
[comments]
