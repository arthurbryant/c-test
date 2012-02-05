#!/bin/sh
for i in $@
do
time ./dir2 $i >> log
time ./dir3 $i >> log 
done
