import java.io.File;
import java.io.IOException;
import java.util.Scanner;

class BSTremove {


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
    BSTremove() {
        root = null;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    Node insertRec(Node root, int key) {

        // if tree is empty return new node
        if (root == null) {
            root = new Node(key);
            return root;
        }

        // Otherwise traverse down  the tree
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        return root;
    }


    void deleteKey(int key)
    {
        root = deleteRec(root, key);
    }
    Node deleteRec(Node root, int key) {
        // base case: tree is empty
        if (root == null)  return root;

        // Otherwise traverse down the tree
        if (key < root.key)
            root.left = deleteRec(root.left, key);
        else if (key > root.key)
            root.right = deleteRec(root.right, key);

            // if key is same as root's key, then This is the node
            // to be deleted
        else {
            // node with only one child or no child
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            root.key = minValue(root.right);

            // Delete the inorder successor
            root.right = deleteRec(root.right, root.key);
        }

        return root;
    }

    int minValue(Node root) {
        int minv = root.key;
        while (root.left != null)
        {
            minv = root.left.key;
            root = root.left;
        }
        return minv;
    }

    public static void main(String[] args) throws IOException {
        BSTremove tree = new BSTremove();
        final int N = 1000;
        File array = new File("array.txt");
        Scanner scanner = new Scanner(array);
        int [] arr = new int [N];
        int i = 0;


        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }

        for (int j = 0; j < arr.length - 1; j++){
            tree.insert(arr[j]);
        }

        final double startTime = System.nanoTime() / 1000000;

        for (int j = 0; j < arr.length - 1; j++){
            tree.deleteKey(arr[j]);
        }
        final double endTime = System.nanoTime() / 1000000;

        System.out.println((endTime - startTime));
    }
}
