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

var result = insertionSort([5,2, 56, 2, 1, 7, 1, 3, 5, 10, 123])