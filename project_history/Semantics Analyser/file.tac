5
$a_0.1.1.1.0
$g_1.4.1.1.0
$a_2.1.2.2.0
$b_3.1.2.2.0
$a_4.1.3.3.0
1
#main.-1.-1.0
^ main:
t1 = $a_0
t2 = 5
t3 = t1 > t2
$g_1 = t3
t4 = $a_0
t5 = 10
t6 = t4 < t5
@if = t6 ^ LABEL1
t7 = $b_3
t8 = 0
t9 = t7 >= t8
@if = t9 ^ LABEL2
t10 = 1
t11 = $a_4
t12 = t11 + t10
$a_4 = t12
JUMP ^ END1
^ LABEL2:
t13 = false
$g_1 = t13
^ END1:
t14 = true
$g_1 = t14
^ LABEL1:
t15 = 10
$a_0 = t15
