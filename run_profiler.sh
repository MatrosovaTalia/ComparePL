#!/bin/bash

res="results.txt"
progs="programs.txt"

# clear output file
echo "" > $res
echo "" > $progs

# for js execution

for f in "js"/*.js
do
	echo "Profiling $f" >> $res
	{ time node $f ; } 2>> $res
	echo "" >> $res
done

# for swift execution

for f in "swift"/*.swift
do
	echo "Profiling $f" >> $res
	{ time swift $f ; } 2>> $res
	echo "" >> $res
done

# for c compilation and execution
for f in "c"/*.c
do
	echo "Profiling $f" >> $res
	echo "$f" >> $progs
	gcc $f -o ${f%.c}.out
	{ time ./"${f%.c}.out" ; } 2>> $res
	{ /usr/bin/time -f "\t%M max memory consumption" ./"${f%.c}.out" ; } 2>> $res
	rm "${f%.c}.out"	
	echo "" >> $res
	
	
done

# for kotlin compilation and execution
for f in "kt"/*.kt
do
	echo "Profiling $f" >> $res
	echo "$f" >> $progs
	kotlinc $f -include-runtime -d ${f%.kt}.jar
	{ time java -jar ${f%.kt}.jar ; } 2>> $res
	{ /usr/bin/time -f "\t%M max memory consumption" java -jar ${f%.kt}.jar ; } 2>> $res
	echo "" >> $res

done


# for java execution 
for f in "java"/*.java
do
	echo "Profiling $f" >> $res
	{ time java $f ; } 2>> $res
	echo "$f" >> $progs
	{ /usr/bin/time -f "\t%M max memory consumption" java $f ; } 2>> $res
	echo "" >> $res
done

