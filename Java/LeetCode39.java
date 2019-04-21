__________________________________________________________________________________________________
0ms
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        
        if (candidates == null || candidates.length == 0) {
            return ans;
        }
        
        int[] visited = new int[candidates.length];
        bt(candidates, visited, 0, target, ans);
        return ans;
    }
    
    public void bt(int[] candidates, int[] visited, int start, int target, List<List<Integer>> ans) {
        if (target == 0) {
            List<Integer> combination = new LinkedList<>();
            for (int i = 0; i < visited.length; i++) {
                for (int j = 0; j < visited[i]; j++) {
                    combination.add(candidates[i]);
                }
            }
            ans.add(combination);
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            if (target - candidates[i] >= 0) {
                visited[i]++;
                bt(candidates, visited, i, target - candidates[i], ans);
                visited[i]--;
            }
        }
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        cal(candidates, target, res, new ArrayList<>(), 0);
        return res;
    }
    
    public void cal(int[] ll, int target, List<List<Integer>> res, List<Integer> row, int k){
        for(int i = k; i < ll.length; i++){
            if(target == ll[i]){
                row.add(ll[i]);
                res.add(new ArrayList<>(row));
                row.remove(row.size()-1);
                break;
            } else if(target < ll[i]) {
                break;
            } else {
                row.add(ll[i]);
                cal(ll, target - ll[i], res, row, i);
                row.remove(row.size()-1);
            }
        }
    }
}
__________________________________________________________________________________________________
5ms
class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res =  new ArrayList<List<Integer>>();
        Stack<Integer> temp = new Stack<Integer>();
        int tempCount = 0;
        int used = -1;
        combine(res, candidates, target, temp, tempCount, used);
        return res;
    }

    public void combine(List<List<Integer>> res, int[] candidates, int target, Stack<Integer> temp, int tempCount, int used){
        for(int i = 0; i < candidates.length; i++){
            if(i < used){
                continue;
            }
            if(tempCount + candidates[i] == target){
                temp.push(candidates[i]);
                List<Integer> tempRes = new ArrayList<Integer>();
                tempRes.addAll(temp);
                res.add(tempRes);
                temp.pop();

                return;
            }else if(tempCount + candidates[i] > target){
                return;
            }else{
                temp.push(candidates[i]);
                combine(res, candidates, target, temp, tempCount+candidates[i], i);
                temp.pop();
            }
        }
    }
}
__________________________________________________________________________________________________
35752 kb 
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
    	List<List<Integer>> res = new ArrayList<>();

        List<List<Integer>> [] dp = new List[target + 1];
        dp[0] = new ArrayList<>();
        for(int i = 1; i <= target; i++)
        {
        	dp[i] = new ArrayList<>();
        	for(int coin: candidates)
        	{
        		if(coin > i) continue;

        		if(coin == i)
        		{
        			dp[i].add(Arrays.asList(coin));
        		} else {
        			for(List<Integer> list: dp[i - coin])
        			{
        				if(coin >= list.get(list.size() - 1))
        				{
        					List<Integer> tmp = new ArrayList<>(list);
        					tmp.add(coin);
        					dp[i].add(tmp);
        				}
        			}
        		}

        	}
        }
        return dp[target];
    }
}
__________________________________________________________________________________________________
35816 kb
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new LinkedList<>();
        List<Integer> permutes = new LinkedList<>();
       
        dfs(res, permutes,candidates, target,0);
        return res;
    }
    
    public void dfs(List<List<Integer>> res, List<Integer> permutes, int[] candidates, int target,int start){
        if(target == 0 ){
            res.add(new LinkedList<>(permutes));
            return;
        }
        for(int i = start;i<candidates.length;i++){
            if(candidates[i] <= target){
                permutes.add(candidates[i]);
                dfs(res, permutes,candidates,target-candidates[i],i);
                permutes.remove(permutes.size()-1);
            }
        }
    }
}
__________________________________________________________________________________________________