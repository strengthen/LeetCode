__________________________________________________________________________________________________
sample 13 ms submission
class Solution {
    
    public void subtree(int curr, int prev, ArrayList <Integer>[] tree, int[] sum, int[] nodes) {
        nodes[curr] ++;
        for(int next : tree[curr]) {
            if(next == prev)
                continue;
            subtree(next, curr, tree, sum, nodes);
            nodes[curr] += nodes[next];
            sum[curr] += sum[next] + nodes[next];
        }
    }
    
    public static void getAns(int curr, int prev, ArrayList <Integer>[] tree, int[] nodes, int[] ans, int N) {
        ans[curr] = ans[prev] - nodes[curr] + (N - nodes[curr]);
        for(int next : tree[curr]) {
            if(next == prev)
                continue;
            getAns(next, curr, tree, nodes, ans, N);
        }
    }
    
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        ArrayList <Integer>[] tree = new ArrayList[N];
        for(int i = 0; i < N; i ++)
            tree[i] = new ArrayList <> ();
        for(int i = 0; i < N - 1; i ++) {
            tree[edges[i][0]].add(edges[i][1]);
            tree[edges[i][1]].add(edges[i][0]);
        }
        int[] sum = new int[N];
        int[] nodes = new int[N];
        subtree(0, -1, tree, sum, nodes);
        int[] ans = new int[N];
        ans[0] = sum[0];
        for(int nextTo0 : tree[0])
            getAns(nextTo0, 0, tree, nodes, ans, N);
        return ans;
    }
}
__________________________________________________________________________________________________
sample 50660 kb submission
class Solution {
    class TreeNode {
        int val;

        int num;
        int sum;

        TreeNode father;
        List<TreeNode> children;

        public TreeNode(int val) {
            this.val = val;
        }
    }

    Map<Integer, Set<Integer>> adjMap;
    int[] ans;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        if (N <= 0) return null;

        ans = new int[N];
        adjMap = new HashMap<>();
        for (int[] edge : edges) {
            adjMap.computeIfAbsent(edge[0], k -> new HashSet<>()).add(edge[1]);
            adjMap.computeIfAbsent(edge[1], k -> new HashSet<>()).add(edge[0]);
        }

        TreeNode root = build(0, null);

        getAns(root, N);

        return ans;
    }

    private void getAns(TreeNode root, int N) {

        if (root.father == null) {
            ans[root.val] = root.sum;
        } else {
            ans[root.val] = root.sum + ans[root.father.val] - root.sum - root.num + (N - root.num);
        }

        for (TreeNode child : root.children) {
            getAns(child, N);
        }

    }

    private TreeNode build(int x, TreeNode father) {
        TreeNode root = new TreeNode(x);
        root.father = father;

        Set<Integer> adjSet = adjMap.computeIfAbsent(x, k -> new HashSet<>());

        List<TreeNode> children = new ArrayList<>();
        for (int y : adjSet) {
            if (father != null && father.val == y) continue;

            children.add(build(y, root));
        }

        root.children = children;
        root.num = 1;
        for (TreeNode child: children) {
            root.num += child.num;
            root.sum += child.sum + child.num;
        }

        return root;
    }
}
__________________________________________________________________________________________________
