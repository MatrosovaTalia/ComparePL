import java.io.File;
import java.io.IOException;
import java.util.Scanner;

class BSTinsert {

    class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }

    // Root of BST 
    Node root;

    // Constructor 
    BSTinsert() {
        root = null;
    }

    // This method mainly calls insertRec() 
    void insert(int key) {
        root = insertRec(root, key);
    }

    /* A recursive function to insert a new key in BST */
    Node insertRec(Node root, int key) {

        /* If the tree is empty, return a new node */
        if (root == null) {
            root = new Node(key);
            return root;
        }

        /* Otherwise, recursion down the tree */
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        /* return the (unchanged) node pointer */
        return root;
    }

    public static void main(String[] args) throws IOException {
        BSTinsert tree = new BSTinsert();
        final int N = 1000;
        File array = new File("array.txt");
        Scanner scanner = new Scanner(array);
        int[] arr = new int[N];
        int i = 0;

        while (scanner.hasNextInt()) {
            arr[i++] = scanner.nextInt();
        }

        final double startTime = System.nanoTime() / 1000000;

        for (int j = 0; j < arr.length - 1; j++) {
            tree.insert(arr[j]);
        }
        final double endTime = System.nanoTime() / 1000000;

        System.out.println("BSTInsert: " + (endTime - startTime) + "ms");
    }
}