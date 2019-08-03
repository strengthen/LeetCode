__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxTurbulenceSize(int[] A) {
        return helper(A,0);   
    }
    private int helper(int [] A,int index){
        if(index >= A.length - 1){
            return A.length - index;
        }
        int len =2;
        index+=2;
        int prev = A[index-1]  - A[index-2];
        if(prev == 0){
            int next = helper(A,index-1);
            return 1>next?1:next;
        }
        while(index<A.length){
            int d =A[index] - A[index-1];
            if(d == 0){
                break;
            }
            if((prev^d)<0){
                len++;
                index++;
                prev =d; 
            }
            else{
                break;
            }
        }
        
        int next = helper(A,index-1);
        return next> len?next:len;
    }
}
__________________________________________________________________________________________________
sample 42196 kb submission
class Solution {
    public int maxTurbulenceSize(int[] A) {
        if(A.length == 1)
            return 1;
        int N = A.length;
        int res = 1,tmp = 1;
        int[] dp = new int[N];
        for(int i =0; i<N-1; i++){
            if(A[i] > A[i+1])
                dp[i] = 1;
            else if(A[i] < A[i+1])
                dp[i] = 0;
            else
                dp[i] = 2;
        }
        for(int i=0; i<N-1; i++){
            if(dp[i] == 2){
                res=Math.max(res, tmp);
                tmp=1;
            }else if(dp[i] == dp[i+1]){
                res=Math.max(res, tmp+1);
                tmp=1;
            }else{
                tmp++;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
