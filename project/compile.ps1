Param (
    $filepath
)

# $filepath     :   ./program/sum.xvgs

./environment/sample $filepath
./environment/parser ./target.xvgs
./environment/asm ./file.tac
