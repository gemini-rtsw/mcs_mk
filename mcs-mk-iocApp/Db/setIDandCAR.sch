[schematic2]
uniq 48
[tools]
[detail]
w 800 2891 100 0 n#47 hwin.hwin#44.in 736 2880 912 2880 ecalcs.ecalcs#34.INPA
w 800 2859 100 0 n#46 hwin.hwin#45.in 736 2848 912 2848 ecalcs.ecalcs#34.INPB
w 1624 2811 100 0 n#42 efanouts.efanouts#35.LNK1 1552 2800 1744 2800 1744 2592 1840 2592 carBusy.carBusy#20.SLNK
w 1216 2699 100 0 n#41 ecalcs.ecalcs#34.VAL 1200 2688 1280 2688 1280 2800 1360 2800 efanouts.efanouts#35.SELL
w 1232 2731 100 0 n#40 ecalcs.ecalcs#34.FLNK 1200 2720 1312 2720 efanouts.efanouts#35.SLNK
w 2360 2603 100 0 n#33 carBusy.carBusy#20.FLNK 2288 2592 2480 2592 carBusy.carBusy#21.SLNK
w 696 2507 100 0 SLNK inhier.SLNK.P 528 2496 912 2496 ecalcs.ecalcs#34.SLNK
w 3048 2859 100 0 TRACKID inhier.TRACKID.P 2960 2848 3184 2848 3184 2624 3296 2624 eaos.eaos#1.DOL
w 3088 2603 100 0 n#22 carBusy.carBusy#21.FLNK 2928 2592 3296 2592 eaos.eaos#1.SLNK
[cell use]
use hwin 544 2839 100 0 hwin#44
xform 0 640 2880
p 544 2912 100 0 -1 val(in):$(top)FollowL
use hwin 544 2807 100 0 hwin#45
xform 0 640 2848
p 496 2800 100 0 -1 val(in):$(top)inPosition
use efanouts 1312 2583 100 0 efanouts#35
xform 0 1432 2736
p 1360 2896 150 0 1 SELM:Specified
p 1424 2576 100 1024 0 name:$(top)CommandFilt
use ecalcs 912 2407 100 0 ecalcs#34
xform 0 1056 2672
p 944 2944 150 0 1 CALC:(A & B)?2:1
p 1024 2400 100 1024 0 name:$(top)CalcFilt
use bc200tr 352 1192 -100 0 frame
xform 0 2032 2496
use carBusy 2480 2439 100 0 carBusy#21
xform 0 2704 2576
p 2560 2416 200 0 1 seta:dev el
p 2560 2352 200 0 1 setb:command tracking
use carBusy 1840 2439 100 0 carBusy#20
xform 0 2064 2576
p 1920 2400 200 0 1 seta:dev az
p 1920 2352 200 0 1 setb:command tracking
use inhier 512 2455 100 0 SLNK
xform 0 528 2496
use inhier 2944 2807 100 0 TRACKID
xform 0 2960 2848
use eaos 3296 2503 100 0 eaos#1
xform 0 3424 2592
p 3344 2688 100 0 1 OMSL:closed_loop
p 3344 2720 100 0 1 PREC:12
p 3408 2496 100 1024 -1 name:$(top)trackId
[comments]
