__________________________________________________________________________________________________
sample 0 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    int res = 0;
    public int maxDepth(Node root) {
        if(root==null)
            return 0;
        int maxDepth = 0 ;
        for(int i = 0 ; i< root.children.size();i++)
        {
            maxDepth = Math.max(maxDepth,maxDepth(root.children.get(i)));
        }
        return maxDepth+1;
    }
}
__________________________________________________________________________________________________
sample 42348 kb submission
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public int maxDepth(Node root) {
        if (root == null) return 0;

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 1));
        int maxDepth = 0;
        while (queue.size() > 0) {
            Pair curNode = queue.poll();
            maxDepth = Math.max(maxDepth, curNode.depth);
            for (Node child : curNode.node.children) {
                queue.add(new Pair(child, curNode.depth + 1));
            }
        }
        return maxDepth;
    }
    class Pair {
        Node node;
        int depth;
        Pair(Node node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }
}
__________________________________________________________________________________________________
