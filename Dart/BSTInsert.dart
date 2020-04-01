import "dart:io";

class Node {
  int key;
  Node left, right;

  Node(int item) {
    key = item;
    left = right = null;
  }
}

class BSTinsert {
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
    else if (key > root.key) root.right = insertRec(root.right, key);

    /* return the (unchanged) node pointer */
    return root;
  }
}

void main() {
  var tree = new BSTinsert();
  var N = 5;
  File myFile = new File("array.txt");
  String myFileContent = myFile.readAsStringSync();
  List<String> mylist = myFileContent.split(' ');
  var arr = [];
  for (var i = 0; i < N; i++) arr.add(int.parse(mylist[i]));

  Stopwatch stopwatch = new Stopwatch()..start();

  for (var i = 0; i < N; i++) tree.insert(arr[i]);

  print(stopwatch.elapsedMicroseconds); // executing time in microseconds
}
