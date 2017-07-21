[schematic2]
uniq 15
[tools]
[detail]
w 3768 4587 100 0 FLNK GISassert.GISassert#0.OK 3488 4576 4096 4576 outhier.FLNK.p
w 2952 4555 100 0 n#13 carBusy.carBusy#1.FLNK 2912 4544 3040 4544 GISassert.GISassert#0.SLNK
w 3582 4299 100 0 n#8 GISassert.GISassert#0.FAIL 3488 4512 3552 4512 3552 4288 3648 4288 carError.carError#7.SLNK
w 2334 4555 100 0 SLNK inhier.SLNK.P 2240 4544 2464 4544 carBusy.carBusy#1.SLNK
[cell use]
use carError 3648 4135 100 0 carError#7
xform 0 3872 4272
p 3712 4112 200 0 1 seta:errno 1
use outhier 4064 4535 100 0 FLNK
xform 0 4080 4576
use inhier 2224 4503 100 0 SLNK
xform 0 2240 4544
use carBusy 2464 4391 100 0 carBusy#1
xform 0 2688 4528
use GISassert 3040 4455 100 0 GISassert#0
xform 0 3264 4536
use bc200tr 1792 2984 -100 0 frame
xform 0 3472 4288
[comments]
