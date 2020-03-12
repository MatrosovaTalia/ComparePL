#!/bin/bash

res="results.txt"
progs="programs.txt"

# clear output file
echo "" > $res
echo "" > $progs

echo "##" >> $res
# for js execution
echo "JavaScript" >> $res
for f in "js"/*.js
do
	NAME=$(basename $f .js)
	echo "${NAME}" >> $res
	node $f >> $res
	\time -f "%M %R %c %w" node $f 2>>$res >/dev/null
done
echo "##" >> $res
# for swift execution
echo "Swift" >> $res
for f in "swift"/*.swift
do
	NAME=$(basename $f .swift)
	echo "${NAME}" >> $res
	swift $f >> $res
	\time -f "%M %R %c %w" ~/swift/swift-5.1.4-RELEASE-ubuntu18.04/usr/bin/swift $f 2>>$res >/dev/null
	# pmap -x `ps -ef | grep swift | awk '{print $2}'`
done

echo "##" >> $res
# for c compilation and execution
echo "C" >> $res
for f in "c"/*.c
do
	NAME=$(basename $f .c)
	echo "${NAME}" >> $res
	echo "$f" >> $progs
	gcc $f -o ${f%.c}.out
	./"${f%.c}.out" >> $res
	\time -f "%M %R %c %w" ./"${f%.c}.out" 2>>$res >/dev/null
	rm "${f%.c}.out"	
done

echo "##" >> $res
# for cpp compilation and execution
echo "C++" >> $res
for f in "cpp"/*.cpp
do
	NAME=$(basename $f .cpp)
	echo "${NAME}" >> $res
	echo "$f" >> $progs
	g++ -o ${f%.cpp}.out $f
	./"${f%.cpp}.out" >> $res
	\time -f "%M %R %c %w" ./"${f%.cpp}.out" 2>>$res >/dev/null
	rm "${f%.cpp}.out"	
done

echo "##" >> $res

# for kotlin compilation and execution
echo "Kotlin" >> $res
for f in "kt"/*.kt
do
	NAME=$(basename $f .kt)
	echo "${NAME}" >> $res
	echo "$f" >> $progs
	kotlinc $f -include-runtime -d ${f%.kt}.jar
	java -jar ${f%.kt}.jar >> $res
	\time -f "%M %R %c %w" java -jar ${f%.kt}.jar 2>>$res >/dev/null
	rm "${f%.kt}.jar"
done

echo "##" >> $res

# for java execution 
echo "Java" >> $res
for f in "java"/*.java
do
	NAME=$(basename $f .java)
	echo "${NAME}" >> $res
	java $f >> $res
	echo "$f" >> $progs
	\time -f "%M %R %c %w" java $f 2>>$res >/dev/null
done

python3 formatter.py