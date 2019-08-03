__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        quickSort(points, 0, points.length-1, K);
        return Arrays.copyOf(points, K);
    }
    
    private void quickSort(int[][] points, int l, int r, int k) {
        int[] pivot = points[l];
        int i = l;
        int j = r;
        while (i <= j){
            while (i <= j && compare(points[i], pivot) < 0){
                i++;
            }
            while (i <= j && compare(points[j], pivot) > 0){
                j--;
            }
            if (i <= j){
                int[] temp = points[i];
                points[i] = points[j];
                points[j] = temp;
                i++;
                j--;
            }
                       
        }
        // The k-th element is in the first part.
        if(j-l+1 >= k) {
            quickSort(points, l, j, k);
        }
        // The k-th element is in the second part.
        if((i-1)-l+1 < k) {
            quickSort(points, i, r, k-(i-l));
        }
    }
    private int compare (int[] p1, int[] p2){
        return p1[0]*p1[0] + p1[1]*p1[1] - p2[0]*p2[0] - p2[1]*p2[1];
    }
}
__________________________________________________________________________________________________
sample 43264 kb submission
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        int[][] res = new int[K][2];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->(a[0]*a[0]+a[1]*a[1]-b[0]*b[0]-b[1]*b[1]));
        
        for(int[] e : points){
            pq.add(e);
        }
        int index = 0;
        while(K>0){
            int[] pp = pq.poll();
            res[index][0] = pp[0];
            res[index++][1] = pp[1];
            K--;
        }
        return res;
    }
}
__________________________________________________________________________________________________
