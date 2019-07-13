__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    private int mergeSort(int[][] arr, int[][] comp, int begin, int end) {
        if (begin == end) {
            return 1;
        }
        int mid = (begin + end) / 2;
        int len1 = mergeSort(comp, arr, begin, mid);
        int len2 = mergeSort(comp, arr, mid + 1, end);
        int i = begin;
        int j = mid + 1;
        int k = begin;
        while (i < begin + len1 || j < mid + 1 + len2) {
            if (i >= begin + len1) {
                comp[k++] = arr[j++];
            } else if (j >= mid + 1 + len2) {
                comp[k++] = arr[i++];
            } else if (arr[i][0] < arr[j][0]) {
                if (arr[i][1] < arr[j][1]) {
                    comp[k++] = arr[i++];
                } else {
                    i++;
                }
            } else if (arr[i][0] == arr[j][0]) {
                if (arr[i][1] <= arr[j][1]) {
                    j++;
                } else {
                    i++;
                }
            } else {
                if (arr[i][1] <= arr[j][1]) {
                    j++;
                } else {
                    comp[k++] = arr[j++];
                }
            }
        }
        return k - begin;
    }

    public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0) {
            return 0;
        }
        int[][] comp = new int[points.length][];
        int i;
        for (i = 0; i < points.length; i++) {
            comp[i] = points[i];
        }
        int len = mergeSort(comp, points, 0, points.length - 1);
        int arrows = 1;
        int lastArrow = points[0][1];
        for (i = 1; i < len; i++) {
            if (points[i][0] <= lastArrow) {
                continue;
            } else {
                arrows++;
                lastArrow = points[i][1];
            }
        }
        return arrows;
    }
}
__________________________________________________________________________________________________
sample 39736 kb submission
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length ==0) return 0;
        Arrays.sort(points, (x, y) -> x[0] == y[0] ? x[1] - y[1] : x[0] - y[0]);
        int ans = 1, lastArrow = points[0][1];
        for(int i=1; i<points.length; i++){
            if(points[i][0] > lastArrow){
                lastArrow = points[i][1];
                ans++;
            } else{
                lastArrow = Math.min(lastArrow, points[i][1]);
            }
        }
        return ans;

    }
}
__________________________________________________________________________________________________
