func countingSort(_ arr : [Int])-> [Int] {
	let max = arr.max() ?? 0

	var countArray = [Int](repeating: 0, count: Int(max + 1))

	for element in arr {
		countArray[element] += 1
	}

	for idx in 1 ..< countArray.count {
		let sum = countArray[idx] + countArray[idx - 1]
		countArray[idx] = sum
	}

	var sortedArray = [Int](repeating: 0, count: arr.count)
	for element in arr {
		countArray[element] -= 1
		sortedArray[countArray[element]] = element
	}
	return sortedArray
}

var result = countingSort([5,2, 56, 2, 1, 7, 1, 3, 5, 10, 123])