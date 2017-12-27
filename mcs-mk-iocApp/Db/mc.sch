[schematic2]
uniq 1
[tools]
[detail]
s 2512 48 100 0 Andy Foster
s 2784 0 200 0 MCS Level 1
[cell use]
use bc200tr -96 -216 -100 0 frame
xform 0 1584 1088
use commandIf 24 1736 100 0 commandIf#1
xform 0 368 1976
p 160 1968 100 0 1 seta:CLEAR_TRIGGER 0
p 160 1936 100 0 1 setb:START_TRIGGER 1
p 160 1904 100 0 1 setc:SLEW_ON 1
p 160 1872 100 0 1 setd:SLEW_OFF 0
p 160 1840 100 0 1 sete:DISABLE 0
p 432 1904 100 0 1 setf:ENABLE 1
p 432 1872 100 0 1 setg:ES 1
use testNewFollow 128 135 100 0 testNewFollow#27
xform 0 272 240
p 128 128 100 0 1 seta:command testF
use axis 1344 439 100 0 axis#25
xform 0 1584 632
p 1392 656 200 0 1 seta:dev az
p 1392 608 200 0 1 setb:command
p 1392 560 200 0 1 setc:card 0
p 1392 496 200 0 1 setd:id 3
use misc 736 439 100 0 misc#22
xform 0 976 632
use pmacCommands 128 439 100 0 pmacCommands#21
xform 0 368 632
use pmacIF 736 887 100 0 pmacIF#18
xform 0 976 1080
p 768 1104 200 0 1 seta:axis el
p 768 1056 200 0 1 setb:CARD 1
p 768 1008 200 0 1 setc:DELAY_SEC 30
p 768 944 200 0 1 setd:M1 0
use pmacIF 128 887 100 0 pmacIF#17
xform 0 368 1080
p 160 1104 200 0 1 seta:axis az
p 160 1056 200 0 1 setb:CARD 0
p 160 1008 200 0 1 setc:DELAY_SEC 15
p 160 944 200 0 1 setd:M1 1
use xycom566T 1344 1335 100 0 xycom566T#16
xform 0 1584 1528
use xycom566M 736 1335 100 0 xycom566M#15
xform 0 976 1528
use xycom240 128 1335 100 0 xycom240#14
xform 0 368 1528
use time 1240 1736 100 0 time#6
xform 0 1584 1976
use statusData 632 1736 100 0 statusData#2
xform 0 976 1976
use axis 1952 439 100 0 axis#26
xform 0 2192 632
p 1984 656 200 0 1 seta:dev el
p 1984 608 200 0 1 setb:command
p 1984 560 200 0 1 setc:card 1
p 1984 496 200 0 1 setd:id 4
use logDataSyncClock 1576 1080 100 0 logDataSyncClock#28
xform 0 1816 1160
p 1657 1012 100 0 -1 set0:AZCARD 0
p 1663 971 100 0 -1 set1:ELCARD 1
p 1672 927 100 0 -1 set2:command logData
[comments]
