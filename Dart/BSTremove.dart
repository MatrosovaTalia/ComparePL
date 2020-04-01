import "dart:io";

class Node {
  int key;
  Node left, right;

  Node(int item) {
    key = item;
    left = right = null;
  }
}

class BSTremove {
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
    else if (key > root.key) root.right = insertRec(root.right, key);

    return root;
  }

  void deleteKey(int key) {
    root = deleteRec(root, key);
  }

  Node deleteRec(Node root, int key) {
    // base case: tree is empty
    if (root == null) return root;

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
      else if (root.right == null) return root.left;

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
    while (root.left != null) {
      minv = root.left.key;
      root = root.left;
    }
    return minv;
  }
}

void main() {
  var tree = new BSTremove();
  var N = 1000;
  File myFile = new File("array.txt");
  String myFileContent = myFile.readAsStringSync();
  List<String> mylist = myFileContent.split(' ');
  var arr = [];
  for (var i = 0; i < N; i++) arr.add(int.parse(mylist[i]));

  for (var i = 0; i < N; i++) tree.insert(arr[i]);

  Stopwatch stopwatch = new Stopwatch()..start();

  for (var i = 0; i < N; i++) tree.deleteKey(arr[i]);

  print(stopwatch.elapsedMicroseconds); // executing time in microseconds
}
