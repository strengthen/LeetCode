__________________________________________________________________________________________________
sample 1 ms submission
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
    
    List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null)
            return res;
        helper(root, 0);
        return res;
    }
    
    public void helper(Node node, int depth){
        if(res.size() <= depth)
            res.add(new ArrayList<>());
        res.get(depth).add(node.val);
        for(Node c : node.children){
            if(c != null)
                helper(c, depth+1);
        }
    }
}
__________________________________________________________________________________________________
sample 42708 kb submission
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
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> fin = new ArrayList();
        if(root == null) return fin;
        Queue<Node> q = new LinkedList();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> temp = new LinkedList();
            for(int i = 0; i<size; i++){
                temp.add(q.peek().val);
                q.addAll(q.poll().children);
            }
            fin.add(temp);
        }
        return fin;
    }
}
__________________________________________________________________________________________________
