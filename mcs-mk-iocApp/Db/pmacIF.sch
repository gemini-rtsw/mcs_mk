[schematic2]
uniq 1
[tools]
[detail]
[cell use]
use bc200tr -80 -104 -100 0 frame
xform 0 1600 1200
use pmacMotor1servo 192 839 100 0 pmacMotor1servo#14
xform 0 448 960
p 192 800 200 0 1 seta:ADDRESS1 X:$003D
p 192 752 200 0 1 setb:NUM 1:
p 192 704 200 0 1 setc:ID motstat1:
use VE 1152 1695 100 0 VE#13
xform 0 1520 1952
use pmacGlobalStatus 2200 992 100 0 pmacGlobalStatus#10
xform 0 2544 1248
p 2240 1140 200 0 1 seta:ADDRESS1 X:$0003
p 2240 1076 200 0 1 setb:ADDRESS2 Y:$0003
use pmacCSStatus 1160 1128 100 0 pmacCSStatus#4
xform 0 1504 1384
p 1152 1252 200 0 1 seta:ADDRESS1 Y:$D0B8
p 1152 1188 200 0 1 setb:ADDRESS2 Y:$D0CB
p 1152 1140 200 0 1 setc:NUM 2:
use pmacMotorStatus 48 1136 200 0 pmacMotorStatus#3
xform 0 392 1392
p 184 1260 200 0 1 seta:ADDRESS1 X:$0079
p 184 1212 200 0 1 setb:ADDRESS2 Y:$D0B6
p 184 1164 200 0 1 setc:NUM 2:
use pmacGeneral 216 1688 100 0 pmacGeneral#2
xform 0 560 1944
p 240 1820 200 0 1 seta:motor 1
p 240 1756 200 0 1 setb:SETSC_ADDR Y:$07F1
p 599 1812 200 0 -1 set0:card $(CARD)
[comments]
