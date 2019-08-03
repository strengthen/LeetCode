__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            int[] arrRes = new int[10];
            for (int i = 1; i <= 9; i++) arrRes[i] = i;
            return arrRes;
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i <= 9; i++) {
            helper(K, N - 1, i, res);
        }
        int[] arrRes = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            arrRes[i] = res.get(i);
        }
        return arrRes;
    }
    
    public void helper(int N, int k, int cur, List<Integer> res) {
        //System.out.println(cur);
        if (k == 0) {
            res.add(cur);
            return;
        }
         
        int last = cur % 10;
        
        if (N == 0) helper(N, k - 1, cur * 10 + last, res);
        else {
            if (last - N >= 0) {
                helper(N, k - 1, cur * 10 + last - N, res);
            }
            if (last + N <= 9) {
                helper(N, k - 1, cur * 10 + last + N, res);
            }
        }
    }
}
__________________________________________________________________________________________________
sample 34572 kb submission
class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        List<Integer> res = new ArrayList();
        if(N == 0) return new int[0];
        if(N == 1) res.add(0);
        
        dfs(N, K, res, 0);
        
        return res.stream().mapToInt(j->j).toArray();
    }
    
    public void dfs(int N, int K, List<Integer> res, int num){
        if(N == 0){
            res.add(num);
            return;
        }
        
        for(int i = 0; i < 10; i++){
            if(i == 0 && num == 0) continue;
            if(num == 0 && i != 0){
                dfs(N-1, K, res, i);
            }else if(Math.abs(num%10-i) == K){
                dfs(N-1, K, res, num*10+i);
            }
        }
    }
    
    public int[] dpSol(int N, int K){
        List<Integer> res = Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
        
        for(int i = 2; i <= N; i++){
            List<Integer> cur = new ArrayList();
            
            for(int n: res){
                int l = n%10;
                if(n > 0 && l+K < 10){
                    cur.add(n*10 + l+K);
                } 
                if(n > 0 && K > 0 && l-K >= 0){
                    cur.add(n*10 + l-K);
                }
            }
            
            res = cur;
        }
        
        return res.stream().mapToInt(j->j).toArray();
    }
}
__________________________________________________________________________________________________
