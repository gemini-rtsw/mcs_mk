[schematic2]
uniq 9
[tools]
[detail]
w 1366 2155 100 0 SLNK inhier.SLNK.P 1248 2144 1520 2144 eseqs.eseqs#0.SLNK
w 1942 2475 100 0 n#6 eseqs.eseqs#0.LNK1 1840 2464 2080 2464 hwout.hwout#3.outp
w 1894 2443 100 0 n#6 eseqs.eseqs#0.LNK2 1840 2432 1984 2432 1984 2464 junction
w 1462 2443 100 0 n#5 hwin.hwin#2.in 1376 2400 1440 2400 1440 2432 1520 2432 eseqs.eseqs#0.DOL2
w 1430 2475 100 0 n#4 hwin.hwin#1.in 1376 2464 1520 2464 eseqs.eseqs#0.DOL1
[cell use]
use inhier 1232 2103 100 0 SLNK
xform 0 1248 2144
use hwout 2080 2423 100 0 hwout#3
xform 0 2176 2464
p 2128 2400 100 0 -1 val(outp):$(top)activeC.IVAL .PP
use hwin 1184 2423 100 0 hwin#1
xform 0 1280 2464
p 1187 2456 100 0 -1 val(in):$(BUSY)
use hwin 1184 2359 100 0 hwin#2
xform 0 1280 2400
p 1187 2392 100 0 -1 val(in):$(IDLE)
use eseqs 1520 2055 100 0 eseqs#0
xform 0 1680 2304
p 1632 2512 100 0 1 DLY2:1.0
p 1632 2048 100 1024 -1 name:$(top)$(command)SetBusyIdle
use bc200tr 720 664 -100 0 frame
xform 0 2400 1968
[comments]
