__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n;
        while(l < r){
            int mid = l + ((r - l) >> 1);
            if(count(m, n, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
        /*
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0] * a[1] - b[0] * b[1];
            }
        });
        for(int i = 1; i <= m; i++){
            pq.add(new int[]{i, 1});
        }
        for(int i = 0; i < Math.min(k - 1, m * n); i++){
            int[] curr = pq.poll();
            if(curr[1] < n)
                pq.add(new int[]{curr[0], curr[1] + 1});
        }
        return pq.peek()[0] * pq.peek()[1];
        */
    }
    private int count(int m, int n, int target){
        int counter = 0;
        /*
        for(int i = 1; i <= m > 0; i++){
            counter += Math.min(target / i, n);
        }
        */
        for(int i = 1, j = n; i <= m; i++){
            while(j >= 1 && i * j > target) j--;
            counter += j;
        }
        return counter;
    }
}
__________________________________________________________________________________________________
sample 31688 kb submission
class Solution {
    
    private int result;
    
    public int findKthNumber(int m, int n, int k) {
        if (m < n) {
            int t = m;
            m = n;
            n = t;
        }
        
        int a = 1;
        int b = m * n + 1;
        while (a <= b) {
            int sum = 0;
            int med = (a + b) / 2;
            result = 0;
            for (int i = 1; i <= n; i++) {
                int t = countLessThanOrEqual(med, i, m);
                sum += t;
                if (t == 0)
                    break;
            }
            
            if (sum == k || a == b)
                break;
            if (sum > k) {
                b = med;
            } else {
                a = med + 1;
            }
        }
        
        return result;
    }
    
    private int countLessThanOrEqual(int boundary, int a, int m) {
        int k = boundary / a;
        if (k > m)
            k = m;
        int t = a * k;
        if (t > result)
            result = t;
        return k;
    }
}
__________________________________________________________________________________________________
