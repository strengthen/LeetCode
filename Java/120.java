__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
		if (triangle.size() == 0)
			return 0;
        
		if (triangle.size() == 1)
			return triangle.get(0).get(0);
        
		int[] dp = new int[triangle.size()];
		dp[0] = triangle.get(0).get(0);
		return minimumTotal(triangle, dp, 1);
	}
	
	public int minimumTotal(List<List<Integer>> triangle, int[] dp, int lvlidx) {
		List<Integer> list = triangle.get(lvlidx);
		int pre = dp[0], temp;
		dp[0] += list.get(0);
		for (int i = 1; i < lvlidx; i++) {
			temp = dp[i];
			dp[i] = list.get(i) + Math.min(pre, dp[i]);
			pre = temp;
		}
		dp[lvlidx] = pre + list.get(lvlidx);

		if (lvlidx + 1 == triangle.size()) {
			int res = dp[0];
			for (int i = 1; i <= lvlidx; i++){
				res = Math.min(res, dp[i]);
            }
			return res;
		}

		return minimumTotal(triangle, dp, lvlidx + 1);
	}	
}
__________________________________________________________________________________________________
sample 34244 kb submission
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        if (triangle.size() == 1) {
            return triangle.get(0).get(0);
        }
        
        int[] curr = new int[triangle.size()];
        Arrays.fill(curr, Integer.MAX_VALUE);
        
        curr[0] = triangle.get(0).get(0);
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < triangle.size(); i++) {
            List<Integer> row = triangle.get(i);
            int[] prev = curr.clone();
            for (int j = 0; j < row.size(); j++) {
                if (j == 0) {
                    curr[j] = prev[0] + row.get(j);
                }
                else if (j == row.size() - 1) {
                    curr[j] = prev[row.size() - 2] + row.get(j);
                }
                else {
                    curr[j] = Math.min(prev[j-1], prev[j])+ row.get(j);
                }
                if (i == triangle.size() - 1) {
                    min = Math.min(min, curr[j]);                    
                }
            }
        }
        
        return min;
    }
}
__________________________________________________________________________________________________
