[schematic2]
uniq 6
[tools]
[detail]
[cell use]
use estringins 280 1480 100 0 estringins#5
xform 0 384 1552
p 368 1472 100 1024 -1 name:$(top)logrecord
use ebis 280 1800 100 0 ebis#4
xform 0 384 1872
p 272 1694 100 0 1 ONAM:SIMULATED
p 368 1792 100 1024 -1 name:$(top)TIME:intSimulate
p 272 1726 100 0 1 ZNAM:REAL
use esirs 280 2024 100 0 esirs#3
xform 0 464 2176
p 368 2016 100 1024 -1 name:$(top)TIME:health
p 384 2142 100 0 0 SNAM:
use bc200tr -144 -24 -100 0 frame
xform 0 1536 1280
use ebis 912 1816 100 0 ebis#7
xform 0 1016 1888
p 904 1710 100 0 1 ONAM:ON
p 1000 1808 100 1024 1 name:$(top)TIME:debug
p 904 1742 100 0 1 ZNAM:OFF
[comments]
