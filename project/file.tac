5
$a_0.1.1.1.0
$b_1.1.1.1.0
$d_2.1.2.2.0
$l_3.1.3.3.0
$e_4.1.4.2.0
1
#main.-1.-1.0
^ main:
t1 = 0
$a_0 = t1
t2 = 1
$b_1 = t2
t3 = $a_0
t4 = $b_1
t5 = t3 < t4
@if = t5 ^ LABEL1
t6 = 10
$d_2 = t6
^ LOOP_LABEL1:
t7 = $d_2
t8 = 20
t9 = t7 < t8
@if = t9 ^ LABEL2
t10 = 1
t11 = $d_2
t12 = t11 + t10
$d_2 = t12
t13 = 5
$l_3 = t13
JUMP ^ LOOP_LABEL1
^ LABEL2:
t14 = -1
$a_0 = t14
@output = $d_2
@output = $a_0
JUMP ^ END1
^ LABEL1:
t15 = 20
$e_4 = t15
t16 = -1
$a_0 = t16
t17 = -1
$b_1 = t17
^ END1:
t18 = $a_0
t19 = $b_1
t20 = t18 < t19
@if = t20 ^ LABEL3
t21 = 1
t22 = $a_0
t23 = t22 - t21
$a_0 = t23
^ LABEL3:
