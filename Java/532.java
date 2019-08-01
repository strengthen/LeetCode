__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) {
            return 0;
        }

        Arrays.sort(nums);

        int left = 0, right = 1, count = 0;

        while (right < nums.length) {
            if (nums[right] - nums[left] > k) {
                left++;
            } else if (left == right || nums[right] - nums[left] < k) {
                right++;
            } else {
                count++;
                left++;
                right++;
                while (right < nums.length && nums[right] == nums[right - 1]) {
                    right++;
                }
            }
        }

        return count;
    }
}
__________________________________________________________________________________________________
sample 38520 kb submission
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) {
             return 0;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            map.compute(n + k, (key, value) -> value == null ? 1 : value + 1);
        }
        Set<List<Integer>> set = new HashSet<>();
        for (int num : nums) {
            Integer value = map.get(num);
            if (value != null) {
                int a = Math.min(num, num - k);
                int b = Math.max(num, num - k);
                if (k == 0) {
                    if (value > 1) {
                        set.add(Arrays.asList(num, num));
                    }
                } else {
                    set.add(Arrays.asList(a, b));
                }
            }
        }
        return set.size();
    }
}
__________________________________________________________________________________________________
