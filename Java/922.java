__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int odd = 1;
        for(int even = 0; even < A.length; even += 2){
            if ((A[even] & 1) == 1){
                // find the first unmatch element with odd index
                while( (A[odd] & 1) == 1)
                    odd += 2;
                int tmp = A[even];
                A[even] = A[odd];
                A[odd] = tmp;
            }
        }
        return A;
    }
}
__________________________________________________________________________________________________
sample 40784 kb submission
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int len = A.length;
        int[] res = new int[len];
        Queue<Integer> even = new LinkedList<>();
        Queue<Integer> odd = new LinkedList<>();
        for(int i=0;i<len;i++){
            if(A[i] % 2 == 0){
                even.add(A[i]);
            }else{
                odd.add(A[i]);
            }
        }
        
        for(int j=0;j<len;j++){
            if(j%2==0){
                res[j] = even.poll();
            }else{
                res[j] = odd.poll();
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
