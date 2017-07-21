[schematic2]
uniq 259
[tools]
[detail]
w 2098 1707 100 0 n#258 setCommand.setCommand#222.FLNK 2992 2080 3040 2080 3040 1696 1216 1696 1216 992 1408 992 eseqs.eseqs#252.SLNK
w 1106 2059 100 0 n#258 efanouts.efanouts#233.LNK2 1056 2048 1216 2048 1216 1696 junction
w 2034 811 100 0 n#256 eseqs.eseqs#252.LNK3 1728 1248 1856 1248 1856 800 2272 800 GISdisassert.GISdisassert#200.SLNK
w 2066 1083 100 0 n#255 eseqs.eseqs#252.LNK2 1728 1280 1920 1280 1920 1072 2272 1072 estringins.estringins#97.SLNK
w 1970 1323 100 0 n#254 eseqs.eseqs#252.LNK1 1728 1312 2272 1312 estringins.estringins#191.SLNK
w 1320 1355 100 0 MASK inhier.MASK.P 1280 1344 1408 1344 eseqs.eseqs#252.SELL
w 754 2091 100 0 n#242 ecalcs.ecalcs#230.VAL 624 1968 704 1968 704 2080 864 2080 efanouts.efanouts#233.SELL
w 690 2011 100 0 n#241 ecalcs.ecalcs#230.FLNK 624 2000 816 2000 efanouts.efanouts#233.SLNK
w 1170 2091 100 0 n#240 efanouts.efanouts#233.LNK1 1056 2080 1344 2080 carBusy.carBusy#205.SLNK
w 2442 2091 100 0 n#238 trackingOff.trackingOff#212.FLNK 2400 2080 2544 2080 setCommand.setCommand#222.SLNK
w 1842 2091 100 0 n#237 carBusy.carBusy#205.FLNK 1792 2080 1952 2080 trackingOff.trackingOff#212.SLNK
w 2466 2027 100 0 CMD inhier.CMD.P 2448 2016 2544 2016 setCommand.setCommand#222.CMD
w 258 2171 100 0 n#232 hwin.hwin#231.in 240 2160 336 2160 ecalcs.ecalcs#230.INPA
w 242 1787 100 0 SLNK inhier.SLNK.P 208 1776 336 1776 ecalcs.ecalcs#230.SLNK
w 2186 1348 100 0 n#190 hwin.hwin#192.in 2160 1344 2272 1344 estringins.estringins#191.INP
w 2186 1108 100 0 n#101 hwin.hwin#98.in 2160 1104 2272 1104 estringins.estringins#97.INP
[cell use]
use eseqs 1408 903 100 0 eseqs#252
xform 0 1568 1152
p 1520 1392 100 0 1 DLY2:0.25
p 1520 1360 100 0 1 SELM:Mask
p 1520 896 100 1024 -1 name:$(top)$(command)$(dev)ChooseStop
p 1744 1312 75 1024 -1 pproc(LNK1):PP
p 1744 1280 75 1024 -1 pproc(LNK2):PP
p 1744 1248 75 1024 -1 pproc(LNK3):PP
use hwin 1992 1304 100 0 hwin#192
xform 0 2064 1344
p 1968 1390 100 0 -1 val(in):#C$(card) S0 @#2K
use hwin 1992 1064 100 0 hwin#98
xform 0 2064 1104
p 1968 1150 100 0 -1 val(in):#C$(card) S0 @#2J/
use hwin 48 2119 100 0 hwin#231
xform 0 144 2160
p 0 2208 100 0 -1 val(in):$(top)$(dev)CommandL
use efanouts 816 1863 100 0 efanouts#233
xform 0 936 2016
p 912 2176 100 0 1 SELM:Mask
p 928 1856 100 1024 -1 name:$(top)$(command)$(dev)FO
p 1088 2080 75 1280 -1 pproc(LNK1):PP
p 1088 2048 75 1280 -1 pproc(LNK2):PP
use ecalcs 336 1687 100 0 ecalcs#230
xform 0 480 1952
p 336 2224 100 0 1 CALC:(A=$(park))?2:1
p 448 1680 100 1024 -1 name:$(top)$(command)$(dev)Calc
use inhier 1264 1303 100 0 MASK
xform 0 1280 1344
use inhier 192 1735 100 0 SLNK
xform 0 208 1776
use inhier 2432 1975 100 0 CMD
xform 0 2448 2016
use setCommand 2544 1927 100 0 setCommand#222
xform 0 2768 2064
p 2564 1900 100 0 0 seta:id
use estringins 2296 1240 100 0 estringins#191
xform 0 2400 1312
p 2336 1390 100 0 1 DTYP:PMAC-VME ASCII
p 2384 1232 100 1024 -1 name:$(top)$(command)$(dev)SendKill
use estringins 2296 1000 100 0 estringins#97
xform 0 2400 1072
p 2336 1150 100 0 1 DTYP:PMAC-VME ASCII
p 2384 992 100 1024 -1 name:$(top)$(command)$(dev)CloseLoop
use trackingOff 1952 1927 100 0 trackingOff#212
xform 0 2176 2064
use carBusy 1376 1927 100 0 carBusy#205
xform 0 1568 2064
use GISdisassert 2272 711 100 0 GISdisassert#200
xform 0 2528 800
p 2480 752 100 0 1 seta:id 1
use bc200tr -160 -88 -100 0 frame
xform 0 1520 1216
[comments]
