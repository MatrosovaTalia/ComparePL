import Foundation

func mergeSort(_ arr : [Float])->[Float] {
    guard arr.count > 1 else { return arr }
    
    let mid = arr.count / 2
    
    let leftPart = mergeSort(Array(arr[0..<mid]))
    let rightPart = mergeSort(Array(arr[mid..<arr.count]))
    
    return merge(
        leftPart,
        rightPart
    )
}

func merge(_ arr1 : [Float],_ arr2 : [Float])->[Float] {
    var sortedArray = [Float]()
    
    var li = 0, ri = 0;
    
    while(li < arr1.count && ri < arr2.count) {
        if(arr1[li] < arr2[ri]) {
            sortedArray.append(arr1[li])
            li+=1;
        } else {
            sortedArray.append(arr2[ri])
            ri+=1;
        }
    }
    
    while li < arr1.count {
      sortedArray.append(arr1[li])
      li += 1
    }

    while ri < arr2.count {
      sortedArray.append(arr2[ri])
      ri += 1
    }
    
    
    return sortedArray
}

let text = try! String(contentsOfFile: "./array.txt", encoding: String.Encoding.utf8)
let lines : [Float] = text.components(separatedBy: " ").map { Float($0)!}

let startTime = Date().timeIntervalSinceReferenceDate
var result = mergeSort(lines)
let timeElapsed = (Date().timeIntervalSinceReferenceDate - startTime) * 1000
print("\(timeElapsed)")

