class Leaf {
  num value;
  Leaf left;
  Leaf right;

  Leaf(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class Tree {
  Leaf root;

  Tree() {
    this.root = null;
  }

  void add(value) {
    var newLeaf = Leaf(value);
    if (this.root == null)
      this.root = newLeaf;
    else {
      var current = this.root;
      while (true) {
        if (value <= current.value && current.left == null) {
          current.left = newLeaf;
          break;
        } else if (value > current.value && current.right == null) {
          current.right = newLeaf;
          break;
        } else {
          if (value <= current.value)
            current = current.left;
          else
            current = current.right;
        }
      }
    }
  }
  
  bool isHere(value){
    var current = this.root;
    while(current != null){
      if(current.value == value)
        return true;
      if(value <= current.value)
        current = current.left;
      else
        current = current.right;
    }
    return false;
  }
}

void main() {
  var newTree = Tree();
  newTree.add(5);
  newTree.add(3);
  newTree.add(6);
  newTree.add(1);
  print(newTree.isHere(5));
  print(newTree.isHere(3));
  print(newTree.isHere(6));
  print(newTree.isHere(1));
  print(newTree.isHere(2));
}