__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        int[] counts = new int[n];
        int[] levels = new int[n];
        int[] left = new int[n];
        for(int[] edge : edges){
            counts[edge[0]]++;
            counts[edge[1]]++;
        }
        int[] togo = new int[n];
        int c = 0;
        int end = 0;
        int[][] e = new int[n][];
        for(int i = 0; i < n; ++i){
            left[i] = counts[i];
            e[i] = new int[counts[i]];
            if(counts[i] == 1){
                levels[i] = 1;
                togo[end++] = i;
            }
        }
        int maxLevel = 0;
        for(int[] edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            e[n1][--counts[n1]] = n2;
            e[n2][--counts[n2]] = n1;
        }
        while(c < end){
            int curr = togo[c++];
            int level = levels[curr];
            maxLevel = Math.max(maxLevel, level);
            for(int next : e[curr]){
                if(levels[next] != 0) continue;
                if(--left[next] == 1) {
                    levels[next] = level + 1;
                    togo[end++] = next;
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        for(int i = 0; i < n; ++i){
            if(levels[i] == maxLevel) result.add(i);
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
sample 40548 kb submission
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 0) return new ArrayList<>();
        else if (n == 1) {
            List<Integer> ret = new ArrayList<>();
            ret.add(0);
            return ret;
        }
        
        List<Integer>[] lists = new ArrayList[n];
        for(int i=0;i<lists.length;i++)
        {
            lists[i] = new ArrayList();
        }
        
        for(int i=0;i<edges.length;i++)
        {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            lists[n1].add(n2);
            lists[n2].add(n1);
        }
        List<Integer> leaves = new ArrayList();
        for(int i=0;i<lists.length;i++)
        {
            if(lists[i].size()==1)
            {
                leaves.add(i);
            }
        }
        int count =n;
        while(count>2)
        {
            int size = leaves.size();
            count-=size;
            List<Integer> newleaves = new ArrayList();
            for(int i=0;i<size;i++)
            {
                int leave = leaves.get(i);
                for(int j=0;j<lists[leave].size();j++)
                {
                    int srcnode = lists[leave].get(j);
                    lists[srcnode].remove(Integer.valueOf(leave));
                    if (lists[srcnode].size() == 1)
                        newleaves.add(srcnode);
                }
            }
            leaves = newleaves;
        }
        return leaves;
    }
}
__________________________________________________________________________________________________
