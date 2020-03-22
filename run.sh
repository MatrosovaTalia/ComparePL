#!/bin/bash

res=""
if [ -z $1 ]
then
	res="results.md"
else
	res=$1
fi

echo "" > $res

docker build -t driver .
docker run driver -d -it -v $(pwd).:/app --name driver >> $res