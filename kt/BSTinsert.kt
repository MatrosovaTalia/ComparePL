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

}

fun main(args : Array<String>){
    val tree = BST()
    val N = 1000
    val arrayContent = File("array.txt")
    var scanner = Scanner(arrayContent)
    val arr = IntArray(N)
    var j = 0

    while (scanner.hasNextInt()) {
        arr[j++] = scanner.nextInt()
    }

    val time = System.nanoTime();

    for (i in 0 until arr.lastIndex){
        tree.insert(arr[i])
    }

    val timeMilli = (System.nanoTime() - time) / 1000000

    println("$timeMilli")

}
