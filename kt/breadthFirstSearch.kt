import java.util.ArrayDeque;

class Graph {
    private data class Vertex(val name: Int) {
        val neighbors = mutableSetOf<Vertex>()
    }
    private val vertices = mutableMapOf<Int, Vertex>()
    private fun connect(first: Vertex?, second: Vertex?) {
        if (second != null) first?.neighbors?.add(second)
        // if (first != null) second?.neighbors?.add(first)
    }
    fun addVertex(name: Int) {
        vertices[name] = Vertex(name)
    }
    fun connect(first: Int, second: Int) =
        connect(vertices[first], vertices[second])
    fun neighbors(name: Int): List<Int> =
        vertices[name]?.neighbors?.map { it.name } ?: listOf()
}


fun Graph.bfs(finish: Int, start: Int = 1): Int {
    val queue = ArrayDeque<Int>()
    queue.add(start)
    val visited = mutableMapOf(start to 0)
    while (queue.isNotEmpty()) {
        val next = queue.poll()
        val distance = visited[next]!!
        if (next == finish) return distance
        for (neighbor in neighbors(next)) {
//            println(neighbor)
            if (neighbor in visited) continue
            visited[neighbor] = distance + 1
            queue.add(neighbor)
        }
    }
    return -1
}

fun main(){
    var g = Graph()

    val n = 1000
    for (i in 0 until n){
        g.addVertex(i)
    }
    for (i in 0 until n) {
        for (j in i until n) {
            g.connect(i, j)
        }
    }

    val time = System.nanoTime()
    g.bfs(7)
    val timeMilli = (System.nanoTime() - time) / 1000000.0f

    println("$timeMilli")

}
