[schematic2]
uniq 1
[tools]
[detail]
s 2096 -48 100 0 Andy Foster
s 2384 -80 200 0 MCS Level 0
[cell use]
use bc200tr -496 -296 -100 0 frame
xform 0 1184 1008
use mc 376 360 100 0 mc#0
xform 0 1168 1088
p 352 288 100 0 -1 setb:IDLE 0
p 352 256 100 0 -1 setc:PAUSED 1
p 352 224 100 0 -1 setd:BUSY 2
p 352 192 100 0 -1 sete:ERROR 3
p 512 286 100 0 -1 setf:MARK 0
p 512 254 100 0 -1 setg:CLEAR 1
p 512 222 100 0 -1 seth:PRESET 2
p 512 190 100 0 -1 seti:START 3
p 512 158 100 0 -1 setj:STOP 4
p 512 126 100 0 -1 setk:BRAKED 1
p 512 94 100 0 -1 setl:FALSE 0
p 512 62 100 0 -1 setm:TRUE 1
p 512 30 100 0 -1 setn:OFF 0
p 512 -2 100 0 -1 seto:IGNORING 0
p 512 -34 100 0 -1 setp:NOT_DATUMED 0
p 512 -66 100 0 -1 setq:ZERO 0
p 512 -98 100 0 -1 setr:VSM 2
p 720 286 100 0 -1 sets:STATIONARY 2
p 720 254 100 0 -1 sett:SLEWING 3
p 720 222 100 0 -1 setu:PARKED 5
p 720 190 100 0 -1 setv:GOOD 0
p 720 158 100 0 -1 setw:BAD 1
p 512 -130 100 0 -1 setx:SUBCMD_OFF 1
p 720 128 100 0 -1 sety:DISASSERT 1
p 720 96 100 0 -1 setz:ASSERT 2
p 349 322 100 0 -1 set0:mc $(top)
[comments]
