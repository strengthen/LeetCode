__________________________________________________________________________________________________
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        int n = arr1.length;
		
        //sort and generate new arr2
        Arrays.sort(arr2);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < arr2.length; i++){
            if (i+1 < arr2.length && arr2[i] == arr2[i+1])
                continue;
            list.add(arr2[i]);
        }
        int[] newarr2 = new int[list.size()];
        for (int i = 0; i < list.size(); i++)
            newarr2[i] = list.get(i);
        arr2 = newarr2;
        
		//generate new arr1
        int[] newarr1 = new int[n+2];
        for (int i = 0; i < n; i++)
            newarr1[i+1] = arr1[i];
        newarr1[n+1] = Integer.MAX_VALUE;
        newarr1[0] = Integer.MIN_VALUE;
        arr1 = newarr1;
        
		//perform dp based on LIS
        int[] dp = new int[n+2];
        Arrays.fill(dp, Integer.MAX_VALUE);
        //dp[i] -> answer to change array 0 to i
        dp[0] = 0;
        for (int i = 1; i < n+2; i++){
            for (int j = 0; j < i; j++){
                if (arr1[j] < arr1[i] && dp[j] != Integer.MAX_VALUE){
                    int change = check(arr1, arr2, j, i);
                    if (change >= 0){
                        dp[i] = Math.min(dp[i], dp[j] + change);
                    }
                }
            }
        }
        return dp[n+1] == Integer.MAX_VALUE? -1:dp[n+1];
    }
    
    //change number from start+1 to end-1
    private int check(int[] arr1, int[] arr2, int start, int end){
        if (start+1 == end)
            return 0;
        int min = arr1[start];
        int max = arr1[end];
        int idx = Arrays.binarySearch(arr2, min);
        if (idx < 0)
            idx = -idx-1;
        else
            idx = idx+1;
        
        int maxcount = end-start-1;
        int endi = idx + maxcount-1;
        if (endi < arr2.length && arr2[endi] < max)
            return maxcount;
        else
            return -1;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
