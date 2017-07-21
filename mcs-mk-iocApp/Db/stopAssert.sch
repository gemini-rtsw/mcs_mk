[schematic2]
uniq 24
[tools]
[detail]
w 2576 2251 100 0 SLNK inhier.SLNK.P 2480 2240 2720 2240 eaos.eaos#10.SLNK
w 3208 2283 100 0 n#18 eaos.eaos#10.FLNK 2976 2272 3488 2272 carIdle.carIdle#17.SLNK
w 2504 2283 100 0 n#11 hwin.hwin#6.in 2336 2272 2720 2272 eaos.eaos#10.DOL
w 3016 2219 100 0 n#12 eaos.eaos#10.OUT 2976 2208 3104 2208 hwout.hwout#1.outp
[cell use]
use inhier 2464 2199 100 0 SLNK
xform 0 2480 2240
use carIdle 3488 2119 100 0 carIdle#17
xform 0 3712 2256
p 3616 2208 100 0 1 seta:dev $(dev)
p 3616 2176 100 0 1 setb:command stopBrake
use eaos 2720 2151 100 0 eaos#10
xform 0 2848 2240
p 2768 2336 100 0 1 OMSL:closed_loop
p 2832 2144 100 1024 -1 name:$(top)$(dev)stopBrake
use hwout 3104 2167 100 0 hwout#1
xform 0 3200 2208
p 3040 2144 100 0 -1 val(outp):$(top)$(dev)DriveEnable .PP
use hwin 2144 2231 100 0 hwin#6
xform 0 2240 2272
p 2128 2304 100 0 -1 val(in):$(DISASSERT)
use bc200tr 1328 584 -100 0 frame
xform 0 3008 1888
[comments]
