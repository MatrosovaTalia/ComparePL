class Node(var dat: Int) {
    var visited: Boolean = false
    var neighbours = mutableListOf<Node>()

    fun addneighbours(neighbourNode: Node) {
        this.neighbours.add(neighbourNode)
    }

    fun getneighbours() = this.neighbours

    fun setneighbours(neighbours: MutableList<Node>) {
        this.neighbours = neighbours
    }
}

fun dfs(node: Node) {
    val neighbours = node.getneighbours()
    node.visited = true
    for (el in neighbours) {
        if (!el.visited) {
            dfs(el)
        }
    }
}


fun main(){
    val n = 1000
    val nodes = Array(n) { i -> Node(i) }
    for (i in 0 until n) {
        for (j in i until n) {
            nodes[i].addneighbours(nodes[j])
        }
    }
    val time = System.nanoTime()
    dfs(nodes[7])
    val timeMilli = (System.nanoTime() - time) / 1000000.0f

    println("$timeMilli")
}
