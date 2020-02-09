import java.util.*
import java.io.File

fun insertion_sort(arr: IntArray): Unit{
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

fun main(args : Array<String>){

    val N = 1000
    val arrayContent = File("array.txt")
    var scanner = Scanner(arrayContent)
    val arr = IntArray(N)
    var i = 0

    while (scanner.hasNextInt()) {
        arr[i++] = scanner.nextInt()
    }

    insertion_sort(arr)
}