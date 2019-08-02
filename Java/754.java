__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int reachNumber(int target) {
        if (target == 0) {
            return 0;
        }
        target = Math.abs(target);
        int max = (int) (Math.sqrt(2) * Math.sqrt(target)) - 1;
        int sum = max * (max + 1) / 2;
        while (sum < target) {
            max++;
            sum += max;
        }
        
        int diff = sum - target;
        if (diff == 0) {
            return max;
        }
        
        int count = max;
        if (diff % 2 == 0) {
            return count;
        } else {
            if (max % 2 == 0) {
                return count + 1;
            } else {
                return count + 2;
            }
        }
    }
}
__________________________________________________________________________________________________
sample 31512 kb submission
class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        if (target == 1) {
            return 1;
        }
        int cur = (int) Math.sqrt(target * 2);
        int total = cur * (1 + cur) / 2;
        while (total < target) {
            ++cur;
            total += cur;
        }
        while ((total - target) % 2 != 0) {
            ++cur;
            total += cur;
        }
        return cur;
    }
}
__________________________________________________________________________________________________
