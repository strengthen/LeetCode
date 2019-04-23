__________________________________________________________________________________________________
18ms
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
      Arrays.sort(nums);   //Time: O(nlogn)
        int target =0;
      List<List<Integer>> res = new ArrayList();
      for (int i=0; i<nums.length-2; i++) {  //Time: O(n^2)
          if (i>0 && nums[i]==nums[i-1] ) continue;   //skip dup
          twoSum(nums, i+1, nums.length-1, target-nums[i], res);
      }  
      return res;
  }
  private void twoSum(int[] nums, int left, int right, int target, List<List<Integer>> res ) {
      int tmp = nums[left-1], sum=0;
      int small=0, large=0;
      while (left < right) {
          sum = nums[left]+nums[right];
          small = nums[left];
          large = nums[right];
          if (sum==target) {
              res.add(Arrays.asList(tmp, nums[left++], nums[right--])); 
              while (left < right && nums[left]==small) left++;    //skip dup
              while (left < right && nums[right]==large) right--;  //skip dup
          } else if (sum < target) {
              left ++; 
          } else {
              right--;
          }
      }
      return;
    }
}
__________________________________________________________________________________________________
22ms
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
      Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]>0)break;
            if(i>0&&nums[i]==nums[i-1])continue;
            int l = i + 1;
            int r = nums.length - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    list.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    do {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                    do {
                        r--;
                    } while (l < r && nums[r] == nums[r + 1]);
                }
            }
        }
        return list;
    }
}
__________________________________________________________________________________________________
24ms
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new LinkedList();
        Arrays.sort(nums);
        if(nums.length <3 || nums[0] > 0 || nums[nums.length - 1] < 0) return ans;
        for(int i = 0; i < nums.length - 2 ; i++)
        {
            if(nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int begin = i + 1, end = nums.length - 1, sum = 0;
            while(begin < end)
            {
                sum = nums[begin] + nums[end] + nums[i];
                if(sum < 0) begin++;                
                else if(sum > 0) end--;                
                else
                {
                    ans.add(Arrays.asList(nums[i], nums[begin], nums[end]));
                    begin++; end--;
                    while(begin < end && nums[end] == nums[end+1]) end--;                    
                    while(begin < end && nums[begin] == nums[begin-1]) begin++;                    
                }
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
42928 kb
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int l = nums.length;
        Arrays.sort(nums);
        ArrayList ans = new ArrayList();
        if(l<3 || 0 < nums[0]*3 || 0 > nums[l-1]*3){
            return(ans);
        }
        for(int i=0;i<l-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int start = i+1;
                int end = l-1;
                while(end>start){
                    int val = nums[start]+nums[end]+nums[i];
                    if(val==0){
                        ans.add(new int[] {nums[i],nums[start],nums[end]});
                    }
                    if(val<0){
                        int temp = start;
                        while(nums[temp]==nums[start] && end>start){
                            start+=1;
                        }
                    }
                    else{
                        int temp = end;
                        while(nums[temp]==nums[end] && end>start){
                            end-=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
43208 kb 
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null || nums.length < 3) {
            return results;
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            int target = -nums[i];
            List<List<Integer>> twoSumResults = twoSum(nums, i + 1, target);
            if (twoSumResults != null) {
                for (List<Integer> twoSumResult : twoSumResults) {
                    twoSumResult.add(0, nums[i]);
                }
                results.addAll(twoSumResults);
            }
            while ((i < nums.length - 1) && (nums[i + 1] == nums[i])) {
                i++;
            }
        }
        return results;
    }
    private List<List<Integer>> twoSum(int[] nums, int start, int target) {
        int left = start;
        int right = nums.length - 1;
        List<List<Integer>> results = new ArrayList<>();
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                List<Integer> result = new ArrayList<>();
                result.add(nums[left]);
                result.add(nums[right]);
                results.add(result);
                left++;
                right--;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
            while ((left >= start + 1) && (left < right) && (nums[left]  == nums[left - 1])) {
                left++;
            }
            while ((right <= nums.length - 2) && (left < right) && (nums[right] == nums[right + 1])) {
                right--;
            }
        }
        return results;
    }
}
__________________________________________________________________________________________________
