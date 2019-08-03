__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        int n=A.length;
        int l=0;
        int[] count=new int[n+1];
        int unique=0,bias=0,res=0;
        for(int r=0;r<n;r++){
            if(++count[A[r]]==1)unique++;
            if(unique>K){
                bias=0;
                --count[A[l++]];
                unique--;
            }
            while(count[A[l]]>1){
                --count[A[l++]];
                bias++;
             
            }
            if(unique==K)res+=bias+1;
        }
        return res;
        
    }
}
__________________________________________________________________________________________________
sample 39464 kb submission
class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        if (A == null || A.length < K) {
            return 0;
        }
        
        int[] hash = new int[A.length + 1];
        
        int l = 0, results = 0, count = 0, result = 1;
        for (int r = 0; r < A.length; ++r) {
            hash[A[r]]++;
            
            if (hash[A[r]] == 1) {
                count++;
            }
            
            if (count > K) {
                count--;
                result = 1;
                hash[A[l]]--;
                l++;
            }
            
            while (hash[A[l]] > 1) {
                result++;
                hash[A[l]]--;
                l++;
            }
            
            if (count == K) {
                results += result;
            }
        }
        
        return results;
    }
}
__________________________________________________________________________________________________
