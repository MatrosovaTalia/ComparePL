res=""
nums=10000

if [ -z $1 ]
then
	res="array.txt"
else
	res=$1
fi

printf "" > $res

RANDOM=$$
printf $RANDOM >> $res
for i in `seq $(($nums-1))`
do
	printf " $RANDOM" >> $res
done