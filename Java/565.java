__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int arrayNesting(int[] nums) {
        boolean visited[] = new boolean[nums.length];
        int len = 0;
        for (int i = 0; i < nums.length; i++) {
            if (visited[i]) {
                continue;
            }
            int u = i;
            int count = 0;
            do {
                ++count;
                visited[u] = true;
                u = nums[u];
            } while (!visited[u]);
            len = Math.max(len, count);
        }
        return len;
    }
}
__________________________________________________________________________________________________
sample 40524 kb submission
class Solution {
    public int arrayNesting(int[] nums) {
        boolean[] tmp = new boolean[nums.length];
        int longest = 0;
        for(int i = 0; i < nums.length; i++) {
            int l = 0;
            int index = i;
            while(!tmp[index]) {
                l++;
                tmp[index] = true;
                index = nums[index];
            }
            longest = Math.max(longest, l);
        }
        return longest;
    }
}
__________________________________________________________________________________________________
