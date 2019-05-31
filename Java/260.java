__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] singleNumber(int[] nums) {
        int x = 0;
        for (int i : nums) {
            x ^= i;
        }
        int mask = 1;
        while ((mask & x) == 0) {
            mask <<= 1;
        }
        int copy = x;
        for (int i : nums) {
            if ((i & mask) != 0) {
                x = x ^ i;
            }
        }
        return new int[]{x, copy ^ x};
    }
}
__________________________________________________________________________________________________
sample 34824 kb submission
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] res=new int[2];
        Set<Integer> set=new HashSet<>();
        for(int n: nums){
            if(set.contains(n)){
                set.remove(n);
            }else{
                set.add(n);
            }
        }
        int i=0;
        for(int n: set){
            res[i]=n;
            i++;
        }
        return res;
    }
}
__________________________________________________________________________________________________
