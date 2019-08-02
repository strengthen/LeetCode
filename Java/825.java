__________________________________________________________________________________________________
sample 1 ms submission
class Solution {    
    public int numFriendRequests(int[] ages) {
        if (ages == null || ages.length == 0) {
            return 0;
        }
        
        int[] ageBuckets = new int[121];
        int[] runningSum = new int[121];
        int numRequests = 0;
        
        for (int age : ages) {
            ageBuckets[age]++;
        }
        
        for (int i = 1; i < ageBuckets.length; i++) {
            runningSum[i] = runningSum[i - 1] + ageBuckets[i];
        }
        
        for (int ageA = 15; ageA < ageBuckets.length; ageA++) {
            if (ageBuckets[ageA] > 0) {
                numRequests += ageBuckets[ageA] * 
                    (runningSum[ageA] - runningSum[ageA / 2 + 7]) - ageBuckets[ageA];
            }
        }
        
        return numRequests;
    }
}
__________________________________________________________________________________________________
sample 39744 kb submission
class Solution {
    public int numFriendRequests(int[] ages) {
        int[] counts = new int[121];
        for (int age:ages) counts[age]++;
        int ans = 0;
        for (int i=1;i<=120; i++) {
            if (counts[i]==0) continue;
            for (int j=(int) Math.floor(i*0.5+7)+1; j<i; j++) ans += counts[j]*counts[i];
            if (i>14) ans += counts[i]*(counts[i]-1);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
