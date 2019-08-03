__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int cost = 0;
        int N = costs.length/2;
        quickSelect(costs, 0, costs.length-1, N);
        for(int i=0; i<costs.length; ++i) 
            cost += i < N ? costs[i][0] : costs[i][1];
        return cost;
    }
    
    private void quickSelect(int[][] costs, int start, int end, int N) {
        if(costs.length <= 1 || end < start)
            return;
        int i = start -1;
        int j = start -1;
        int pivot = end;
        while(j<pivot) {
            ++j;
            if(costs[j][0] - costs[j][1] <= costs[pivot][0] - costs[pivot][1]) {
                int[] temp = costs[j];
                costs[j] = costs[++i];
                costs[i] = temp;
            }
        }
        if(i == N) return;
        else if( i > N) quickSelect(costs, start, i-1, N);
	else quickSelect(costs, i+1, end, N);
    }
}
__________________________________________________________________________________________________
sample 34560 kb submission
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, 
                    (c1, c2)->(Math.abs(c1[0] - c1[1]) - 
                               Math.abs(c2[0] - c2[1])));
        
        for(int[] cost : costs) {
            System.out.println(cost[0]);
        }
        
        int toA = 0;
        int toB = 0;
        int sum = 0;
        int n = costs.length;
        for(int i = n - 1; i >= 0; i--) {
            
            if(i < n / 2) {
                if(costs[i][0] < costs[i][1] && (toA != n / 2)) {
                    if(toA != n/2) {
                        sum += costs[i][0];
                        toA++;
                    } else {
                        sum += costs[i][1];
                        toB++;
                    }
                } else {
                    if(toB != n/2) {
                        sum += costs[i][1];
                        toB++;
                    } else {
                        sum += costs[i][0];
                        toA++;
                    }
                }
            } else {
                if(costs[i][0] < costs[i][1]) {
                    toA++;
                    sum += costs[i][0];
                } else {
                    toB++;
                    sum += costs[i][1];
                }
            }
            System.out.println(sum);
        }
        
        return sum;
    }
}
__________________________________________________________________________________________________
