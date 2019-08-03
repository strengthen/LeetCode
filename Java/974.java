__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int sum = 0;
        int ans = 0;
        int[] map = new int[K];
        map[0] = 1;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            int tmp = sum % K;
            if (tmp < 0) tmp += K;
            ans += map[tmp];
            map[tmp]++;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 39732 kb submission
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int prefix = 0;
        int count = 0;
        for(int num : A) {
            prefix = (prefix + num) % K;
            if(prefix < 0) prefix += K;
            count += map.getOrDefault(prefix,0);
            map.put(prefix, map.getOrDefault(prefix,0)+1);
        }
        return count;
    }
}
__________________________________________________________________________________________________
