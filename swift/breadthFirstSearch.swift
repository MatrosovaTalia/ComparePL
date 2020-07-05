import Foundation

class Node {
    var data: Int
    var visited: Bool
    var neighbours = [Node]()
    
    init(data: Int) {
        self.data = data
        self.visited = false
    }
    
    func addneighbours(neighboursNode: Node) {
        self.neighbours.append(neighboursNode)
    }
    
    func getneighbours() -> [Node] {
        return neighbours
    }
    
    func setneighbours(neighbours: [Node]) {
        self.neighbours = neighbours
    }
}

var queue = [Node]()

func bfs(node: Node) {
    queue.append(node)
    node.visited = true
    while !queue.isEmpty {
        let element = queue.removeFirst()
        let neighbours = element.getneighbours()
        for i in 0..<neighbours.count {
            let n = neighbours[i]
            if (!n.visited) {
                queue.append(n)
                n.visited = true
            }
        }
    }
}

let n = 1000
var nodes = [Node]()
for i in 0..<n {
    nodes.append(Node(data: i))
}
for i in 0..<n {
    for j in i..<n {
        nodes[i].addneighbours(neighboursNode: nodes[j])
    }
}
let startTime = DispatchTime.now()
bfs(node: nodes[7])
let endTime = DispatchTime.now()
let interval = endTime.uptimeNanoseconds - startTime.uptimeNanoseconds

print("\(Double(interval) / 1_000_000)")
