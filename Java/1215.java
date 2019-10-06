__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
    public int[] countSteppingNumbers(int low, int high) {
        int c1 = ct(low), c2 = ct(high);
        List<Long> re = new ArrayList<>();
        for(int i = c1; i <= c2; i++) {
            get(re, i);
        }
        List<Integer> temp = new ArrayList<>();
        for(long i: re) {
            if(i >= low && i <= high) temp.add((int)(i));
        }
        int[] r = new int[temp.size()];
        for(int i = 0; i < r.length; i++) r[i] = temp.get(i);
        return r;
    }
    int ct(int val) {
        if(val == 0) return 1;
        int re = 0;
        while(val > 0) {
            re++;
            val /= 10;
        }
        return re;
    }
    void get(List<Long> re, int l) {
        if(l == 1) re.add(0l);
        for(long i = 1; i <= 9; i++) dfs(re, 0, i, l);
    }
    void dfs(List<Long> re, int p, long val, int l) {
        if(val < 0) return;
        if(p == l - 1) {
            if(val > Integer.MAX_VALUE) return;
            re.add(val); return;
        }
        if(val % 10 == 0) {
            dfs(re, p + 1, val * 10 + 1, l);
        }
        else if(val % 10 == 9) {
            dfs(re, p + 1, val * 10 + 8, l);
        }
        else {
        dfs(re, p + 1, val * 10 + val % 10 - 1, l);
        dfs(re, p + 1, val * 10 + val % 10 + 1, l);
        }
    }
}
__________________________________________________________________________________________________
22ms
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        TreeSet<Integer> ans = new TreeSet();
        
        for (int i = 0; i < 10; i++)
            help(i, low, high, ans);
        
        return new ArrayList(ans);
    }
    
    private void help(int n, int low, int high, TreeSet<Integer> ans) {
        if (n <= high && n >= low)
            ans.add(n);
        
        if (n > high || (long) n * 10 >= Integer.MAX_VALUE)
            return;
        
        if (n % 10 != 0)
            help(n % 10 - 1 + n * 10, low, high, ans);
        if (n % 10 != 9)
            help(n % 10 + 1 + n * 10, low, high, ans);
    }
}
__________________________________________________________________________________________________
