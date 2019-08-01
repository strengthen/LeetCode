__________________________________________________________________________________________________
sample 4 ms submission
import javafx.util.Pair;
class Solution {
    public int findNumberOfLIS(int[] nums) {
        List<Pair<Integer, Integer>>[] hs = new ArrayList[nums.length];
        int len = 0;
        for(int n : nums){
            int left = 0;
            int right = len;
            //找到大于等于n 的最小值
            while(left < right){
                int mid = (right - left)/2 + left;
                int last = hs[mid].size()-1;
                if(hs[mid].get(last).getKey() < n){
                    left = mid+1;
                }else{
                    right = mid;
                }
                
            }
            int options = 1;
            if(left > 0){
                int row = left-1;
                int l1 = 0;
                int r1 = hs[row].size();
                while(l1 < r1){
                    int mid = (r1 - l1)/2 + l1;
                    if(hs[row].get(mid).getKey() < n){
                        r1 = mid;
                    }else{
                        l1 = mid+1;
                    }
                }
                options = hs[row].get(hs[row].size()-1).getValue();
                options -= l1 == 0 ? 0 : hs[row].get(l1-1).getValue();
            }
           
            if(hs[left] == null) hs[left] = new ArrayList<Pair<Integer, Integer>>();
            int tmp = (hs[left].size() == 0 ? 0: hs[left].get(hs[left].size()-1).getValue()) + options;
            hs[left].add(new Pair(n, tmp));
            if(left == len) len++;
            
        }
        return len == 0 ? 0: hs[len-1].get(hs[len-1].size()-1).getValue();
    }
}
__________________________________________________________________________________________________
sample 37052 kb submission
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int N = nums.length;
        if (N < 2) return N;
        
        int[] length = new int[N]; // length of LIS up until nums[i]
        int[] count = new int[N]; // number of LIS up until nums[i]
        
        // Initialise array properly: Single element is a LIS of length 1
        Arrays.fill(length, 1);
        Arrays.fill(count, 1);
        
        int longest = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                
                if (length[j] >= length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }
            
            longest = Math.max(longest, length[i]);
        }
        
        int lis = 0;
        for (int i = 0; i < N; i++) {
            lis += length[i] == longest ? count[i] : 0;
        }
        return lis;
    }
}
__________________________________________________________________________________________________
