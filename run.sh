#!/bin/bash

res="results.md"

echo "" > $res

docker build -t driver .
docker run driver -d -it -v $(pwd).:/app --name driver >> $res