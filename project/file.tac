5
$n_0.1.1.1.1
$i_1.1.1.1.1
$mul_2.1.1.1.1
$n_3.1.3.1.0
$mul_4.1.3.1.0
2
#fact.1.1.1
#main.-1.-1.0
^ FUNC_LABEL1:
t1 = 1
$i_1 = t1
t2 = 1
$mul_2 = t2
^ LOOP_LABEL1:
t3 = $i_1
t4 = $n_0
t5 = t3 <= t4
@if = t5 ^ LABEL1
t6 = $i_1
t7 = $mul_2
t8 = t7 * t6
$mul_2 = t8
t9 = 1
t10 = $i_1
t11 = t10 + t9
$i_1 = t11
JUMP ^ LOOP_LABEL1
^ LABEL1:
t12 = $mul_2
v1 = t12
JR ^ RA
^ main:
@input = $n_3
t13 = $n_3
$n_0 = t13
JAL ^ FUNC_LABEL1
t14 = v1
$mul_4 = t14
@output = $mul_4
