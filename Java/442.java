__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int[] mem = new int[nums.length+1];
        for (int i = 0; i < nums.length; i++) {
            if (mem[nums[i]] == 1) {
                ans.add(nums[i]);
            } else {
                mem[nums[i]]++;
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 46304 kb submission
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res=new ArrayList();
        for(int i=0;i<nums.length;i++){
            while(nums[i]!=nums[nums[i]-1]){
                int t=nums[i];
                nums[i]=nums[nums[i]-1];
                nums[t-1]=t;
            }
            if(nums[i]==nums[nums[i]-1]&&nums[i]-1!=i&&!res.contains(nums[i])){
                res.add(nums[i]);
            }
                
        }
        return res;
    }
}  
__________________________________________________________________________________________________
