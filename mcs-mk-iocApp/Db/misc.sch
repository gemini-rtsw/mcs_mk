[schematic2]
uniq 31
[tools]
[detail]
w 1256 1826 100 0 n#1 hwin.hwin#148.in 1184 1824 1376 1824 egenSubD.egenSubD#105.INPH
w 1828 587 100 2 n#2 hwin.hwin#145.in 1824 592 1824 592 egenSub.egenSub#128.INPE
w 1828 331 100 2 n#3 hwin.hwin#143.in 1824 336 1824 336 egenSub.egenSub#128.INPI
w 1828 395 100 2 n#4 egenSub.egenSub#128.INPH 1824 400 1824 400 hwin.hwin#139.in
w 1828 459 100 2 n#5 egenSub.egenSub#128.INPG 1824 464 1824 464 hwin.hwin#140.in
w 1828 523 100 2 n#6 egenSub.egenSub#128.INPF 1824 528 1824 528 hwin.hwin#141.in
w 1828 651 100 2 n#7 egenSub.egenSub#128.INPD 1824 656 1824 656 hwin.hwin#131.in
w 1828 715 100 2 n#8 egenSub.egenSub#128.INPC 1824 720 1824 720 hwin.hwin#132.in
w 1828 779 100 2 n#9 egenSub.egenSub#128.INPB 1824 784 1824 784 hwin.hwin#133.in
w 1828 843 100 2 n#10 egenSub.egenSub#128.INPA 1824 848 1824 848 hwin.hwin#134.in
w 1250 1867 100 0 n#11 hwin.hwin#101.in 1184 1856 1376 1856 egenSubD.egenSubD#105.INPG
w 996 411 100 2 n#12 hwin.hwin#98.in 992 416 992 416 egenSub.egenSub#72.INPJ
w 996 731 100 2 n#13 hwin.hwin#96.in 992 736 992 736 egenSub.egenSub#72.INPE
w 996 795 100 2 n#14 hwin.hwin#92.in 992 800 992 800 egenSub.egenSub#72.INPD
w 996 859 100 2 n#15 hwin.hwin#90.in 992 864 992 864 egenSub.egenSub#72.INPC
w 996 923 100 2 n#16 hwin.hwin#88.in 992 928 992 928 egenSub.egenSub#72.INPB
w 996 987 100 2 n#17 hwin.hwin#73.in 992 992 992 992 egenSub.egenSub#72.INPA
w 1896 1739 100 0 n#18 egenSubD.egenSubD#105.VALD 1664 1856 1824 1856 1824 1728 2016 1728 efanouts.efanouts#47.SELL
w 1752 1323 100 0 n#19 egenSubD.egenSubD#105.FLNK 1664 1312 1888 1312 1888 1648 1968 1648 efanouts.efanouts#47.SLNK
w 2264 1707 100 0 n#20 efanouts.efanouts#47.LNK2 2208 1696 2368 1696 2368 1488 2432 1488 carIdle.carIdle#54.SLNK
w 1720 1890 100 0 n#21 egenSubD.egenSubD#105.OUTC 1664 1888 1824 1888 hwout.hwout#61.outp
w 1720 1954 100 0 n#22 egenSubD.egenSubD#105.OUTB 1664 1952 1824 1952 hwout.hwout#60.outp
w 2296 1739 100 0 n#23 efanouts.efanouts#47.LNK1 2208 1728 2432 1728 carIdle.carIdle#50.SLNK
w 1720 2018 100 0 n#24 egenSubD.egenSubD#105.OUTA 1664 2016 1824 2016 hwout.hwout#43.outp
w 1256 1890 100 0 n#25 hwin.hwin#36.in 1184 1888 1376 1888 egenSubD.egenSubD#105.INPF
w 1256 1922 100 0 n#26 hwin.hwin#35.in 1184 1920 1376 1920 egenSubD.egenSubD#105.INPE
w 1256 1954 100 0 n#27 hwin.hwin#34.in 1184 1952 1376 1952 egenSubD.egenSubD#105.INPD
w 1256 1986 100 0 n#28 hwin.hwin#33.in 1184 1984 1376 1984 egenSubD.egenSubD#105.INPC
w 1256 2018 100 0 n#29 hwin.hwin#32.in 1184 2016 1376 2016 egenSubD.egenSubD#105.INPB
w 1256 2050 100 0 n#30 hwin.hwin#31.in 1184 2048 1376 2048 egenSubD.egenSubD#105.INPA
[cell use]
use bc200tr -160 -88 -100 0 frame
xform 0 1520 1216
use hwin 1016 1784 100 0 hwin#148
xform 0 1088 1824
p 784 1822 100 0 -1 val(in):$(top)pmacServoTol
use hwin 1016 1816 100 0 hwin#101
xform 0 1088 1856
p 736 1856 100 0 -1 val(in):$(top)azPmacPosError
use hwin 800 375 100 0 hwin#98
xform 0 896 416
p 560 416 100 0 -1 val(in):$(top)elcapturedVel
use hwin 800 695 100 0 hwin#96
xform 0 896 736
p 560 736 100 0 -1 val(in):$(top)elcapturedPos
use hwin 800 759 100 0 hwin#92
xform 0 896 800
p 544 800 100 0 -1 val(in):$(top)elcapturedTime
use hwin 800 823 100 0 hwin#90
xform 0 896 864
p 560 864 100 0 -1 val(in):$(top)azcapturedVel
use hwin 800 887 100 0 hwin#88
xform 0 896 928
p 560 928 100 0 -1 val(in):$(top)azcapturedPos
use hwin 1016 1848 100 0 hwin#36
xform 0 1088 1888
p 784 1886 100 0 -1 val(in):$(top)velocityTol
use hwin 1016 1880 100 0 hwin#35
xform 0 1088 1920
p 784 1918 100 0 -1 val(in):$(top)positionTol
use hwin 1016 1912 100 0 hwin#34
xform 0 1088 1952
p 736 1952 100 0 -1 val(in):$(top)elPmacPosError
use hwin 1016 1944 100 0 hwin#33
xform 0 1088 1984
p 784 1982 100 0 -1 val(in):$(top)FollowL
use hwin 1016 1976 100 0 hwin#32
xform 0 1088 2016
p 784 2014 100 0 -1 val(in):$(top)elPosError
use hwin 1016 2008 100 0 hwin#31
xform 0 1088 2048
p 784 2046 100 0 -1 val(in):$(top)azPosError
use hwin 800 951 100 0 hwin#73
xform 0 896 992
p 544 992 100 0 -1 val(in):$(top)azcapturedTime
use hwin 1632 615 100 0 hwin#131
xform 0 1728 656
p 1376 656 100 0 -1 val(in):$(top)azCurrentVel
use hwin 1632 679 100 0 hwin#132
xform 0 1728 720
p 1392 720 100 0 -1 val(in):$(top)azCurrentPos
use hwin 1632 743 100 0 hwin#133
xform 0 1728 784
p 1392 784 100 0 -1 val(in):$(top)azPmacDemandPos
use hwin 1632 807 100 0 hwin#134
xform 0 1728 848
p 1376 848 100 0 -1 val(in):$(top)trackingAZDemand
use hwin 1632 359 100 0 hwin#139
xform 0 1728 400
p 1376 400 100 0 -1 val(in):$(top)elCurrentVel
use hwin 1632 423 100 0 hwin#140
xform 0 1728 464
p 1392 464 100 0 -1 val(in):$(top)elCurrentPos
use hwin 1632 487 100 0 hwin#141
xform 0 1728 528
p 1392 528 100 0 -1 val(in):$(top)elPmacDemandPos
use hwin 1656 296 100 0 hwin#143
xform 0 1728 336
p 1424 334 100 0 -1 val(in):$(top)FollowL
use hwin 1632 551 100 0 hwin#145
xform 0 1728 592
p 1376 592 100 0 -1 val(in):$(top)trackingELDemand
use egenSub 1016 232 100 0 egenSub#72
xform 0 1136 656
p 1328 1072 100 0 1 FTVA:DOUBLE
p 1072 608 100 0 0 FTVB:STRING
p 1328 1040 100 0 1 NOVA:6
p 1088 1006 100 0 0 PINI:NO
p 704 926 100 0 0 SCAN:Passive
p 1056 1086 100 0 1 SNAM:timeStamp
p 1104 224 100 1024 -1 name:$(top)timeStampedPos
p 944 426 75 0 -1 pproc(INPJ):PP
use egenSub 216 1192 100 0 egenSub#1
xform 0 336 1616
p 272 1598 100 0 1 FTVA:STRING
p 272 1568 100 0 1 FTVB:STRING
p 288 1966 100 0 1 PINI:YES
p 256 2046 100 0 1 SNAM:pwdCommand
p 304 1184 100 1024 -1 name:$(top)pwdCommand
use egenSub 160 199 100 0 egenSub#46
xform 0 304 624
p 224 1056 100 0 1 SNAM:getTime
p 272 192 100 1024 -1 name:$(top)getTime
use egenSub 1848 88 100 0 egenSub#128
xform 0 1968 512
p 1601 -139 100 0 0 FTA:DOUBLE
p 1601 -363 100 0 0 FTI:LONG
p 2160 928 100 0 1 FTVA:DOUBLE
p 1904 464 100 0 0 FTVB:STRING
p 1601 -491 100 0 0 NOA:1
p 1601 -619 100 0 0 NOE:1
p 2160 896 100 0 1 NOVA:6
p 1920 862 100 0 0 PINI:NO
p 1536 638 100 0 0 PREC:14
p 1536 782 100 0 0 SCAN:.1 second
p 1888 942 100 0 1 SNAM:trajLog
p 1936 80 100 1024 -1 name:$(top)trajLog
p 1776 282 75 0 -1 pproc(INPJ):PP
use carIdle 2432 1335 100 0 carIdle#54
xform 0 2656 1472
p 2528 1424 100 0 1 seta:dev el
p 2528 1392 100 0 1 setb:command inpos
use carIdle 2432 1575 100 0 carIdle#50
xform 0 2656 1712
p 2528 1664 100 0 1 seta:dev az
p 2528 1632 100 0 1 setb:command inpos
use egenSubD 1376 1255 100 0 egenSubD#105
xform 0 1520 1680
p 1472 2016 100 0 1 FTA:DOUBLE
p 1472 1984 100 0 1 FTB:DOUBLE
p 1472 1952 100 0 1 FTC:DOUBLE
p 1472 1920 100 0 1 FTD:DOUBLE
p 1472 1888 100 0 1 FTE:DOUBLE
p 1472 1856 100 0 1 FTF:DOUBLE
p 1472 1824 100 0 1 FTG:DOUBLE
p 1472 1792 100 0 1 FTH:DOUBLE
p 1472 1760 100 0 1 FTI:LONG
p 1472 1664 100 0 1 FTK:LONG
p 1472 1632 100 0 1 FTL:LONG
p 1472 1520 100 0 1 FTVA:LONG
p 1472 1488 100 0 1 FTVB:LONG
p 1472 1456 100 0 1 FTVC:LONG
p 1472 1424 100 0 1 FTVD:LONG
p 1440 2128 100 0 1 SCAN:.5 second
p 1440 2096 100 0 1 SNAM:inPositionCalc
p 1520 1232 100 1024 -1 name:$(top)InPositionCalc
use timeStamp 2304 327 100 0 timeStamp#103
xform 0 2584 400
p 2324 300 200 0 1 seta:azcard 0
p 2320 240 200 0 1 setb:elcard 1
p 2601 303 200 0 1 set0:top $(top)
use eStop 2304 487 100 0 eStop#71
xform 0 2480 608
use balance 2304 855 100 0 balance#69
xform 0 2480 976
p 2304 816 200 0 1 seta:dev el
p 2304 752 200 0 1 setb:card 1
use hwout 1848 1976 100 0 hwout#43
xform 0 1920 2016
p 2032 2016 100 0 -1 val(outp):$(top)inPositionAz .PP
use hwout 1848 1912 100 0 hwout#60
xform 0 1920 1952
p 2032 1952 100 0 -1 val(outp):$(top)inPositionEl .PP
use hwout 1848 1848 100 0 hwout#61
xform 0 1920 1888
p 2032 1888 100 0 -1 val(outp):$(top)inPosition .PP
use efanouts 1968 1511 100 0 efanouts#47
xform 0 2088 1664
p 2064 1808 100 0 1 SELM:Mask
p 2080 1504 100 1024 -1 name:$(top)inPositionFanout
p 2240 1728 75 1280 -1 pproc(LNK1):PP
p 2240 1696 75 1280 -1 pproc(LNK2):PP
use estringouts 216 2152 100 0 estringouts#0
xform 0 320 2224
p 304 2144 100 1024 -1 name:$(top)savePath
[comments]
