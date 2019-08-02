__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k<=1) return 0;
        int prod = 1, left = 0, cnt = 0;
        
        for(int right = 0; right < nums.length; right++){
            prod *= nums[right];
            
            while(prod>=k){
                prod /= nums[left++];
            }
            
            cnt += right - left + 1;
        }
        
        return cnt;
    }
}
__________________________________________________________________________________________________
sample 52776 kb submission
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        
        List<Integer> prevs = new LinkedList<>();
        int subCount = 0; 
        for(int num : nums){
            List<Integer> currs = new LinkedList<>();
            if(num < k){
                if(num==1){
                    prevs.add(0,1);
                    currs=prevs;
                }else{
                    currs.add(num);
                    int prod = 0;
                    while(!prevs.isEmpty() && prod<k){
                        int prev = prevs.remove(0);
                        prod = prev*num;
                        if(prod < k){
                            currs.add(prod);
                        }
                    }
                }
            }
            subCount += currs.size();
            prevs = currs;
        }
        return subCount;
        
    }
}
__________________________________________________________________________________________________
