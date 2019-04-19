__________________________________________________________________________________________________
1msclass Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 2) return nums.length;
        int currentIdx = 0;
        int nextIdx = 1;
        while(nextIdx < nums.length ) {
            while(nextIdx < nums.length && nums[currentIdx] == nums[nextIdx]) {
                nextIdx++;
            }
            if(nextIdx < nums.length)
               nums[++currentIdx] = nums[nextIdx];
            nextIdx++;
        }
        return currentIdx+1;
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int removeDuplicates(int[] nums) {
        int slow = 0, fast = 0;
        Set<Integer> set = new HashSet<>();
        int res = 0;
        while(fast < nums.length) {
            if(set.add(nums[fast])) {
                nums[slow] = nums[fast];
                res++;
                slow++;
            }
            fast ++;
        }
        return res;
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public int removeDuplicates(int[] nums) {
        Set<Integer> set = new TreeSet<>();
        for(int i = 0; i<nums.length; i++){

            set.add(nums[i]);

        }
        Iterator<Integer> iterator = set.iterator();
        int i = 0;
        while (iterator.hasNext()){
            nums[i++] = iterator.next();
        }
        return set.size();
    }
}
__________________________________________________________________________________________________
36584 kb
class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 0;
        int j = 0;
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[j]==nums[i]){
                continue;
            }
            else{
                nums[++j] = nums[i];
                //nums[i] = 0;
                count++;
            }
        }
        return count+1;
    }
}
__________________________________________________________________________________________________
36720 kb
public class Solution {
    public int removeDuplicates(int[] A) {
        if (A == null || A.length == 0) return 0; //can do "if len < 2 return A.len"
        int pre = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] != A[pre]) {
                A[++pre] = A[i];
            }
        }

        return pre + 1;
    }
}
__________________________________________________________________________________________________
