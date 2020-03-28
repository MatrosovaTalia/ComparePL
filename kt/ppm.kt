// import java.io.File
import java.util.*
import java.lang.String.*


fun fillGradientLine(arr: kotlin.UIntArray, line: Int, w: Int, a: UByte, b: UByte): Unit {
    val delta = b - a
    val offset = line * w
    for (i in 0 until w) {
        var fraction = i.toFloat() / w.toFloat()
        arr[offset + i] = a.toUByte() + (delta.toFloat() * fraction).toUInt()
    }
}
fun generateGrayGradient(h: Int, w: Int, a: UByte, b: UByte): kotlin.UIntArray{
    val size = w * h
    val arr = kotlin.UIntArray(size)
    for (i in 0 until h){
        fillGradientLine(arr, i, w, a, b)
    }
    return arr
}

fun saveGradient(arr: kotlin.UIntArray, h: Int, w: Int, b: UByte): Unit {
    print(java.lang.String.format("P2\n%d %d\n%d\n", w, h.toInt(), b.toInt()))
    for (i in 0 until h) {
        for (j in 0 until w){
            print(arr[i * w + j])
            print(" ")
        }
        println("")
    }
}

fun main(args : Array<String>) {
    val h = 50
    val w = 50
    val a: UByte = 55.toUByte()
    val b: UByte = 233.toUByte()

    val time = System.nanoTime();
    var arr = generateGrayGradient(h, w, a, b)
    val timeMilli = (System.nanoTime() - time) / 1000000

    println("$timeMilli")
    println()

    // saveGradient(arr, h, w, b)
}
