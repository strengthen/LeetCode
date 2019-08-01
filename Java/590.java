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
    public List<Integer> postorder(Node root) {
        if(root==null)
        {
            return new ArrayList<Integer>();
        }
        List<Integer> result=new ArrayList<Integer>();
        postOrder(root,result);
        return result;
        
    }
    private void postOrder(Node root,List<Integer> result)
    {
        if(root==null)
            return;
        for(int i=0;i<root.children.size();i++)
        {
            postOrder(root.children.get(i),result);
        }
        result.add(root.val);
    }
}
__________________________________________________________________________________________________
sample 42244 kb submission
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
    public List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        help(root, res);
        return res;
    }
    private void help(Node root, List<Integer> res){
        if(root == null){
            return;
        }
        List<Node> children = root.children;
        for(Node child : children){
            help(child, res);
        }
        res.add(root.val);
    }
}
__________________________________________________________________________________________________
