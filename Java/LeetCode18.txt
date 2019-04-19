__________________________________________________________________________________________________
3ms
class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
         ArrayList<List<Integer>> ans = new ArrayList<>();
    if(num.length<4)return ans;
    Arrays.sort(num);
    for(int i=0; i<num.length-3; i++){
        if(num[i]+num[i+1]+num[i+2]+num[i+3]>target)break; //first candidate too large, search finished
        if(num[i]+num[num.length-1]+num[num.length-2]+num[num.length-3]<target)continue; //first candidate too small
        if(i>0&&num[i]==num[i-1])continue; //prevents duplicate result in ans list
        for(int j=i+1; j<num.length-2; j++){
            if(num[i]+num[j]+num[j+1]+num[j+2]>target)break; //second candidate too large
            if(num[i]+num[j]+num[num.length-1]+num[num.length-2]<target)continue; //second candidate too small
            if(j>i+1&&num[j]==num[j-1])continue; //prevents duplicate results in ans list
            int low=j+1, high=num.length-1;
            while(low<high){
                int sum=num[i]+num[j]+num[low]+num[high];
                if(sum==target){
                    ans.add(Arrays.asList(num[i], num[j], num[low], num[high]));
                    while(low<high&&num[low]==num[low+1])low++; //skipping over duplicate on low
                    while(low<high&&num[high]==num[high-1])high--; //skipping over duplicate on high
                    low++; 
                    high--;
                }
                //move window
                else if(sum<target)low++; 
                else high--;
            }
        }
    }
    return ans;
    }
}
__________________________________________________________________________________________________
4ms
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        int len = nums.length;
        if (nums == null || len < 4) {
            return result;
        }
        //排序
        Arrays.sort(nums);
        //确定两个值两层循环然后确定左右指针
        //外循环
        for (int i = 0; i < len - 3; i++) {
            //判断相等
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            //最小值大于目标值结束
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            //最大值小于目标值跳过此循环
            if (nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) {
                continue;
            }
            //内循环
            for (int j = i + 1; j < len - 2; j++) {
                //判断相等
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                //最小值大于目标值结束
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                //最大值小于目标值跳过此循环
                if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) {
                    continue;
                }
                //左右指针寻找满足条件的值
                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum == target) {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }

                }
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int second = 0, third = 0, nexti = 0, nextj = 0;
        for(int i=0, L=nums.length; i<L-3; i++) {
            if(nums[i]<<2 > target) return list; // return immediately
            for(int j=L-1; j>i+2; j--) {
                if(nums[j]<<2 < target) break; // break immediately
                int rem = target-nums[i]-nums[j];
                int lo = i+1, hi=j-1;
                while(lo<hi) {
                    int sum = nums[lo] + nums[hi];
                    if(sum>rem) --hi;
                    else if(sum<rem) ++lo;
                    else {
                        list.add(Arrays.asList(nums[i],nums[lo],nums[hi],nums[j]));
                        while(++lo<=hi && nums[lo-1]==nums[lo]) continue; // avoid duplicate results
                        while(--hi>=lo && nums[hi]==nums[hi+1]) continue; // avoid duplicate results
                    }
                }
                while(j>=1 && nums[j]==nums[j-1]) --j; // skip inner loop
            }
            while(i<L-1 && nums[i]==nums[i+1]) ++i; // skip outer loop
        }
        return list;
    }
}
__________________________________________________________________________________________________
36144 kb
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
		ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
		int len = nums.length;
		if (nums == null || len < 4)
			return res;

		Arrays.sort(nums);

		int max = nums[len - 1];
		if (4 * nums[0] > target || 4 * max < target)
			return res;

		int i, z;
		for (i = 0; i < len; i++) {
			z = nums[i];
			if (i > 0 && z == nums[i - 1])// avoid duplicate
				continue;
			if (z + 3 * max < target) // z is too small
				continue;
			if (4 * z > target) // z is too large
				break;
			if (4 * z == target) { // z is the boundary
				if (i + 3 < len && nums[i + 3] == z)
					res.add(Arrays.asList(z, z, z, z));
				break;
			}

			threeSumForFourSum(nums, target - z, i + 1, len - 1, res, z);
		}

		return res;
	}

	/*
	 * Find all possible distinguished three numbers adding up to the target
	 * in sorted array nums[] between indices low and high. If there are,
	 * add all of them into the ArrayList fourSumList, using
	 * fourSumList.add(Arrays.asList(z1, the three numbers))
	 */
	public void threeSumForFourSum(int[] nums, int target, int low, int high, ArrayList<List<Integer>> fourSumList,
			int z1) {
		if (low + 1 >= high)
			return;

		int max = nums[high];
		if (3 * nums[low] > target || 3 * max < target)
			return;

		int i, z;
		for (i = low; i < high - 1; i++) {
			z = nums[i];
			if (i > low && z == nums[i - 1]) // avoid duplicate
				continue;
			if (z + 2 * max < target) // z is too small
				continue;

			if (3 * z > target) // z is too large
				break;

			if (3 * z == target) { // z is the boundary
				if (i + 1 < high && nums[i + 2] == z)
					fourSumList.add(Arrays.asList(z1, z, z, z));
				break;
			}

			twoSumForFourSum(nums, target - z, i + 1, high, fourSumList, z1, z);
		}

	}

	/*
	 * Find all possible distinguished two numbers adding up to the target
	 * in sorted array nums[] between indices low and high. If there are,
	 * add all of them into the ArrayList fourSumList, using
	 * fourSumList.add(Arrays.asList(z1, z2, the two numbers))
	 */
	public void twoSumForFourSum(int[] nums, int target, int low, int high, ArrayList<List<Integer>> fourSumList,
			int z1, int z2) {

		if (low >= high)
			return;

		if (2 * nums[low] > target || 2 * nums[high] < target)
			return;

		int i = low, j = high, sum, x;
		while (i < j) {
			sum = nums[i] + nums[j];
			if (sum == target) {
				fourSumList.add(Arrays.asList(z1, z2, nums[i], nums[j]));

				x = nums[i];
				while (++i < j && x == nums[i]) // avoid duplicate
					;
				x = nums[j];
				while (i < --j && x == nums[j]) // avoid duplicate
					;
			}
			if (sum < target)
				i++;
			if (sum > target)
				j--;
		}
		return;
	}
}
__________________________________________________________________________________________________
36152 kb
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        if(nums.length==0)  return new ArrayList<>();
        Arrays.sort(nums);
        List<List<Integer>> res =  new ArrayList<>();
        
        for(int i=0;i<nums.length-3;i++){
        	if(i>0 && nums[i]==nums[i-1]) continue;
            
            List<List<Integer>> threesum = threeSum(nums, i+1, target-nums[i]);
            for(List<Integer> list: threesum){
                list.add(nums[i]);
                res.add(list);
            }
        }
        return res;
    }
    
    public List<List<Integer>> threeSum(int[] nums, int s, int t) {
        List<List<Integer>> ret =  new ArrayList<>();
        for(int i=s; i<nums.length-2;i++){
        	if(i>s&&nums[i]==nums[i-1]) continue;
            int target = t - nums[i];
            int j=i+1, k=nums.length-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);list.add(nums[j]);list.add(nums[k]);
                    ret.add(list);
                    while(j<nums.length-1 && nums[j]==nums[j+1])j++;
                    while(k>s && nums[k]==nums[k-1])k--;
                    j++;    k--;
                }else if(nums[j]+nums[k]>target) k--;
                else j++;
            }
        }
        return ret;
    }
}
__________________________________________________________________________________________________
