__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    int[] uf = new int[20000];
    int islands = 0;
    
    public int removeStones(int[][] stones) {
        for(int[] s : stones)
            union(s[0], s[1]);
        return stones.length - islands;
    }
    
    public void union(int row, int col){
        int rowParent = find(row + 1);
        int colParent = find(col + 10001);
        if(rowParent != colParent){
            uf[rowParent] = colParent;
            islands--;
        }
    }
    
    public int find(int x){
        if(uf[x] == 0){
            uf[x] = x;
            islands++;
        }else{
            int parent = uf[x];
            if(uf[parent] != parent)
                uf[x] = find(parent);    
        }
        return uf[x];
    }
}
__________________________________________________________________________________________________
sample 38796 kb submission
class Solution {
    public int removeStones(int[][] stones) {
        if(stones.length == 0) return 0;
        DSU solution = new DSU(stones);
        for(int i = 0 ; i < stones.length ; i++){
            int[] firstStone = stones[i];
            
            for(int j = i + 1 ; j < stones.length ; j++){
                int[] secondStone = stones[j];
                
                if(firstStone[0] == secondStone[0] || firstStone[1] == secondStone[1]){
                    solution.union(i, j);   
                }
            }
        }
        
        Map<Integer, Integer> counts = solution.count();
        int count = 0;
        for(Map.Entry<Integer, Integer> entry: counts.entrySet()){
            count += (entry.getValue() - 1);
        }
        return count;
    }
    
    class DSU{
        int[] parent;
        int[] rank;
        
        DSU(int[][] stones){
            this.parent = new int[stones.length];
            for(int i = 0 ; i < stones.length ; i++){
                this.parent[i] = i;
            }
            this.rank = new int[stones.length];
        }
        
        int find(int index){
            if(parent[index] == index) {
                return index;
            }
            
            parent[index] = find(parent[index]);
            return parent[index];
        }
        
        void union(int index1, int index2){
            int parent1 = find(index1);
            int parent2 = find(index2);
            
            if(parent1 == parent2) {
                return;
            }
            
            if(rank[parent1] > rank[parent2]){
                parent[parent2] = parent1;
            } else if(rank[parent2] > rank[parent1]){
                parent[parent1] = parent2;
            } else {
                parent[parent2] = parent1;
                rank[parent1]++;
            }
        }
        
        Map<Integer, Integer> count(){
            Map<Integer, Integer> parentCount = new HashMap<Integer, Integer>();
            
            for(int index = 0 ; index < parent.length ; index++){
                if(parent[index] != index) parent[index] = find(parent[index]);
                int count = parentCount.getOrDefault(parent[index], 0);
                parentCount.put(parent[index], count + 1);
            }
            
            return parentCount;
        }
    }
}
__________________________________________________________________________________________________
