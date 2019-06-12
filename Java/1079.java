__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    int all = -1;
    int p[] = new int[8];
    
    public int numTilePossibilities(String ts) {
        p[0] = 1;
        for(int i=1;i<=7;++i){
            p[i] = i*p[i-1];
        }
        int tid[] = new int[26];
        int d[] = new int[27];
        int id = 1;
        for(char c:ts.toCharArray()){
            int x = c-'A';
            if(tid[x]==0){
                tid[x] = id++;
            }
            d[tid[x]]++;
        }
        dfs(1,d,0,1,id);
        return all;
    }
    
    public void dfs(int i,int[] d,int sum,int ji,int sz){
        if(i==sz){
            all += p[sum]/ji;
            return;
        }
        for(int x=0;x<=d[i];++x){
            dfs(i+1,d,sum+x,ji*p[x],sz);
        }
    }    
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private int ans = 0;
    
    public int numTilePossibilities(String tiles) {
        int n = tiles.length();
        int[] map = new int[26];
        for (int i = 0; i < n; i++) {
            map[tiles.charAt(i)-'A'] += 1;
        }
        dfs(0, n, map);
        return ans;
    }
    
    private void dfs(int start, int upper, int[] map) {
        if (start == upper) return;
        for (int i = 0; i < 26; i++) {
            if (map[i] > 0) {
                ans++;
                map[i] -= 1;
                dfs(start+1, upper, map);
                map[i] += 1;
            }
        }
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int numTilePossibilities(String tiles) {
        int[] count = new int[26];
        for (char c : tiles.toCharArray()) count[c - 'A']++;
        return dfs(count);
    }
    
    int dfs(int[] arr) {
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == 0) continue;
            sum++;
            arr[i]--;
            sum += dfs(arr);
            arr[i]++;
        }
        return sum;
    }
}