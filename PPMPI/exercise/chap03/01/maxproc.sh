#!/bin/bash

# find the maximum of process that I could create

i=1
while true; do
    mpiexec -n ${i} ./01 &> /dev/null 
    if [[ ! $? == "0" ]]; then
        i=$((i-1))
        echo "you can create at most $i process" 
        exit -1
    fi
    let i+=1
done
