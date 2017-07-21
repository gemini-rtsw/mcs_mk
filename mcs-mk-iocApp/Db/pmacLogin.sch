[schematic2]
uniq 26
[tools]
[detail]
w 1144 1666 100 0 n#25 hwin.hwin#24.in 1120 1664 1216 1664 1216 1696 1280 1696 egenSub.egenSub#1.INPC
w 1160 2658 100 0 n#23 hwin.hwin#22.in 1152 2656 1216 2656 1216 2720 1280 2720 egenSub.egenSub#0.INPC
w 1176 1762 100 0 n#21 hwin.hwin#20.in 1120 1760 1280 1760 egenSub.egenSub#1.INPB
w 1192 2786 100 0 n#19 hwin.hwin#18.in 1152 2784 1280 2784 egenSub.egenSub#0.INPB
w 1640 1762 100 0 n#17 egenSub.egenSub#1.OUTB 1568 1760 1760 1760 hwout.hwout#16.outp
w 1640 2786 100 0 n#15 egenSub.egenSub#0.OUTB 1568 2784 1760 2784 hwout.hwout#14.outp
w 1192 2850 100 0 n#12 hwin.hwin#8.in 1152 2848 1280 2848 egenSub.egenSub#0.INPA
w 1176 1826 100 0 n#11 hwin.hwin#10.in 1120 1824 1280 1824 egenSub.egenSub#1.INPA
w 1646 1826 100 0 n#7 egenSub.egenSub#1.OUTA 1568 1824 1760 1824 hwout.hwout#6.outp
w 1646 2850 100 0 n#5 egenSub.egenSub#0.OUTA 1568 2848 1760 2848 hwout.hwout#4.outp
[cell use]
use hwin 952 1624 100 0 hwin#24
xform 0 1024 1664
p 912 1614 100 0 -1 val(in):$(top)debugLevelL
use hwin 984 2616 100 0 hwin#22
xform 0 1056 2656
p 928 2606 100 0 -1 val(in):$(top)debugLevelL
use hwin 952 1720 100 0 hwin#20
xform 0 1024 1760
p 880 1710 100 0 -1 val(in):$(top)$(axis)Mailbox.DISA
use hwin 984 2744 100 0 hwin#18
xform 0 1056 2784
p 864 2734 100 0 -1 val(in):$(top)$(axis)Mailbox.DISA
use hwin 984 2808 100 0 hwin#8
xform 0 1056 2848
p 963 2840 100 0 -1 val(in):$(CARD)
use hwin 952 1784 100 0 hwin#10
xform 0 1024 1824
p 931 1816 100 0 -1 val(in):$(CARD)
use hwout 1784 2808 100 0 hwout#4
xform 0 1856 2848
p 1808 2894 100 0 -1 val(outp):$(top)$(axis)AccessL.VAL .PP
use hwout 1784 1784 100 0 hwout#6
xform 0 1856 1824
p 1808 1870 100 0 -1 val(outp):$(top)$(axis)AccessL.VAL .PP
use hwout 1784 2744 100 0 hwout#14
xform 0 1856 2784
p 1968 2782 100 0 -1 val(outp):$(top)$(axis)Mailbox.DISA
use hwout 1784 1720 100 0 hwout#16
xform 0 1856 1760
p 1984 1758 100 0 -1 val(outp):$(top)$(axis)Mailbox.DISA
use egenSub 1304 2088 100 0 egenSub#0
xform 0 1424 2512
p 1056 2302 100 0 0 FTVJ:DOUBLE
p 1392 2080 100 1024 -1 name:$(top)$(axis)Login
p 1328 2942 100 0 1 SNAM:pmacLogin
p 1360 2766 100 0 1 FTVA:LONG
p 1376 2846 100 0 1 FTA:LONG
p 1360 2702 100 0 1 FTJ:STRING
p 1360 2734 100 0 1 FTVB:LONG
p 1376 2814 100 0 1 FTB:LONG
p 1360 2670 100 0 1 FTC:LONG
use egenSub 1304 1064 100 0 egenSub#1
xform 0 1424 1488
p 1088 1262 100 0 0 FTVJ:DOUBLE
p 1392 1056 100 1024 -1 name:$(top)$(axis)Logout
p 1344 1934 100 0 1 SNAM:pmacLogout
p 1360 1758 100 0 1 FTVA:LONG
p 1376 1838 100 0 1 FTA:LONG
p 1376 1438 100 0 1 PINI:YES
p 1360 1726 100 0 1 FTVB:LONG
p 1376 1806 100 0 1 FTB:LONG
p 1360 1694 100 0 1 FTC:LONG
use bc200tr 752 648 -100 0 frame
xform 0 2432 1952
[comments]
