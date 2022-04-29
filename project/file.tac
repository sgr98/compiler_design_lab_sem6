3
$a_0.1.1.1.0
$b_1.1.1.1.0
$c_2.1.1.1.0
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
t6 = -1
$a_0 = t6
^ LABEL1:
t7 = $a_0
t8 = $b_1
t9 = t7 > t8
@if = t9 ^ LABEL2
t10 = -1
$b_1 = t10
^ LABEL2:
t11 = 5
$c_2 = t11
t12 = $a_0
t13 = $c_2
t14 = t12 > t13
@if = t14 ^ LABEL3
t15 = -1
$c_2 = t15
^ LABEL3:
