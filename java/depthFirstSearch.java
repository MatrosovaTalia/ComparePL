import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
 
public class depthFirstSearch{ 
 
	static class Node{
		int data;
		boolean visited;
		List<Node> neighbours;
 
		Node(int data){
			this.data = data;
			this.neighbours=new ArrayList<>();
 
		}
		public void addneighbours(Node neighbourNode){
			this.neighbours.add(neighbourNode);
		}
		public List<Node> getNeighbours() {
			return neighbours;
		}
		public void setNeighbours(List<Node> neighbours) {
			this.neighbours = neighbours;
		}
	}
 
	// Recursive DFS
	public  void dfs(Node node){
		List<Node> neighbours=node.getNeighbours();
        node.visited=true;
		for (int i = 0; i < neighbours.size(); i++) {
			Node n=neighbours.get(i);
			if(n!=null && !n.visited){
				dfs(n);
			}
		}
	}
 
	public static void main(String arg[]){
		int n = 1000;
		Node[] nodes = new Node[n];

		for (int i = 0; i < n; i++){
			nodes[i] = new Node(i);
		}

		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++){
				nodes[i].addneighbours(nodes[j]);
			}
		}

		depthFirstSearch dfs = new depthFirstSearch();
		final double startTime = System.nanoTime() / 1000000.0;
		dfs.dfs(nodes[7]);
        final double endTime = System.nanoTime() / 1000000.0;

        System.out.println(endTime - startTime);
	}
}
 