import java.io.File
import java.util.*

fun counting_sort(arr: IntArray, range: Int = 100000): Unit{
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

fun main(args : Array<String>) {

    val N = 10000
    val arrayContent = File("array.txt")
    var scanner = Scanner(arrayContent)
    val arr = IntArray(N)
    var i = 0

    while (scanner.hasNextInt()) {
        arr[i++] = scanner.nextInt()
    }

    val time = System.nanoTime();
    counting_sort(arr)

    val timeMilli = (System.nanoTime() - time) / 1000000.0f

    println("$timeMilli")
}