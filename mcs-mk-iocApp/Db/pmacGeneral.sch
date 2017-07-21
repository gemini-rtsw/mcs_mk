[schematic2]
uniq 2
[tools]
[detail]
w 352 2258 100 0 n#1 hwin.hwin#33.in 320 2256 432 2256 estringins.estringins#63.INP
[cell use]
use bc200tr -96 -104 -100 0 frame
xform 0 1584 1200
use pmacInit 1080 1544 100 0 pmacInit#118
xform 0 1296 1648
use pmacProgStatus 920 1864 100 0 pmacProgStatus#112
xform 0 1224 1952
p 1096 1863 100 0 1 set0:top $(top)$(axis)
use esirs 1880 1576 100 0 esirs#110
xform 0 2064 1728
p 1968 1568 100 1024 -1 name:$(top)$(axis)pmacSir
p 1968 1742 100 0 1 FTVL:STRING
use ecars 1880 1928 100 0 ecars#109
xform 0 2016 2096
p 1968 1920 100 1024 -1 name:$(top)$(axis)pmacC
use pmacUpDown 1096 2056 100 0 pmacUpDown#108
xform 0 1224 2176
p 1100 2091 100 0 1 set0:top $(top)$(axis)
use hwin 152 2216 100 0 hwin#33
xform 0 224 2256
p 112 2286 100 0 -1 val(in):#C$(CARD) S2
use pmacLogin 216 1864 100 0 pmacLogin#85
xform 0 416 1944
use estringins 456 2152 100 0 estringins#63
xform 0 560 2224
p 448 2318 100 0 1 DTYP:PMAC-VME ASCII
p 544 2144 100 1024 -1 name:$(top)$(axis)Mailbox
p 432 2318 100 0 0 VAL:
[comments]
