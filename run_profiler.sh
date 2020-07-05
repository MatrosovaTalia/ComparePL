#!/bin/bash

res="results.txt"
progs="programs.txt"

cmd=false
noformat=false

if [ -n "$2" ]
then
	if [ "$2" = "info" ]; then
		JS=$(node -v)
		SWIFT=$(swift --version)
		C=$(gcc --version)
		CPP=$(g++ --version)
		KOTLIN=$(kotlinc -version 2>&1)
		JAVA=$(java --version)
		GO=$(go version)
		DART=$(dart --version 2>&1)
		clear
		echo $'###--PACKAGES INFO--###\n\n'
		printf "%s:\n###\n%s\n###\n\n" "JavaScript" "${JS}"
		printf "%s:\n###\n%s\n###\n\n" "Swift" "${SWIFT}"
		printf "%s:\n###\n%s\n###\n\n" "C" "${C}"
		printf "%s:\n###\n%s\n###\n\n" "C++" "${CPP}"
		printf "%s:\n###\n%s\n###\n\n" "Kotlin" "${KOTLIN}"
		printf "%s:\n###\n%s\n###\n\n" "Java" "${JAVA}"
		printf "%s:\n###\n%s\n###\n\n" "GoLang" "${GO}"
		printf "%s:\n###\n%s\n###\n\n" "Dart" "${DART}"
		noformat=true
	fi
	cmd=true
fi

# clear output file
echo "" > $res
echo "" > $progs

# DO NOTHING IF NO FILES
shopt -s nullglob

if [ "$cmd" = false ] || [[ $2 == *"js,"* ]]; then
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
fi

if [ "$cmd" = false ] || [[ $2 == *"swift,"* ]]; then
	echo "##" >> $res
	# for swift execution
	echo "Swift" >> $res
	for f in "swift"/*.swift
	do
		NAME=$(basename $f .swift)
		echo "${NAME}" >> $res
		swiftc $f -Ounchecked -o ${f%.swift}.out
		./"${f%.swift}.out" >> $res
		\time -f "%M %R %c %w" ./"${f%.swift}.out" 2>>$res >/dev/null
		# pmap -x `ps -ef | grep swift | awk '{print $2}'`
	done
fi

if [ "$cmd" = false ] || [[ $2 == *"c,"* ]]; then
	echo "##" >> $res
	# for c compilation and execution
	echo "C" >> $res
	for f in "c"/*.c
	do
		NAME=$(basename $f .c)
		echo "${NAME}" >> $res
		echo "$f" >> $progs
		gcc $f -O3 -o ${f%.c}.out
		./"${f%.c}.out" >> $res
		\time -f "%M %R %c %w" ./"${f%.c}.out" 2>>$res >/dev/null
		rm "${f%.c}.out"	
	done
fi

if [ "$cmd" = false ] || [[ $2 == *"kotlin,"* ]]; then
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
fi

if [ "$cmd" = false ] || [[ $2 == *"java,"* ]]; then
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
fi

if [ "$cmd" = false ] || [[ $2 == *"dart,"* ]]; then
	echo "##" >> $res
	# for Dart compilation and execution
	echo "Dart" >> $res
	for f in "Dart"/*.dart
	do
		NAME=$(basename $f .dart)
		echo "${NAME}" >> $res
		echo "$f" >> $progs
		dart2native $f -o $NAME > /dev/null
		./"${NAME}" >> $res
		\time -f "%M %R %c %w" ./"${NAME}" 2>>$res >/dev/null
		rm "${NAME}"	
	done
fi

if [ "$cmd" = false ] || [[ $2 == *"go,"* ]]; then
	echo "##" >> $res
	# for Go compilation and execution
	echo "Go" >> $res
	for f in "go"/*.go
	do
		NAME=$(basename $f .go)
		echo "${NAME}" >> $res
		echo "$f" >> $progs
		go build $f
		./"${NAME}" >> $res
		\time -f "%M %R %c %w" ./"${NAME}" 2>>$res >/dev/null
		rm "${NAME}"	
	done
fi

if [ "$cmd" = false ] || [[ $2 == *"cpp,"* ]]; then
	echo "##" >> $res
	# for cpp compilation and execution
	echo "C++" >> $res
	for f in "cpp"/*.cpp
	do
		NAME=$(basename $f .cpp)
		echo "${NAME}" >> $res
		echo "$f" >> $progs
		g++ -O3 -o ${f%.cpp}.out $f
		./"${f%.cpp}.out" >> $res
		\time -f "%M %R %c %w" ./"${f%.cpp}.out" 2>>$res >/dev/null
		rm "${f%.cpp}.out"	
	done
fi

# TODO FIX RUST OUTPUT

# echo "##" >> $res

# for Rust compilation and execution
# echo "Rust" >> $res
# for f in "Rust"/*.rs
# do
# 	NAME=$(basename $f .rs)
# 	echo "${NAME}" >> $res
# 	echo "$f" >> $progs
# 	~/.cargo/bin/rustc $f
# 	./"${NAME}" >> $res
# 	\time -f "%M %R %c %w" ./"${NAME}" 2>>$res >/dev/null
# 	rm "${NAME}"	
# done

if [ "$noformat" = false ]
then
	python3 formatter.py
fi