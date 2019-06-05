__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        /*
                List<Integer> res = new ArrayList();
        if(nums.length == 0)
            return res;
        Arrays.sort(nums);
        int n = nums.length, maxLen = 0, maxIdx = 0; 
        int[] dp = new int[n];        
        int[] pre = new int[n];
        
        for(int i = 0; i < n; i++){           
            dp[i] = 1;
            pre[i] = -1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }                    
                }                    
            }
            
            if(dp[i] > maxLen){
                maxLen = dp[i];
                maxIdx = i;
            }                        
        }
                
        while(maxIdx >= 0){
            res.add(nums[maxIdx]);
            maxIdx = pre[maxIdx];
        }
        return res;*/
        
        List<Integer> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        Arrays.sort(nums);
        sorted = nums;
        maxNum = nums[nums.length-1];
        len = new int[nums.length];
        next = new int[nums.length];
        longestChainHead = -1; 
        maxLen = 0;
        int limit = maxNum;
        for (int i = 0; i < nums.length && nums[i] <= limit; i++) {
            dp(i, 1);
            limit = maxNum >> maxLen;
        }
        while (longestChainHead != -1) {
            res.add(nums[longestChainHead]);
            longestChainHead = next[longestChainHead];
        }
        return res;
    }
		
    private int[] sorted;
    private int[] len;
    private int[] next;
    private int longestChainHead;
    private int maxLen;
    private int maxNum;
	
    private void dp(int start, int preLen) {
        if (len[start] == 0) { 
            len[start] = 1;
            next[start] = -1;
        }
        if (len[start] > maxLen) {
            maxLen = len[start];
            longestChainHead = start;
        }
        int limit = maxNum >> Math.max(maxLen - preLen, 0); 
        int max = 0;
        for (int i = start + 1; i < sorted.length && sorted[i] <= limit; i++) {
            if (sorted[i] % sorted[start] == 0) {
                if (len[i] == 0) {
                    dp(i, preLen + 1);
                } 
                if (len[i] > max) {
                    max = len[i];
                    len[start] = len[i] + 1;
                    next[start] = i;
                    if (len[start] > maxLen) {
                        maxLen = len[start];
                        longestChainHead = start;
                        limit = maxNum >> Math.max(maxLen - preLen, 0);
                    }           
                }
            }
        }
    }
}
__________________________________________________________________________________________________
sample 35232 kb submission
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Integer> results = new ArrayList<>();
        if (nums == null || nums.length == 0) return results;    
        if (nums.length == 1) { results.add(nums[0]); return results; }
        Arrays.sort(nums);
        int[] dp = new int[nums.length];
        int[] prev = new int[nums.length]; Arrays.fill(prev, -1);
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    //System.out.println(String.format("i:%d, j: %d", nums[i], nums[j]));
                    int num = dp[j] + 1;
                    if (num > dp[i]) { dp[i] = num; prev[i] = j; }
                }
            }
        }
        int max = Arrays.stream(dp).max().getAsInt();
        //System.out.println(max);
        //for (int i = 0; i < nums.length; i++) System.out.print(prev[i]);
        //System.out.println();
        for (int i = 0; i < nums.length; i++) {
            if (dp[i] == max) {
                do {
                    results.add(nums[i]);
                    i = prev[i];
                } while (i != -1);
                break;
            }
        }
        Collections.reverse(results);
        return results;
    }
}
__________________________________________________________________________________________________
