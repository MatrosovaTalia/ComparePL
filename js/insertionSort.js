const insertionSort = (arr) => {
	const to_sort = arr;
	for (let i = 1; i < to_sort.length; i++) {
		const temp = to_sort[i];
		let j = i - 1;
		while (j >= 0 && to_sort[j] > temp) {
			to_sort[j + 1] = to_sort[j];
			j--;
		}
		to_sort[j + 1] = temp;
	}
	return to_sort;
}

const arr = [];
for (let i = 0; i < 10000; i++) {
	arr.push(Math.floor(Math.random() * 500));
}
const measureTime = (func, name) => (...args) => {
	const s = Date.now();
	func(...args);
	console.log(Date.now() - s);
}

const fs = require('fs');
fs.readFile('./array.txt', {encoding: 'utf8'}, (err, data) => {
	const arr = data.split(' ').map(x=>+x);
	measureTime(insertionSort, 'Insertion sort')(arr);
})