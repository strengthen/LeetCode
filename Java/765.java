__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    int[] root;
    public int minSwapsCouples(int[] row) {
        int n = row.length;
        root = new int[n / 2];
        for (int i = 0; i < n / 2; i++) {
            root[i] = i;
        }
        int res = n / 2;
        for (int i = 0; i < n; i+=2) {
            int a = find(row[i] / 2);
            int b = find(row[i + 1] / 2);
            if (a != b) {
                root[a] = b;
                res--;
            }
        }
        return n / 2 - res;
    }
    
    private int find(int x) {
        return root[x] = (root[x] == x) ? x : find(root[x]);
    }
}
__________________________________________________________________________________________________
sample 35420 kb submission
class Solution {
    public int minSwapsCouples(int[] row) {
        int n = row.length;
        int pair[] = new int[n], pos[] = new int[n];
        
        for ( int i = 0; i < n; i++ ) {
            if ( i % 2 == 0 ) pair[i] = i + 1;
            else pair[i] = i - 1;
            
            pos[ row[i] ] = i; // the perseon row[i] is sitting at position i  
        }
        
                //      
        //row[i]
        int ans = 0;
        for ( int i = 0; i < n; i++ ) { // seat from 0 -> n
            for ( int j = pair[ pos[ pair[ row[i] ] ] ]; j != i ; j = pair[ pos[ pair[ row[i] ] ] ] ) {
                swap( row, i, j );
                swap( pos, row[i], row[j] );
                ans++;
            }
        }
        
        return ans;
    }
    
    private void swap ( int[] nums, int i, int j ) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
__________________________________________________________________________________________________
