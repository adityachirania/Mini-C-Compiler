../semantic-analyzer/a.out $1
if [ $? == 0 ]; then
    echo
    echo ICG
    echo ---
    echo
    ./a.out $1
fi