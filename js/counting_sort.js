const countingSort = (arr) => {
	const max = Math.max(...arr);
	const countMap = new Array(max).fill(0);
	arr.forEach((el) => {
		countMap[el] += 1;
	});

	res = [];
	countMap.forEach((el, idx) => {
		while (el > 0) {
			res.push(idx);
			el--;
		}
	})

	return res;
}


const arr = [];
for (let i = 0; i < 10000; i++) {
	arr.push(Math.floor(Math.random() * 500));
}

countingSort(arr);