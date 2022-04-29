Param (
    $val,
    $filepath
)

If($val -eq 0) {
    make
    make preprocess
    make asm
}
If($val -eq 1) {
    ./sample $filepath
    ./parser ./target.xvgs
    ./asm ./file.tac
}