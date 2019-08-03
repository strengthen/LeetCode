__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isBoomerang(int[][] p) {
        return (p[0][0] - p[1][0]) * (p[0][1] - p[2][1]) != (p[0][0] - p[2][0]) * (p[0][1] - p[1][1]);
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public boolean isBoomerang(int[][] points) {
        // check if any point is repeated
        HashSet<String> seenPoints = new HashSet<>();
        for (int[] point : points) {            
            String key = point[0] + "," + point[1];
            if (seenPoints.contains(key)) {
                return false;
            }
            seenPoints.add(key);      
        }                                        
        double x1x2 = slope(points[0], points[1]);        
        double x1x3 = slope(points[0], points[2]);        
        return (x1x2 != x1x3);
    }
    
    public double slope(int[] a, int[] b) {
        
        if (b[0] - a[0] == 0) {
            return Double.MIN_VALUE;
        }
        
        double m = (1.0 * (b[1] - a[1])) / (b[0] - a[0]); 
        return m;        
    }
    
}
__________________________________________________________________________________________________
