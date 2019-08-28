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
sample 2 BFS Runtime: 88 ms Memory Usage: 44.4 MB
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
    if(node == null) return null;

    let map = {};
    let queue = [];

    let clone = new Node(node.val, []);
    map[node.val] = clone;
    queue.push(node);

    while(queue.length > 0) {
        let cur = queue.shift();
        for(let neighbor of cur.neighbors) {
            if(map[neighbor.val] == undefined) {
                map[neighbor.val] = new Node(neighbor.val, []);
                queue.push(neighbor);
            }
            map[cur.val].neighbors.push(map[neighbor.val]);
        }
    }

    return clone;
}
__________________________________________________________________________________________________
