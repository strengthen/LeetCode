__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        int count = 0;
        int res = 0;
        int start=0;
        for(int i=0;i<A.length;i++){
            if(A[i]>R){
                count=0;
                start = i+1;
            }else if(A[i]>=L){
                count = i-start+1;
            }
            res+=count;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 48868 kb submission
class Solution {
    private int result=0;
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        if(A.length==0)
            return result;
        for(int i=0;i<A.length;i++)
       { 
           List<Integer> list=new ArrayList<Integer>();
            combine(A,L,R,i,list,Integer.MIN_VALUE);
        }
        return result;
    }
    
    public void combine(int[] A, int L, int R, int currindex, List<Integer> list, int currmax){
        if(currindex==A.length || Math.max(currmax,A[currindex])>R)
            return; 
        if(Math.max(currmax,A[currindex])>=L && Math.max(currmax,A[currindex])<=R)
           result++;
        
        list.add(A[currindex]);
        combine(A,L,R,currindex+1,list,Math.max(currmax,A[currindex]));
    }
}
__________________________________________________________________________________________________
