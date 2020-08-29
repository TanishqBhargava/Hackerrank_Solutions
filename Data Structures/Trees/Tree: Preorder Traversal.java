/* you only have to complete the function given below.  
Node is defined as  

class Node {
    int data;
    Node left;
    Node right;
}

*/
    public static void preOrder(Node root) {
        Node cur = root;
        while(cur != null){
            System.out.print(cur.data + " ");

            if(cur.left != null & cur.right != null){
                // Find in-order predecessor of cur
                // (that predecessor is also the last node to attempt visiting its right,
                //  directly before attempting visiting cur's right)
                Node pred = cur.left;
                while(pred.right != null){
                    pred = pred.right;
                }
                // Thread pred.right to cur.right (to "remember" it without a stack)
                pred.right = cur.right;
            }

            if(cur.left != null){
                // "Recur" on left
                cur = cur.left;

            } else {
                // "Recur" on right
                cur = cur.right;
            }
        }
    }
