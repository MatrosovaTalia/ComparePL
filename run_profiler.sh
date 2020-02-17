#!/bin/bash

file="./out/results.txt"

# clear output file
echo "" > $file

# for js execution

for f in "js"/*.js
do
	echo "Profiling $f" >> $file
	{ time node $f ; } 2>> $file
	echo "" >> $file
done

# for swift execution

for f in "swift"/*.swift
do
	echo "Profiling $f" >> $file
	{ time swift $f ; } 2>> $file
	echo "" >> $file
done

clang run.c -o sort
./sort >> $file

cat $file