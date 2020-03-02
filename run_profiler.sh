#!/bin/bash

res="results.txt"
progs="programs.txt"

# clear output file
echo "" > $res
echo "" > $progs

# for js execution

for f in "js"/*.js
do
	echo "Profiling $f"
	node $f
	\time -v node $f 2>&1 >/dev/null
	echo ""
done

# for swift execution

for f in "swift"/*.swift
do
	echo "Profiling $f"
	swift $f
	\time -v ~/swift/swift-5.1.4-RELEASE-ubuntu18.04/usr/bin/swift $f 2>&1 >/dev/null
	# pmap -x `ps -ef | grep swift | awk '{print $2}'`
	echo ""
done

# for c compilation and execution
for f in "c"/*.c
do
	echo "Profiling $f"
	echo "$f" >> $progs
	gcc $f -o ${f%.c}.out
	./"${f%.c}.out"
	\time -v ./"${f%.c}.out" 2>&1 >/dev/null
	rm "${f%.c}.out"	
	echo ""
done

# for cpp compilation and execution
for f in "cpp"/*.cpp
do
	echo "Profiling $f"
	echo "$f" >> $progs
	g++ -o ${f%.cpp}.out $f
	./"${f%.cpp}.out"
	\time -v ./"${f%.cpp}.out" 2>&1 >/dev/null
	rm "${f%.cpp}.out"	
	echo ""	
done


# for kotlin compilation and execution
for f in "kt"/*.kt
do
	echo "Profiling $f"
	echo "$f" >> $progs
	kotlinc $f -include-runtime -d ${f%.kt}.jar
	java -jar ${f%.kt}.jar
	\time -v java -jar ${f%.kt}.jar 2>&1 >/dev/null
	rm "${f%.kt}.jar"
	echo ""

done


# for java execution 
for f in "java"/*.java
do
	echo "Profiling $f"
	java $f
	echo "$f" >> $progs
	\time -v java $f 2>&1 >/dev/null
	echo "" >> $res
done

# cat $res