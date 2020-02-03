#!/bin/bash

# for js execution

for f in "js"/*.js
do
	echo "Profiling $f"
	time node $f
	echo ""
done

# for swift execution

for f in "swift"/*.swift
do
	echo "Profiling $f"
	time swift $f
	echo ""
done