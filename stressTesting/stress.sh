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