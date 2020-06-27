#!/bin/bash

res=""
cmd=""

if [ -z $2 ]
then
	res="results.md"
else
	res="$2.md"
fi

if [ $# != 0 ] && [ "${str: -1}" != "," ]
then
	if [ $1 = "info" ]
	then
		cmd=$1
		res="package_info.txt"
	else
		cmd="$1,"
	fi
else
	cmd=$1
fi

echo "" > $res

docker build -t driver .
docker run driver "$cmd" -d -it -v $(pwd).:/app --name driver >> $res