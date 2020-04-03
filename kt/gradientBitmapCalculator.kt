@kotlin.ExperimentalUnsignedTypes
fun fillGradientLine(arr: kotlin.UIntArray, line: Int, w: Int, a: UByte, b: UByte): Unit {
    val delta = b - a
    val offset = line * w
    for (i in 0 until w) {
        var fraction = i.toFloat() / w.toFloat()
        arr[offset + i] = a.toUByte() + (delta.toFloat() * fraction).toUInt()
    }
}

@kotlin.ExperimentalUnsignedTypes
fun generateGrayGradient(h: Int, w: Int, a: UByte, b: UByte): kotlin.UIntArray{
    val size = w * h
    val arr = kotlin.UIntArray(size)
    for (i in 0 until h){
        fillGradientLine(arr, i, w, a, b)
    }
    return arr
}

@kotlin.ExperimentalUnsignedTypes
fun saveGradient(arr: kotlin.UIntArray, h: Int, w: Int, b:UByte): Unit {
    print(java.lang.String.format("P2\n%d %d\n%d\n", w, h.toInt(), b.toInt()))
    for (i in 0 until h) {
        for (j in 0 until w){
            print(arr[i * w + j])
            print(" ")
        }
        println("")
    }
}

@kotlin.ExperimentalUnsignedTypes
fun main() {
    val h = 50
    val w = 50
    val a: UByte = 55.toUByte()
    val b: UByte = 233.toUByte()

    val start = System.nanoTime();
    generateGrayGradient(h, w, a, b)
    val timeMilli = (System.nanoTime() - start) / 1000000.0f
    println("$timeMilli")
    //saveGradient(arr, h, w, b)
}
