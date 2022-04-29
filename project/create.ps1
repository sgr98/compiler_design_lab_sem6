Param (
    $val
)

# ########################################
# Normal Programs
# ########################################

If(($val -ge 0) -and ($val -lt 100)) {
    Write-Host "||||||||||||||||||||||||||||||||||||||" -ForegroundColor Blue
    Write-Host "NON ERROR SCRIPTS" -ForegroundColor Blue
}

If(($val -eq 0) -or ($val -eq 1)) {
    Write-Host ""
    Write-Host "1" -ForegroundColor Green
    Write-Host "arithmetic.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Expression/arithmetic.xvgs
}
If(($val -eq 0) -or ($val -eq 2)) {
    Write-Host ""
    Write-Host "2" -ForegroundColor Green
    Write-Host "character.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Expression/character.xvgs
}
If(($val -eq 0) -or ($val -eq 3)) {
    Write-Host ""
    Write-Host "3" -ForegroundColor Green
    Write-Host "logical.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Expression/logical.xvgs
}
If(($val -eq 0) -or ($val -eq 4)) {
    Write-Host ""
    Write-Host "4" -ForegroundColor Green
    Write-Host "e.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Expression/e.xvgs
}
If(($val -eq 0) -or ($val -eq 5)) {
    Write-Host ""
    Write-Host "5" -ForegroundColor Green
    Write-Host "cond1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond1.xvgs
}
If(($val -eq 0) -or ($val -eq 6)) {
    Write-Host ""
    Write-Host "6" -ForegroundColor Green
    Write-Host "cond2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond2.xvgs
}
If(($val -eq 0) -or ($val -eq 7)) {
    Write-Host ""
    Write-Host "7" -ForegroundColor Green
    Write-Host "cond3.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond3.xvgs
}
If(($val -eq 0) -or ($val -eq 8)) {
    Write-Host ""
    Write-Host "8" -ForegroundColor Green
    Write-Host "cond4.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond4.xvgs
}
If(($val -eq 0) -or ($val -eq 9)) {
    Write-Host ""
    Write-Host "9" -ForegroundColor Green
    Write-Host "func1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Function/func1.xvgs
}
If(($val -eq 0) -or ($val -eq 10)) {
    Write-Host ""
    Write-Host "10" -ForegroundColor Green
    Write-Host "func2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Function/func2.xvgs
}
If(($val -eq 0) -or ($val -eq 11)) {
    Write-Host ""
    Write-Host "11" -ForegroundColor Green
    Write-Host "loop.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Loop/loop.xvgs
}
If(($val -eq 0) -or ($val -eq 12)) {
    Write-Host ""
    Write-Host "12" -ForegroundColor Green
    Write-Host "cond5.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond5.xvgs
}
If(($val -eq 0) -or ($val -eq 13)) {
    Write-Host ""
    Write-Host "13" -ForegroundColor Green
    Write-Host "func3.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Function/func3.xvgs
}
If(($val -eq 0) -or ($val -eq 14)) {
    Write-Host ""
    Write-Host "14" -ForegroundColor Green
    Write-Host "normal1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Expression/normal1.xvgs
}
If(($val -eq 0) -or ($val -eq 15)) {
    Write-Host ""
    Write-Host "15" -ForegroundColor Green
    Write-Host "normal2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/normal2.xvgs
}
If(($val -eq 0) -or ($val -eq 16)) {
    Write-Host ""
    Write-Host "16" -ForegroundColor Green
    Write-Host "io1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/IO/io1.xvgs
}
If(($val -eq 0) -or ($val -eq 17)) {
    Write-Host ""
    Write-Host "17" -ForegroundColor Green
    Write-Host "io2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/IO/io2.xvgs
}
If(($val -eq 0) -or ($val -eq 18)) {
    Write-Host ""
    Write-Host "18" -ForegroundColor Green
    Write-Host "cond6.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond6.xvgs
}
If(($val -eq 0) -or ($val -eq 19)) {
    Write-Host ""
    Write-Host "19" -ForegroundColor Green
    Write-Host "cond7.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Conditional/cond7.xvgs
}
If(($val -eq 0) -or ($val -eq 20)) {
    Write-Host ""
    Write-Host "20" -ForegroundColor Green
    Write-Host "sum_n.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/SHOW/sum_n.xvgs
}
If(($val -eq 0) -or ($val -eq 21)) {
    Write-Host ""
    Write-Host "21" -ForegroundColor Green
    Write-Host "sum_2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/SHOW/sum_2.xvgs
}
If(($val -eq 0) -or ($val -eq 22)) {
    Write-Host ""
    Write-Host "22" -ForegroundColor Green
    Write-Host "fact.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/SHOW/fact.xvgs
}
If(($val -eq 0) -or ($val -eq 23)) {
    Write-Host ""
    Write-Host "23" -ForegroundColor Green
    Write-Host "loop2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Loop/loop2.xvgs
}
If(($val -eq 0) -or ($val -eq 24)) {
    Write-Host ""
    Write-Host "24" -ForegroundColor Green
    Write-Host "func_sum.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/SHOW/func_sum.xvgs
}
If(($val -eq 0) -or ($val -eq 25)) {
    Write-Host ""
    Write-Host "25" -ForegroundColor Green
    Write-Host "func_fact.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/SHOW/func_fact.xvgs
}

# ########################################
# Error Programs
# ########################################

If($val -ge 100) {
    Write-Host ""
    Write-Host "||||||||||||||||||||||||||||||||||||||" -ForegroundColor Red
    Write-Host "ERROR SCRIPTS" -ForegroundColor Red
}

If(($val -eq 100) -or ($val -eq 101)) {
    Write-Host ""
    Write-Host "101" -ForegroundColor Green
    Write-Host "e1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/e1.xvgs
}
If(($val -eq 100) -or ($val -eq 102)) {
    Write-Host ""
    Write-Host "102" -ForegroundColor Green
    Write-Host "arithmetic_err1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/arithmetic_err1.xvgs
}
If(($val -eq 100) -or ($val -eq 103)) {
    Write-Host ""
    Write-Host "103" -ForegroundColor Green
    Write-Host "normal_err1.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/normal_err1.xvgs
}
If(($val -eq 100) -or ($val -eq 104)) {
    Write-Host ""
    Write-Host "104" -ForegroundColor Green
    Write-Host "normal_err2.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/normal_err2.xvgs
}
If(($val -eq 100) -or ($val -eq 105)) {
    Write-Host ""
    Write-Host "105" -ForegroundColor Green
    Write-Host "normal_err3.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/normal_err3.xvgs
}
If(($val -eq 100) -or ($val -eq 106)) {
    Write-Host ""
    Write-Host "106" -ForegroundColor Green
    Write-Host "normal_err4.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/normal_err4.xvgs
}
If(($val -eq 100) -or ($val -eq 107)) {
    Write-Host ""
    Write-Host "107" -ForegroundColor Green
    Write-Host "normal_err5.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/normal_err5.xvgs
}
If(($val -eq 100) -or ($val -eq 108)) {
    Write-Host ""
    Write-Host "108" -ForegroundColor Green
    Write-Host "normal_err6.xvgs" -ForegroundColor Green
    ./compile.ps1 ./program/Error/normal_err6.xvgs
}
If(($val -eq 100) -or ($val -eq 109)) {
    
}
If(($val -eq 100) -or ($val -eq 110)) {
    
}
If(($val -eq 100) -or ($val -eq 111)) {
    
}
If(($val -eq 100) -or ($val -eq 112)) {
    
}