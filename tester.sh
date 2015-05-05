#

./pa2 $1 $2 $3 $4 $5 >& test2
./pa2test $1 $2 $3 $4 $5 >& stdtest2
cmp -l test2 stdtest2
echo "done"
