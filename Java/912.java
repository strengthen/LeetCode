__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] sortArray(int[] nums) {
        int[] res = new int[nums.length];
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        if (nums.length % 2 != 0) {
            max = nums[0];
            min = nums[0];
        }
        for (int i = nums.length % 2 == 0 ? 0 : 1; i < nums.length; i += 2) {
            int localMax = nums[i];
            int localMin = nums[i];
            if (nums[i + 1] > nums[i]) {
                localMax = nums[i + 1];
            } else {
                localMin = nums[i + 1];
            }
            max = Math.max(max, localMax);
            min = Math.min(min, localMin);
        }
        int[] count = new int[max - min + 1];
        for (int i : nums) {
            count[i - min]++;
        }
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        for (int i : nums) {
            res[--count[i - min]] = i;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 42756 kb submission
class Solution {
    public int[] sortArray(int[] nums) {
		
		List<Integer> list = Arrays.stream(nums).boxed().collect(Collectors.toList());
		
		Collections.sort(list);
		
        return list.stream().mapToInt(i -> (Integer)i).toArray();
    }
}
__________________________________________________________________________________________________
