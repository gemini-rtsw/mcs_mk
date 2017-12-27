[schematic2]
uniq 21
[tools]
[detail]
w 426 1579 -100 0 c inhier.c#203.P 240 1568 672 1568 egenSub.elAxisHealth.INPJ
w 426 1835 -100 0 c inhier.c#202.P 240 1824 672 1824 egenSub.elAxisHealth.INPF
w 426 1899 -100 0 c inhier.c#201.P 240 1888 672 1888 egenSub.elAxisHealth.INPE
w 426 1963 -100 0 c inhier.c#200.P 240 1952 672 1952 egenSub.elAxisHealth.INPD
w 426 2027 -100 0 c inhier.c#199.P 240 2016 672 2016 egenSub.elAxisHealth.INPC
w 426 2091 -100 0 c inhier.c#198.P 240 2080 672 2080 egenSub.elAxisHealth.INPB
w 426 2155 -100 0 c inhier.c#197.P 240 2144 672 2144 egenSub.elAxisHealth.INPA
w 426 555 100 0 n#1 inhier.c#187.P 240 544 672 544 egenSub.azAxisHealth.INPJ
w 2002 1163 100 0 n#2 esirs.AzAxis.FLNK 1760 1152 2304 1152 outhier.FLNK.p
w 2114 1019 100 0 n#3 esirs.AzAxis.OMSS 1760 1088 1984 1088 1984 1008 2304 1008 outhier.CMESS.p
w 2114 1243 100 0 n#4 esirs.AzAxis.VAL 1760 1120 1984 1120 1984 1232 2304 1232 outhier.CVAL.p
w 2114 2011 100 0 n#5 esirs.ElAxis.OMSS 1760 2112 1984 2112 1984 2000 2304 2000 outhier.CWMESS.p
w 2114 2219 100 0 n#6 esirs.ElAxis.VAL 1760 2144 1984 2144 1984 2208 2304 2208 outhier.CWVAL.p
w 978 1291 100 0 n#7 esirs.ElAxis.FLNK 1760 2176 1856 2176 1856 1280 160 1280 160 448 672 448 egenSub.azAxisHealth.SLNK
w 426 811 100 0 n#8 inhier.c#165.P 240 800 672 800 egenSub.azAxisHealth.INPF
w 426 875 100 0 n#9 inhier.c#164.P 240 864 672 864 egenSub.azAxisHealth.INPE
w 426 939 100 0 n#10 inhier.c#163.P 240 928 672 928 egenSub.azAxisHealth.INPD
w 426 1003 100 0 n#11 inhier.c#162.P 240 992 672 992 egenSub.azAxisHealth.INPC
w 426 1067 100 0 n#12 inhier.c#161.P 240 1056 672 1056 egenSub.azAxisHealth.INPB
w 426 1131 100 0 n#13 inhier.c#160.P 240 1120 672 1120 egenSub.azAxisHealth.INPA
w 1210 1003 100 0 n#14 egenSub.azAxisHealth.FLNK 960 416 1136 416 1136 992 1344 992 esirs.AzAxis.SLNK
w 1210 1163 100 0 n#15 egenSub.azAxisHealth.VALB 960 1088 1136 1088 1136 1152 1344 1152 esirs.AzAxis.INP
w 1210 2027 100 0 n#16 egenSub.elAxisHealth.FLNK 960 1440 1136 1440 1136 2016 1344 2016 esirs.ElAxis.SLNK
w 1210 2187 100 0 n#17 egenSub.elAxisHealth.VALB 960 2112 1136 2112 1136 2176 1344 2176 esirs.ElAxis.INP
w 426 1483 100 0 n#18 inhier.SLNK.P 240 1472 672 1472 egenSub.elAxisHealth.SLNK
w 1122 1131 100 0 n#19 egenSub.azAxisHealth.OUTA 960 1120 1344 1120 esirs.AzAxis.IMSS
w 1122 2155 100 0 n#20 egenSub.elAxisHealth.OUTA 960 2144 1344 2144 esirs.ElAxis.IMSS
s 848 2448 200 0 This schematic generates overall health values for Axis
s 2352 2576 100 0 $Id: mcMotorHealth.sch,v 1.2 2001/08/20 16:54:53 gemvx Exp $
s 2624 384 100 0 Combine MCS health records
s 2368 384 100 0 Gemini
s 2368 352 100 0 Observatory
[cell use]
use bc200tr -224 104 -100 0 frame
xform 0 1456 1408
use inhier 224 1527 100 0 c#203
xform 0 240 1568
use inhier 224 1783 100 0 c#202
xform 0 240 1824
use inhier 224 1847 100 0 c#201
xform 0 240 1888
use inhier 224 1911 100 0 c#200
xform 0 240 1952
use inhier 224 1975 100 0 c#199
xform 0 240 2016
use inhier 224 2039 100 0 c#198
xform 0 240 2080
use inhier 224 2103 100 0 c#197
xform 0 240 2144
use inhier 224 503 100 0 c#187
xform 0 240 544
use inhier 224 759 100 0 c#165
xform 0 240 800
use inhier 224 823 100 0 c#164
xform 0 240 864
use inhier 224 887 100 0 c#163
xform 0 240 928
use inhier 224 951 100 0 c#162
xform 0 240 992
use inhier 224 1015 100 0 c#161
xform 0 240 1056
use inhier 224 1079 100 0 c#160
xform 0 240 1120
use inhier 224 1431 100 0 SLNK
xform 0 240 1472
use egenSub 672 1383 100 0 elAxisHealth
xform 0 816 1808
p 624 2240 100 0 -1 DESC:Health value for the Elevation Axis
p 449 1157 100 0 0 FTA:LONG
p 449 1157 100 0 0 FTB:LONG
p 449 1125 100 0 0 FTC:LONG
p 449 1093 100 0 0 FTD:LONG
p 449 1061 100 0 0 FTE:LONG
p 449 997 100 0 0 FTF:LONG
p 449 901 100 0 0 FTJ:LONG
p 449 1157 100 0 0 FTVA:STRING
p 449 1157 100 0 0 FTVB:STRING
p 736 1328 100 0 1 SNAM:mcMotorHealth
p 288 2160 100 0 -1 def(INPA):$(mc)elmotstat2:2:FFE
p 288 2096 100 0 -1 def(INPB):$(mc)elmotstat2:2:AFE
p 288 2032 100 0 -1 def(INPC):$(mc)elmotstat1:2:PELS
p 288 1968 100 0 -1 def(INPD):$(mc)elmotstat1:2:NELS
p 288 1904 100 0 -1 def(INPE):$(mc)elmotstat1:2:DBE
p 288 1840 100 0 -1 def(INPF):$(mc)elmotstat2:2:WFE
p 288 1584 100 0 1 def(INPJ):$(mc)elDriveCondition
p 960 2090 75 0 -1 pproc(OUTB):NPP
use egenSub 672 359 100 0 azAxisHealth
xform 0 816 784
p 624 1216 100 0 -1 DESC:Health value for the Azimuth Axis
p 449 133 100 0 0 FTA:LONG
p 449 133 100 0 0 FTB:LONG
p 449 101 100 0 0 FTC:LONG
p 449 69 100 0 0 FTD:LONG
p 449 37 100 0 0 FTE:LONG
p 449 -27 100 0 0 FTF:LONG
p 449 -123 100 0 0 FTJ:LONG
p 449 133 100 0 0 FTVA:STRING
p 449 133 100 0 0 FTVB:STRING
p 736 304 100 0 1 SNAM:mcMotorHealth
p 288 1136 100 0 -1 def(INPA):$(mc)azmotstat2:2:FFE
p 288 1072 100 0 -1 def(INPB):$(mc)azmotstat2:2:AFE
p 288 1008 100 0 -1 def(INPC):$(mc)azmotstat1:2:PELS
p 288 944 100 0 -1 def(INPD):$(mc)azmotstat1:2:NELS
p 288 880 100 0 -1 def(INPE):$(mc)azmotstat1:2:DBE
p 288 816 100 0 -1 def(INPF):$(mc)azmotstat2:2:WFE
p 288 560 100 0 1 def(INPJ):$(mc)azDriveCondition
p 960 1066 75 0 -1 pproc(OUTB):NPP
use outhier 2272 1111 100 0 FLNK
xform 0 2288 1152
use outhier 2272 967 100 0 CMESS
xform 0 2288 1008
use outhier 2272 1191 100 0 CVAL
xform 0 2288 1232
use outhier 2272 1959 100 0 CWMESS
xform 0 2288 2000
use outhier 2272 2167 100 0 CWVAL
xform 0 2288 2208
use esirs 1344 903 100 0 AzAxis
xform 0 1552 1056
p 1456 1216 100 0 -1 DESC:Health of Azimuth Axis
p 1280 640 100 0 0 FDSC:Overall health of Azimuth Axis
p 1440 992 100 0 1 FTVL:STRING
p 1456 896 100 1024 0 name:$(top)AzAxis
use esirs 1344 1927 100 0 ElAxis
xform 0 1552 2080
p 1456 2240 100 0 -1 DESC:Health of Elevation Axis
p 1280 1664 100 0 0 FDSC:Overall health of the Elevation Axis
p 1440 2016 100 0 1 FTVL:STRING
p 1456 1920 100 1024 0 name:$(top)ElAxis
[comments]
