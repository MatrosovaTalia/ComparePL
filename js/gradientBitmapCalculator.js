function fillGradientLine(arr, line, w, a, b) {
	let delta = b - a;
	let offset = a * w;
	for(let i = 0; i < w; i++) {
		let fraction = i / w;
		arr[arr + offset] = a + Math.floor(delta * fraction);
	}
}

function generateGrayGradient(h, w, a, b) {
	size = w * h;
	arr = new Array(size);
	for (let i = 0; i < h; i++) {
		fillGradientLine(arr, i, w, a, b)
	}
	return arr
}

function saveGradient(arr, h, w, b) {
	fmt.Printf("P2\n%d %d\n%d\n", w, h, b)
	console.log("P2\n", w, h, b);
	for (let i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			console.log(arr[i * w + j]);
		}
		console.log("\n");
	}
}

const {performance} = require('perf_hooks');
const measureTime = (func, name) => (...args) => {
	const s = performance.now();
	func(...args);
	console.log(performance.now() - s);
}

const h = 50,
w = 50,
a = 55,
b = 233;

measureTime(generateGrayGradient)(h, w, a, b);