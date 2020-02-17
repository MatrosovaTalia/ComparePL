import Foundation

func insertionSort(_ array : [Float])->[Float] {
    var to_sort = array
    
    for i in 1..<to_sort.count {
        let temp = to_sort[i]
        var j = i - 1
        while (j >= 0 && to_sort[j] > temp) {
            to_sort[j + 1] = to_sort[j]
            j-=1
        }
        to_sort[j + 1] = temp
    }
    return to_sort
}

let text = try! String(contentsOfFile: "./array.txt", encoding: String.Encoding.utf8)
let lines : [Float] = text.components(separatedBy: " ").map { Float($0)!}

let startTime = Date().timeIntervalSinceReferenceDate
var result = insertionSort(lines)
let timeElapsed = (Date().timeIntervalSinceReferenceDate - startTime) * 1000
print("Insertion sort: \(timeElapsed)ms.")