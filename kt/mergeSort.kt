import java.io.File
import java.util.*


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


fun merge_sort(arr: IntArray, l: Int, r: Int){
    if (l < r){
        var m: Int = l + (r - l)/2
        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, r)
        merge(arr, l, m, r)
    }
}

fun main(args : Array<String>){

    val N = 10000
    val arrayContent = File("./array.txt")
    var scanner = Scanner(arrayContent)
    val arr = IntArray(N)
    var i = 0

    while (scanner.hasNextInt()) {
        arr[i++] = scanner.nextInt()
    }

    val time = System.nanoTime();
    merge_sort(arr, 0, arr.lastIndex)

    val timeMilli = (System.nanoTime() - time) / 1000000.0f

    println("$timeMilli")

}
