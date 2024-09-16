#!/bin/bash

echo 'cleaning up old files'
rm -f gen solution brute gen
echo 'compiling files gen, solution, brute'
g++ gen.cpp -o ./gen
g++ solution.cpp -o ./solution
g++ brute.cpp -o ./brute
echo 'compilation done'
for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./solution < int) <(./brute < int) || break
done
echo 'expected vs output'


# echo 'cleaning up old files'
# rm -f genTree solution brute genTree
# echo 'compiling files genTree, solution, brute'
# g++ genTree.cpp -o ./genTree
# g++ solution.cpp -o ./solution
# g++ brute.cpp -o ./brute
# echo 'compilation done'
# for((i = 1; ; ++i)); do
#     echo $i
#     ./genTree $i > int
#     # ./a < int > out1
#     # ./brute < int > out2
#     # diff -w out1 out2 || break
#     diff -w <(./solution < int) <(./brute < int) || break
# done
# echo 'expected vs output'

# echo 'cleaning up old files'
# rm -f genTree2 solution brute genTree2
# echo 'compiling files genTree2, solution, brute'
# g++ genTree2.cpp -o ./genTree2
# g++ solution.cpp -o ./solution
# g++ brute.cpp -o ./brute
# echo 'compilation done'
# for((i = 1; ; ++i)); do
#     echo $i
#     ./genTree2 $i > int
#     # ./a < int > out1
#     # ./brute < int > out2
#     # diff -w out1 out2 || break
#     diff -w <(./solution < int) <(./brute < int) || break
# done
# echo 'expected vs output'