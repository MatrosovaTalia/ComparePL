class Node {
	constructor(value) {
		this.value = value;
		this.left=null;
		this.right=null;
		this.value=null;
	}
}

class BinarySearchTree {
	constructor() {
		this.root = null;
		this.size = 0;

		this.addNode.bind(this);
		this.findNode.bind(this);
		this.removeNode.bind(this);
	}

	addNode(value) {
		if (value.length) {
			value.forEach((arg) => {this.addNode(arg)});
			return;
		}

		if (this.size === 0) {
			this.root = new Node(value);
			this.size++;
			return;
		}

		let current = this.root;

		while(true) {
			if (value === current.value) {
				return;
			}

			if (value > current.value) {
				if (!current.right) {
					current.right = new Node(value);
					break;
				}
				current = current.right;
			} else {
				if (!current.left) {
					current.left = new Node(value);
					break;
				}
				current = current.left;
			}
		}

		this.size++;
	}

	removeNode(value) {
		if (this.size === 0) {
			return;
		}

		let found = this.root;
		let res;

		while(true) {
			if (!found) {
				return;
			}

			if (found.value === value) {
				res = {...found};
				if (!found.left && !found.right) {
					found = null;
				} else if (!found.right || !found.right) {
					found = found.left || found.right;
				} else {	
					let min = this._findMin(found.right);
					found.value = min.value;
					min = min.left || min.right;
				}
				break;
			}
			found = found.value < value ? found.right : found.left;
		}
		this.size--;
		return res;
	}

	findNode(value) {
		let result = this.root;
		while(true) {
			if (!result) {
				return;
			}

			if (result.value === value) {
				return result;
			}

			result = result.value < value ? result.right : result.left;
		}
	}

	_findMin(node) {
		while(true) {
			if (!node.left) {
				return node;
			}
			node = node.left;
		}
	}
}

const {performance} = require('perf_hooks');
const measureTime = (func, name) => (...args) => {
	const s = performance.now();
	func.addNode(...args);
	console.log(performance.now() - s);
}

const binTree = new BinarySearchTree();

const fs = require('fs');
fs.readFile('./array.txt', {encoding: 'utf8'}, (err, data) => {
	const arr = data.split(' ').map(x=>+x);
	measureTime(binTree, 'BinTree insertion')(arr);
})