__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public void moveZeroes(int[] nums) {
        if(nums == null)
            return;
        int pos1 = 0;
        int pos2 = 0;
        while(pos2 < nums.length){
            if(nums[pos2] == 0){
                ++pos2;
                continue;
            }
            if(pos1 != pos2)
                swap(nums, pos1, pos2);
            ++pos1;
            ++pos2;
        }
    }
    
    private void swap(int[] arr, int pos1, int pos2){
        int cache = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = cache;
    }
}
__________________________________________________________________________________________________
sample 35036 kb submission
class Solution {
    public void moveZeroes(int[] nums) {
        Integer[] n = Arrays.stream( nums ).boxed().toArray( Integer[]::new );
        Arrays.sort(n, (a,b)->{ 
            if(a==0) return 1;
            if(b==0) return -1;
            return 0;
                               });
        for(int i=0;i<n.length;i++){
            nums[i]=n[i];
        }
    }
}
__________________________________________________________________________________________________
