[schematic2]
uniq 1
[tools]
[detail]
s 2752 176 100 0 Command Interface
s 2720 240 100 0 MCS Level 2
s 2448 224 100 0 Andy Foster
[cell use]
use bc200tr -160 -40 -100 0 frame
xform 0 1520 1264
use logDataFollow 2496 1095 100 0 logDataFollow#55
xform 0 2672 1216
p 2496 1088 100 0 -1 seta:command trackingLog
p 2496 1056 100 0 -1 setb:EVENT_NUMBER 19
use stop 120 1768 100 0 stop#35
xform 0 272 1888
p 96 1758 100 0 -1 seta:command stop
p 96 1726 100 0 -1 setb:EVENT_NUMBER 7
use trajectory 2496 1447 100 0 trajectory#53
xform 0 2672 1568
p 2496 1440 100 0 -1 seta:command trajectory
p 2496 1408 100 0 -1 setb:EVENT_NUMBER 18
use reload 2016 1447 100 0 reload#51
xform 0 2192 1568
p 2016 1440 100 0 -1 seta:command reload
p 2016 1408 100 0 -1 setb:EVENT_NUMBER 17
use move 600 1768 100 0 move#36
xform 0 752 1888
p 576 1758 100 0 -1 seta:command move
p 576 1726 100 0 -1 setb:EVENT_NUMBER 8
use testlan 1560 1448 100 0 testlan#50
xform 0 1712 1568
p 1536 1438 100 0 -1 seta:command testLan
p 1536 1406 100 0 -1 setb:EVENT_NUMBER 16
use cartop 1272 1032 100 0 cartop#49
xform 0 1456 1184
p 1248 992 100 0 -1 seta:id carTop:
use cwmove 1080 1448 100 0 cwmove#44
xform 0 1232 1568
p 1056 1438 100 0 -1 seta:command cwmove
p 1056 1406 100 0 -1 setb:EVENT_NUMBER 15
use tolerance 600 1448 100 0 tolerance#42
xform 0 752 1568
p 576 1438 100 0 -1 seta:command tolerance
p 576 1406 100 0 -1 setb:EVENT_NUMBER 14
use elconfig 2520 1768 100 0 elconfig#40
xform 0 2672 1888
p 2496 1758 100 0 -1 seta:command elconfig
p 2496 1726 100 0 -1 setb:EVENT_NUMBER 12
use azconfig 2040 1768 100 0 azconfig#39
xform 0 2192 1888
p 2016 1758 100 0 -1 seta:command azconfig
p 2016 1726 100 0 -1 setb:EVENT_NUMBER 11
use park 1560 1768 100 0 park#38
xform 0 1712 1888
p 1552 1758 100 0 -1 seta:command park
p 1552 1726 100 0 -1 setb:EVENT_NUMBER 10
use follow 1080 1768 100 0 follow#37
xform 0 1232 1888
p 1056 1758 100 0 -1 seta:command follow
p 1056 1726 100 0 -1 setb:EVENT_NUMBER 9
use simulate 2520 2088 100 0 simulate#34
xform 0 2672 2208
p 2512 2078 100 0 -1 seta:command simulate
p 2512 2046 100 0 -1 setb:EVENT_NUMBER 6
use debug 2040 2088 100 0 debug#33
xform 0 2192 2208
p 2016 2078 100 0 -1 seta:command debug
p 2016 2046 100 0 -1 setb:EVENT_NUMBER 5
use test 1560 2088 100 0 test#32
xform 0 1712 2208
p 1552 2078 100 0 -1 seta:command test
p 1552 2046 100 0 -1 setb:EVENT_NUMBER 4
use datum 1080 2088 100 0 datum#31
xform 0 1232 2208
p 1056 2078 100 0 -1 seta:command datum
p 1056 2046 100 0 -1 setb:EVENT_NUMBER 3
use init 600 2088 100 0 init#30
xform 0 752 2208
p 576 2078 100 0 -1 seta:command init
p 576 2046 100 0 -1 setb:EVENT_NUMBER 2
use reboot 120 2088 100 0 reboot#29
xform 0 272 2208
p 112 2078 100 0 -1 seta:command reboot
p 112 2046 100 0 -1 setb:EVENT_NUMBER 1
[comments]
