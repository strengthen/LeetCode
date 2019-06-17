__________________________________________________________________________________________________
class Solution {
    public int[][] highFive(int[][] items) {
        Arrays.sort(items, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0])return a[0] - b[0];
                return -(a[1] - b[1]);
            }
        });
        int n = items.length;
        int[][] ret = new int[n][];
        int p = 0;
        for(int i = 0;i < n;){
            int j = i;
            while(j < n && items[i][0] == items[j][0])j++;
            
            int s = 0;
            int num = 0;
            for(int k = 0;k < 5 && k < j-i;k++){
                s += items[k+i][1];
                num++;
            }
            ret[p++] = new int[]{items[i][0], s/num};
            i = j;
        }
        return Arrays.copyOf(ret, p);
    }
}	

__________________________________________________________________________________________________

__________________________________________________________________________________________________
