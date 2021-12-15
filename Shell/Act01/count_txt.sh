#!/bin/bash

declare -i num=0

for file in *.txt
do
    num=num+1
done

echo $num