__________________________________________________________________________________________________
sample 1 DFS Runtime: 92 ms Memory Usage: 44.8 MB
/**
 * // Definition for a Node.
 * function Node(val,neighbors) {
 *    this.val = val;
 *    this.neighbors = neighbors;
 * };
 */
/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
    if(!node) return node;

    var map = {};

    return dfs(node);

    function dfs(node) {
        if(!node) return node;
        if(map[node.val] != undefined) return map[node.val];
        let clone = new Node(node.val, []);
        map[node.val] = clone;

        for(let neighbor of node.neighbors) {
            clone.neighbors.push(dfs(neighbor));
        }

        return map[node.val];
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
