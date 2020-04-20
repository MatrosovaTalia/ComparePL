class Graph {
    private data class Vertex(val name: Int) {
        val neighbors = mutableSetOf<Vertex>()
    }
    private val vertices = mutableMapOf<Int, Vertex>()
    private fun connect(first: Vertex?, second: Vertex?) {
        if (second != null) first?.neighbors?.add(second)
//        if (first != null) second?.neighbors?.add(first)
    }
    fun addVertex(name: Int) {
        vertices[name] = Vertex(name)
    }
    fun connect(first: Int, second: Int) =
        connect(vertices[first], vertices[second])
    fun neighbors(name: Int): List<Int> =
        vertices[name]?.neighbors?.map { it.name } ?: listOf()
}

var visited: Set<Int> = setOf()
//fun Graph.dfs(start: Int, finish: Int) =
//    dfs(start, finish) ?: -1
fun Graph.dfs(start: Int, finish: Int): Int? =
    if (start == finish) -1
    else {
        visited = visited + start
        val min = neighbors(start).filter {
            it !in visited
        }.map {
            dfs(it, finish)
        }.filterNotNull().min()
        if (min == null) null else min + 1
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
    g.dfs(1, 7)
    val timeMilli = (System.nanoTime() - time) / 1000000.0f

    println("$timeMilli")
}
