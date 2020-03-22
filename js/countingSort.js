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

const {performance} = require('perf_hooks');
const measureTime = (func, name) => (...args) => {
	const s = performance.now();
	func(...args);
	console.log(performance.now() - s);
}

const fs = require('fs');
fs.readFile('./array.txt', {encoding: 'utf8'}, (err, data) => {
	const arr = data.split(' ').map(x=>+x);
	measureTime(countingSort, 'Counting sort')(arr);
})