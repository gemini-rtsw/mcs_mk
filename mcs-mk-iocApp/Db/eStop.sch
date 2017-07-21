[schematic2]
uniq 23
[tools]
[detail]
w 3272 2091 100 0 n#22 carIdle.carIdle#17.FLNK 3936 2272 4032 2272 4032 2080 2560 2080 2560 1888 2720 1888 eaos.eaos#14.SLNK
w 3208 1931 100 0 n#21 eaos.eaos#14.FLNK 2976 1920 3488 1920 carIdle.carIdle#20.SLNK
w 3208 2283 100 0 n#18 eaos.eaos#10.FLNK 2976 2272 3488 2272 carIdle.carIdle#17.SLNK
w 2552 1931 100 0 n#11 junction 2432 2272 2432 1920 2720 1920 eaos.eaos#14.DOL
w 2504 2283 100 0 n#11 hwin.hwin#6.in 2336 2272 2720 2272 eaos.eaos#10.DOL
w 3016 1867 100 0 n#15 eaos.eaos#14.OUT 2976 1856 3104 1856 hwout.hwout#13.outp
w 3016 2219 100 0 n#12 eaos.eaos#10.OUT 2976 2208 3104 2208 hwout.hwout#1.outp
[cell use]
use carIdle 3488 1767 100 0 carIdle#20
xform 0 3712 1904
p 3616 1856 100 0 1 seta:dev el
p 3616 1824 100 0 1 setb:command estop
use carIdle 3488 2119 100 0 carIdle#17
xform 0 3712 2256
p 3616 2208 100 0 1 seta:dev az
p 3616 2176 100 0 1 setb:command estop
use eaos 2720 1799 100 0 eaos#14
xform 0 2848 1888
p 2768 1984 100 0 1 OMSL:closed_loop
p 2832 1792 100 1024 -1 name:$(top)elEstop
use eaos 2720 2151 100 0 eaos#10
xform 0 2848 2240
p 2768 2336 100 0 1 OMSL:closed_loop
p 2832 2144 100 1024 -1 name:$(top)azEstop
use hwout 3104 1815 100 0 hwout#13
xform 0 3200 1856
p 3040 1792 100 0 -1 val(outp):$(top)elDriveEnable .PP
use hwout 3104 2167 100 0 hwout#1
xform 0 3200 2208
p 3040 2144 100 0 -1 val(outp):$(top)azDriveEnable .PP
use hwin 2144 2231 100 0 hwin#6
xform 0 2240 2272
p 2128 2304 100 0 -1 val(in):$(DISASSERT)
use bc200tr 1328 584 -100 0 frame
xform 0 3008 1888
[comments]
