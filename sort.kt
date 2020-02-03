import java.util.*
import java.io.File

fun insertionSort(arr: IntArray): Unit{
    for (i in 1 until arr.size){
        val current = arr[i]
        var j = i - 1
        while(j >= 0 && current < arr[j]){
            arr[j + 1] = arr[j]
            j--
        }
        arr[j + 1] = current
    }
}

fun merge(arr: IntArray, l: Int, m: Int, r: Int): Unit{
    val n1 = m - l + 1
    val n2 = r - m
    val L = IntArray(n1)
    val R = IntArray(n2)
    for (i in 0 until n1){
        L[i] = arr[i + l]
    }
    for (j in 0 until n2){
        R[j] = arr[j + m + 1];
    }
    var i = 0
    var j = 0
    var k = l
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i]
            i++
        }
        else{
            arr[k] = R[j]
            j++
        }
        k++
    }
    while(i < n1){
        arr[k] = L[i]
        i++
        k++
    }
    while(j < n2){
        arr[k] = R[j]
        j++
        k++
    }
}


fun mergeSort(arr: IntArray, l: Int, r: Int){
    if (l < r){
        var m: Int = l + (r - l)/2
        mergeSort(arr, l, m)
        mergeSort(arr, m + 1, r)
        merge(arr, l, m, r)
    }
}




fun countingSort(arr: IntArray, range: Int = 1000): Unit{
    val count = IntArray(range)
    for (element in arr){
        count[element]++
    }
    var k = 0
    for (i in 0 until range){
        while (count[i] > 0){
            arr[k] = i
            count[i]--
            k++
        }
    }


}

fun main(args : Array<String>){

    val N = 1000
    val arrayContent = File("array.txt")
    var scanner = Scanner(arrayContent)
    val arr = IntArray(N)
    var i = 0
    var start: Long
    var end: Long
    var insertion_time: Double
    var merge_time: Double
    var counting_time: Double

    while (scanner.hasNextInt()) {
        arr[i++] = scanner.nextInt()
    }

    start = System.nanoTime()
    insertionSort(arr)
    end = System.nanoTime()
    insertion_time =  (end - start).toDouble() / 1_000_000_000

//    i = 0;
//    scanner = Scanner(arrayContent);
//    while(scanner.hasNextInt()){
//        arr[i++] = scanner.nextInt();
//    }

    start = System.nanoTime()
    mergeSort(arr, 0, arr.lastIndex)
    end = System.nanoTime()
    merge_time = (end - start).toDouble() / 1_000_000_000

    start = System.nanoTime()
    countingSort(arr)
    end = System.nanoTime()
    counting_time = (end - start).toDouble() / 1_000_000_000

    println("Insertion sort time: %f\n".format(insertion_time) +
            "Merge sort time: %f\n".format(merge_time) +
            "Counting sort time: %f\n".format(counting_time))
    // println("Hello, I am Kotlin file!\n");
}
