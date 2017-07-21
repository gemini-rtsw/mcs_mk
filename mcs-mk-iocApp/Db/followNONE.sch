[schematic2]
uniq 213
[tools]
[detail]
w 2514 4011 100 0 n#212 followOne.followOne#164.FLNK 2464 4000 2624 4000 trackingOn.trackingOn#156.SLNK
w 1994 4011 100 0 n#210 followOne.followOne#163.FLNK 1968 4000 2080 4000 followOne.followOne#164.SLNK
w 1426 3979 100 0 n#205 efanouts.efanouts#174.LNK4 1408 3968 1504 3968 1504 3488 1568 3488 trackingOff.trackingOff#178.SLNK
w 2642 3499 100 0 n#204 carIdle.carIdle#184.FLNK 2592 3488 2752 3488 trackingOff.trackingOff#182.SLNK
w 1466 4011 100 0 n#196 efanouts.efanouts#174.LNK3 1408 4000 1584 4000 followOne.followOne#163.SLNK
w 3234 3499 100 0 n#191 trackingOff.trackingOff#182.FLNK 3200 3488 3328 3488 carIdle.carIdle#190.SLNK
w 2050 3499 100 0 n#187 trackingOff.trackingOff#178.FLNK 2016 3488 2144 3488 carIdle.carIdle#184.SLNK
w 1106 4075 100 0 n#176 hwin.hwin#175.in 1056 4064 1216 4064 efanouts.efanouts#174.SELL
w 1042 3995 100 0 SLNK inhier.SLNK.P 976 3984 1168 3984 efanouts.efanouts#174.SLNK
[cell use]
use efanouts 1168 3847 100 0 efanouts#174
xform 0 1288 4000
p 1264 4160 100 0 1 SELM:Specified
p 1280 3840 100 1024 -1 name:$(top)$(command)Fanout
p 1440 4000 75 1280 -1 pproc(LNK3):PP
p 1440 3968 75 1280 -1 pproc(LNK4):PP
use carIdle 2144 3335 100 0 carIdle#184
xform 0 2368 3472
p 2224 3312 200 0 1 seta:dev az
use carIdle 3328 3335 100 0 carIdle#190
xform 0 3552 3472
p 3408 3312 200 0 1 seta:dev el
use trackingOff 2752 3335 100 0 trackingOff#182
xform 0 2976 3472
p 2816 3312 200 0 1 seta:card 1
p 2816 3264 200 0 1 setb:dev el
use trackingOff 1568 3335 100 0 trackingOff#178
xform 0 1792 3472
p 1632 3312 200 0 1 seta:card 0
p 1632 3264 200 0 1 setb:dev az
use hwin 864 4023 100 0 hwin#175
xform 0 960 4064
p 864 4112 100 0 -1 val(in):$(top)follow.ODIR
use bc200tr 672 1944 -100 0 frame
xform 0 2352 3248
use inhier 960 3943 100 0 SLNK
xform 0 976 3984
use followOne 1584 3815 100 0 followOne#163
xform 0 1776 4000
p 1648 3776 200 0 1 seta:dev az
p 1648 3728 200 0 1 setb:id
use followOne 2080 3815 100 0 followOne#164
xform 0 2272 4000
p 2144 3776 200 0 1 seta:dev el
p 2144 3728 200 0 1 setb:id
use trackingOn 2624 3847 100 0 trackingOn#156
xform 0 2848 3984
[comments]
