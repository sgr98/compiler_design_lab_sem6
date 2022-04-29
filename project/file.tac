3
$i_0.1.1.1.0
$n_1.1.1.1.0
$sum_2.1.1.1.0
1
#main.-1.-1.0
^ main:
t1 = 2
$i_0 = t1
@input = $n_1
t2 = 0
$sum_2 = t2
^ LOOP_LABEL1:
t3 = $i_0
t4 = $n_1
t5 = t3 <= t4
@if = t5 ^ LABEL1
t6 = $i_0
t7 = $sum_2
t8 = t7 + t6
$sum_2 = t8
t9 = 1
t10 = $i_0
t11 = t10 + t9
$i_0 = t11
JUMP ^ LOOP_LABEL1
^ LABEL1:
@output = $sum_2
