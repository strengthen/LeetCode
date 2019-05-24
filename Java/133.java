__________________________________________________________________________________________________
sample 1 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    public Node cloneGraph(Node node) {
        return clone(node, new HashMap<>());
    }
    
    private Node clone(Node node, HashMap<Integer, Node> visited){
        if(node == null){
            return null;
        }
        
        if(visited.containsKey(node.val)){
            return visited.get(node.val);
        }
        
        Node newNode = new Node(node.val, new ArrayList<>());
        
        visited.put(newNode.val, newNode);
        
        for(Node neighborNode : node.neighbors){
            newNode.neighbors.add(clone(neighborNode, visited));
        }
        
        return newNode;
    }
}
__________________________________________________________________________________________________
sample 31084 kb submission
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    public Node cloneGraph(Node node) {
        Map<Integer, Node> map = new HashMap<>();
        return dfs(node, map);
    }
    private Node dfs(Node node, Map<Integer, Node> map) {
        if (node == null) return null;
        if (map.containsKey(node.val)) return map.get(node.val);
        Node copy = new Node(node.val, new ArrayList<Node>());
        map.put(node.val, copy);
        for (Node n : node.neighbors) {
            copy.neighbors.add(dfs(n, map));
        }
        return copy;
    }
}
__________________________________________________________________________________________________
