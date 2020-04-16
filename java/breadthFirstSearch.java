 
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
 
public class breadthFirstSearch{ 
 
	private Queue<Node> queue;
	static ArrayList<Node> nodes=new ArrayList<Node>();
	static class Node{
		int data;
		boolean visited;
		List<Node> neighbours;
 
		Node(int data){
			this.data=data;
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
 
	public breadthFirstSearch(){
		queue = new LinkedList<Node>();
	}
 
	public void bfs(Node node){
		queue.add(node);
		node.visited=true;
		while (!queue.isEmpty()){
 
			Node element=queue.remove();
			List<Node> neighbours=element.getNeighbours();
			for (int i = 0; i < neighbours.size(); i++) {
				Node n=neighbours.get(i);
				if(n!=null && !n.visited){
					queue.add(n);
					n.visited=true;
 
				}
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
			for (int j = 0; j < n; j++){
				nodes[i].addneighbours(nodes[j]);
			}
		}
		breadthFirstSearch bfs = new breadthFirstSearch();

		final double startTime = System.nanoTime() / 1000000.0;
		bfs.bfs(nodes[100]);
        final double endTime = System.nanoTime() / 1000000.0;

        System.out.println(endTime - startTime);

 
	}
}
