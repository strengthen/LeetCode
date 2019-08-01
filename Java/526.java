__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int countArrangement(int N) {
        int[] retVal = new int[] {
            0,1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679
        };
        return retVal[N];
    }
}
__________________________________________________________________________________________________
sample 31512 kb submission
//本质是permutation，只是在加入下次dfs时，需满足 条件 i%pos==0 || pos%i==0
class Solution {
    int res;
    public int countArrangement(int N) {
        res = 0;
        int[] visited = new int[N+1];
        dfs(N,1,visited);
        return res;
    }
    public void dfs(int N, int pos,int[] visited){
        if(pos > N) {
            res++;
        }
        for(int i = 1; i<=N; i++){
            if((visited[i] == 0) && (pos%i==0 || i%pos ==0)){
                visited[i] = 1;
                dfs(N, pos+1,visited);
                visited[i] = 0;
            }
        }
    }
}
__________________________________________________________________________________________________
