Param (
    $val
)

#   -1  -   Nothing
#   0   -   All
#   1   -   arithmetic.xvgs
#   2   -   character
#   3   -   logical
#   4   -   e
#   5   -   e1
#   6   -   cond1
#   7   -   cond2
#   8   -   cond3
#   9   -   cond4
#   10  -   func1
#   11  -   func2
#   12  -   loop

#   101 -   arithmetic_err1.xvgs


Write-Host "||||||||||||||||||||||||||||||||||||||" -ForegroundColor Blue
Write-Host "NON ERROR SCRIPTS" -ForegroundColor Blue

If(($val -eq 0) -or ($val -eq 1)) {
    Write-Host ""
    Write-Host "arithmetic.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Expression/arithmetic.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 2)) {
    Write-Host ""
    Write-Host "character.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Expression/character.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 3)) {
    Write-Host ""
    Write-Host "logical.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Expression/logical.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 4)) {
    Write-Host ""
    Write-Host "e.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Expression/e.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 5)) {
    Write-Host ""
    Write-Host "e1.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Expression/e1.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 6)) {
    Write-Host ""
    Write-Host "cond1.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Conditional/cond1.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 7)) {
    Write-Host ""
    Write-Host "cond2.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Conditional/cond2.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 8)) {
    Write-Host ""
    Write-Host "cond3.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Conditional/cond3.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 9)) {
    Write-Host ""
    Write-Host "cond4.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Conditional/cond4.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 10)) {
    Write-Host ""
    Write-Host "func1.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Function/func1.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 11)) {
    Write-Host ""
    Write-Host "func2.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Function/func2.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 12)) {
    Write-Host ""
    Write-Host "loop.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Loop/loop.xvgs
}
ElseIf(($val -eq 0) -or ($val -eq 13)) {
    
}



Write-Host ""
Write-Host "||||||||||||||||||||||||||||||||||||||" -ForegroundColor Red
Write-Host "ERROR SCRIPTS" -ForegroundColor Red

If(($val -eq 0) -or ($val -eq 101)) {
    Write-Host ""
    Write-Host "arithmetic_err1.xvgs" -ForegroundColor Green
    ./parser ./../../example_programs/our_language/Expression/arithmetic_err1.xvgs   
}
ElseIf(($val -eq 0) -or ($val -eq 102)) {
    
}
ElseIf(($val -eq 0) -or ($val -eq 103)) {
    
}