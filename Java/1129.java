__________________________________________________________________________________________________
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        int[] d = new int[2*n];
        Queue<Integer> q = new ArrayDeque<>();
        Arrays.fill(d, 999999999);
        d[0] = d[n] = 0;
        q.add(0);
        q.add(n);
        while(!q.isEmpty()){
            int cur = q.poll();
            if(cur < n){
                for(int[] r : red_edges){
                    if(r[0] == cur && d[r[1]+n] > d[cur] + 1){
                        d[r[1]+n] = d[cur] + 1;
                        q.add(r[1]+n);
                    }
                }
            }else{
                for(int[] r : blue_edges){
                    if(r[0] == cur-n && d[r[1]] > d[cur] + 1){
                        d[r[1]] = d[cur] + 1;
                        q.add(r[1]);
                    }
                }
            }
        }
        int[] ret = new int[n];
        for(int i = 0;i < n;i++){
            ret[i] = Math.min(d[i], d[i+n]);
            if(ret[i] > 5000000){
                ret[i] = -1;
            }
        }
        return ret;
    }
}	

__________________________________________________________________________________________________

__________________________________________________________________________________________________
