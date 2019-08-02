__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public double largestTriangleArea(int[][] p) {
        double max = 0;
        int length = p.length;

        for (int i = 0 ; i < length ; ++i)
            for (int j = i+1 ; j < length ; ++j)
                for (int k = j+1 ; k < length ; ++k) {
                    double area = calcArea(p[i], p[j], p[k]);
                    if (area > max) max = area;
                }
        return max;
    }
    
    private double calcArea(int[] a, int[] b, int[] c) {
        return 0.5 * Math.abs(a[0]*b[1] - a[1]*b[0]
                             +b[0]*c[1] - b[1]*c[0]
                             +c[0]*a[1] - c[1]*a[0]);
    }
}
__________________________________________________________________________________________________
sample 35724 kb submission
class Solution {
    public double largestTriangleArea(int[][] points) {
        double max = Double.MIN_VALUE;
        int n = points.length;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    max = Math.max(max, Math.abs(area(points[i], points[j], points[k])));
                }
            }
        }
        return max;
    }

    public double area(int[] a, int[] b, int[] c) {
        double sum = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[0] * c[1] - c[0] * b[1] - b[0] * a[1];
        return sum / 2.0;
    }
}
__________________________________________________________________________________________________
