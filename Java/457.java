__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean circularArrayLoop(int[] nums) {
        if (nums == null || nums.length < 2) {
            return false;
        } 
        
        int len = nums.length;        
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                continue;
            }
            
            int slow = i;
            int fast = i;
             while (nums[i] * nums[fast] > 0 && nums[i] * nums[getNextIndex(nums, fast)] > 0) {
                slow = getNextIndex(nums, slow);
                fast = getNextIndex(nums, getNextIndex(nums, fast));                
                 if (slow == fast) {
                    if (slow == getNextIndex(nums, slow)) {
                        break; 
                    } 
                    return true;
                }                
            }                    
            slow = i;
            int sgn = nums[i];
            while (sgn * nums[slow] > 0) {
                int tmp = getNextIndex(nums, slow);
                nums[slow] = 0;
                slow = tmp;
            }
            // int nextIndex = i;
            // int startNum = nums[i];
            // while (startNum * nums[nextIndex] > 0) {
            //     nums[nextIndex] = 0;
            //     nextIndex = getNextIndex(nums, nextIndex);
            // }
        }
        return false;
    }
    
    private int getNextIndex(int[] nums, int i) {
         int len = nums.length;
        return (i + nums[i]) >= 0 ? ((i + nums[i]) % len) : ((i + nums[i]) % len) + len;
    }
}
__________________________________________________________________________________________________
sample 35356 kb submission
class Solution {
    public boolean circularArrayLoop(int[] a) {
        if(a.length < 2) return false;
        for(int idx = 0; idx < a.length; idx++) {
            if(a[idx] == 0) continue;
            int s = idx, f = idx, n = a.length;
            do {
                s = getNext(a, s);
                f = getNext(a, getNext(a, f));
            } while(s != f);

            if(s == getNext(a, s)) continue;

            boolean flag = true;
            f = s;
            do {
                if(a[f] * a[getNext(a, f)] < 0) {
                    flag = false;
                    break;
                }
                f = getNext(a, f);
            } while(s != f);
            if(flag) return true;

            s = idx;
            do {
                f = getNext(a, s);
                a[s] = 0;
                s = f;
            } while(a[s] != 0);
        }
        return false;
    }
    
    private int getNext(int[] nums, int idx){
        //get the nextIdx.
        int val = idx + nums[idx];
        int n = nums.length;
        return val >= 0 ? val % n : val % n + n;
    }
}
__________________________________________________________________________________________________
