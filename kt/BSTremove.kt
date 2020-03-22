import java.io.File
import java.util.*

class Node (
    var key: Int,
    var left: Node? = null,
    var right: Node? = null
)

class BST(var root: Node? = null) {

    fun insert(key: Int) {
        root = insertRec(root, key)
    }

    fun insertRec(root: Node?, key: Int): Node? {
        // if tree is empty -> return null
        if (root == null) {
            val newRoot = Node(key)
            return newRoot
        }
        // else traverse down the tree
        if (key < root.key)
            root.left = insertRec(root.left, key)
        else if (key > root.key)
            root.right = insertRec(root.right, key)
        return root
    }

    fun inorder()  {
        inorderRec(root)
    }

    // An utility function to do inorder traversal of BST
    fun inorderRec(root: Node?) {
        root?.let {
            inorderRec(root.left);
            println(root.key);
            inorderRec(root.right);
        }
    }

    fun remove(key: Int) {
        root = removeRec(root, key)
    }


    fun removeRec(root: Node?, key: Int): Node? {
        // base case: if tree is empty
        if (root == null)  return root

        // Otherwise, traverse down the tree
        if (key < root.key)
            root.left = removeRec(root.left, key)
        else if (key > root.key)
            root.right = removeRec(root.right, key)

        // if key is same as root's key, then this is the node
        // to be deleted
        else {
            // node with only one child or no child
            if (root.left == null)
                return root.right
            else if (root.right == null)
                return root.left

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            root.key = minValue(root.right!!)

            // Delete the inorder successor
            root.right = removeRec(root.right, root.key)
        }

        return root
    }

    fun minValue(root: Node): Int {
        var min_v: Int = root.key
        var current: Node = root
        while (current.left != null) {
            min_v = current.left!!.key
            current = current.left!!
        }
        return min_v
    }

}

fun main(args : Array<String>){
    val tree = BST()
    val N = 10000
    val arrayContent = File("array.txt")
    var scanner = Scanner(arrayContent)
    val arr = IntArray(N)
    var j = 0

    while (scanner.hasNextInt()) {
        arr[j++] = scanner.nextInt()
    }

    for (i in 0 until arr.lastIndex){
        tree.insert(arr[i])
    }
        
    val time = System.nanoTime();

    for (i in 0 until arr.lastIndex){
        tree.remove(arr[i])
    }

    val timeMilli = (System.nanoTime() - time) / 1000000.0f

    println("$timeMilli")
}
