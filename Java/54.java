__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        LinkedList<Integer> ans = new LinkedList<Integer>();
        
        int m = matrix.length;
        
        if( m == 0)
            return (List)(new LinkedList<Integer>());
        
        int n = matrix[0].length;
        
        int x = 0,y = 0;
        
        int d = Math.min(m,n)/2;
        
        if( m == 1)
        {
            for(;y<n;y++)
                ans.add(matrix[x][y]);
            
            return (List)ans;
        }
        
        if(n == 1)
        {
            for(;x<m;x++)
                ans.add(matrix[x][y]);
            
            return (List)ans;
        }
        
        
        int count = m*n;
        
        for(int i = 0; i< d; i++)
        {
             x = i;
             y = i;
            
            for(;y<(n-1-i);y++)
             {ans.add(matrix[x][y]);count--;}
            
            for(;x<(m-1-i);x++)
                {ans.add(matrix[x][y]);count--;}
            
            for(;y>i;y--)
                {ans.add(matrix[x][y]);count--;}
            
            for(;x>i;x--)
                {ans.add(matrix[x][y]);count--;}
        }
            
            x++;
            y++;
            int i = x;
            
            if(count==1)
                {ans.add(matrix[x][y]);count--;}
            
            
            if(m<n && count>0)
            {
                for(;y<(n-i);y++)
                    ans.add(matrix[x][y]);
            }
            
            if(m>n && count>0)
            {
                for(;x<(m-i);x++)
                    ans.add(matrix[x][y]);
            }
        
        return (List)ans;
    }
}
__________________________________________________________________________________________________
sample 34412 kb submission
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        if(matrix == null || matrix.length == 0)
            return list;
        
        int m = matrix.length;
        int n = matrix[0].length;
        boolean used[][] = new boolean[m][n];
        
        int a = 0;
        while(a <= m - 1 - a){
            for (int j = a; j < n - a && a < m && !used[a][j]; j++){                
                list.add(matrix[a][j]);
                used[a][j]=true;
            }            
            for (int i = a + 1; i < m - a && i < m && n-1-a>=0 && !used[i][n-1-a]; i++) {
                list.add(matrix[i][n-1-a]);
                used[i][n-1-a] = true;
            }
            for (int j = n - 2 - a; j >= a && m-1-a>=0 && !used[m-1-a][j]; j--){ 
                list.add(matrix[m - 1 - a][j]);
                used[m-1-a][j] = true;
            }
            for (int i = m - 2 - a; i >= a + 1 && a < n && !used[i][a]; i--){
                list.add(matrix[i][a]);
                used[i][a] = true;
            }
            a++;
        }
                
        return list;
    }
}
__________________________________________________________________________________________________
