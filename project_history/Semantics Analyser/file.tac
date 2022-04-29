3
$a_0.1.1.1.0
$n_1.1.1.1.0
$i_2.1.1.1.0
1
#main.-1.-1.0
t1 = 0
$a_0 = t1
t2 = 2
$n_1 = t2
t3 = 0
$i_2 = t3
^ LOOP_LABEL1:
t4 = $i_2
t5 = $n_1
t6 = t4 < t5
@if = t6 ^ LABEL1
t7 = $i_2
t8 = $a_0
t9 = t8 + t7
$a_0 = t9
t10 = 1
t11 = $i_2
t12 = t11 + t10
$i_2 = t12
JUMP ^ LOOP_LABEL1
^ LABEL1:
t13 = 5
t14 = $n_1
t15 = t14 - t13
$n_1 = t15
