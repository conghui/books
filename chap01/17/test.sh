#!/bin/bash

for i in {1..20}; do
    echo "Now i is $i"
    seq -s "" $i | ./17
    echo 
done
