const merge = (left, right) => {
	let result = [], li = 0, ri = 0;

	while (li < left.length && ri < right.length) {
		if (left[li] < right[ri]) {
			result.push(left[li]);
			li++;
		} else {
			result.push(right[ri]);
			ri++;
		}
	}

	return result.concat(left.slice(li)).concat(right.slice(ri));
}

const mergeSort = (arr) => {
	if (arr.length <= 1) {
		return arr;
	}

	const sep = Math.floor(arr.length / 2);

	const left = arr.slice(0, sep);
	const right = arr.slice(sep);

	return merge(
		mergeSort(left),
		mergeSort(right)
	);
}

const { performance } = require('perf_hooks');
const measureTime = (func, name) => (...args) => {
	const s = performance.now();
	func(...args);
	console.log(performance.now() - s);
}

const fs = require('fs');
fs.readFile('./array.txt', { encoding: 'utf8' }, (err, data) => {
	const arr = data.split(' ').map(x => +x);
	measureTime(mergeSort, 'Merge sort')(arr);
})