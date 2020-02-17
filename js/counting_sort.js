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

const measureTime = (func, name) => (...args) => {
	console.time(name);
	func(...args);
	console.timeEnd(name);
}

const fs = require('fs');
fs.readFile('./array.txt', {encoding: 'utf8'}, (err, data) => {
	const arr = data.split(' ').map(x=>+x);
	measureTime(countingSort, 'Counting sort')(arr);
})