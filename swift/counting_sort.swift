import Foundation

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

let text = try! String(contentsOfFile: "./array.txt", encoding: String.Encoding.utf8)
let lines : [Int] = text.components(separatedBy: " ").map { Int($0)!}

let startTime = Date().timeIntervalSinceReferenceDate
var result = countingSort(lines)
let timeElapsed = (Date().timeIntervalSinceReferenceDate - startTime) * 1000
print("Counting sort: \(timeElapsed)ms.")