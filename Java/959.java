__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int regionsBySlashes(String[] grid) {
                
        // F -1  =  E + C - V 
        
        //Vertex: if connected component does not change ut add an edge 
        
        int[] u = new int[(grid.length+1)*(grid.length+1)];
        
        for(int i=0; i<=grid.length; i++)
            for(int j=0; j<=grid.length; j++){
                u[i*grid.length + j] = i*grid.length +  j;
            }
        
    
    
        //union
       int count =1 ;
       for(int i=0; i<grid.length;i++)
       {
           union(i, i+1, u);
           union(i*grid.length, grid.length * (i+1),u);
           union(grid.length*grid.length+i, grid.length*grid.length+i+1,u);
           union(i*grid.length + grid.length, grid.length * (i*1) + grid.length,u);
       }
           
       for(int i=0; i< grid.length; i++){
          char[] c = grid[i].toCharArray(); 
          for(int j=0; j<c.length; j++){
             int c_m=0; int c_n=0;   
             int n_m=0;  int n_n=0;
              
              if(c[j] == ' ') continue;
              
              else if(c[j]=='/'){
                  c_m = (i+1)*grid.length;
                  c_n = j;
                  n_m = i*grid.length;
                  n_n = j+1;                      
              }
              
              else if(c[j]=='\\'){
                  c_m = i*grid.length;
                  c_n = j;
                  n_m = (i+1)*grid.length;
                  n_n = j+1;    
                  
              }
              
             if(connected(c_m+c_n,n_m+n_n,u)) count++;
             
              union(c_m+c_n,n_m+n_n,u);
             
              }
       }
    
        return count;
    }


     void union(int i, int j, int[] u){
         
         
         int root_i = root(i, u);
         int root_j = root(j, u);
         
         u[root_i] = j;
     }


     int root(int i, int[] u){
         
         
         while(i!=u[i]){
             u[i] = u[u[i]];
             i = u[i];
         }
         
         return i;
     }

     boolean connected(int i, int j, int[] u){
         
         return root(i,u) == root(j,u);
     }
}
__________________________________________________________________________________________________
sample 36884 kb submission
class Solution {
    public int regionsBySlashes(String[] grid) {
        int N = grid.length;
        DSU dsu = new DSU(4 * N * N);
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c) {
                int root = 4 * (r * N + c);
                char val = grid[r].charAt(c);
                if (val != '\\') {
                    dsu.union(root + 0, root + 1);
                    dsu.union(root + 2, root + 3);
                }
                if (val != '/') {
                    dsu.union(root + 0, root + 2);
                    dsu.union(root + 1, root + 3);
                }

                // north south
                if (r + 1 < N)
                    dsu.union(root + 3, (root + 4 * N) + 0);
                if (r - 1 >= 0)
                    dsu.union(root + 0, (root - 4 * N) + 3);
                // east west
                if (c + 1 < N)
                    dsu.union(root + 2, (root + 4) + 1);
                if (c - 1 >= 0)
                    dsu.union(root + 1, (root - 4) + 2);
            }
/**
       north west east south 0 1 2 3
**/
        return dsu.size();
    }
}

class DSU {
    int[] parent;
    int size;
    public DSU(int N) {
        parent = new int[N];
        size = N;
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    public int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    public void union(int x, int y) {
        if (find(x) == find(y)) {
            return;
        }
        parent[find(x)] = find(y);
        size--;
    }
    public int size() {
        return size;
    }
}
__________________________________________________________________________________________________
