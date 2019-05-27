__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int maxPoints(int[][] points) {
        if (points.length < 3) return points.length;
        else if (points.length == 3 && isCollinear(points[0], points[1], points[2])) return 3;
        int max = 0, count;
        int[] first, second;
        boolean isOverlap, isCollinear;
        for (int i = points.length - 1; i > 0 ; i-=2) {
            count = 2;
            first = points[i];
            second = points[i-1];
            isOverlap = isOverlap(first, second);
            for (int j = 0; j < points.length; j++) {
                isCollinear = isOverlap ? isOverlap(first, points[j]) : isCollinear(first, second, points[j]);
                if (isCollinear) {
                    count++;
                }
            }
            max = Math.max(max, count);
        }
        return max;
    }

    // (y2 - y1) / (x2 - x1) == (y3 - y1) / (x3 - x1)
    public boolean isCollinear(int[] first, int[] second, int[] third) {
        if (first == third || second == third) return false;
        long left = (long)(second[1] - first[1]) * (third[0] - first[0]);
        long right = (int)(third[1] - first[1]) * (second[0] - first[0]);
        return  left == right;
    }
    
    public boolean isOverlap(int[] x, int[] y) {
        return Arrays.equals(x, y);
    }
}
__________________________________________________________________________________________________
sample 33072 kb submission
/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
class Solution {
    public int maxPoints(Point[] points) {
        int n = points.length;
        if (n < 3) {
            return n;
        }

        int result = 2;

        long x1, y1, x2, y2, x3, y3;
        for (int i = 1; i < n; i++) {
            x1 = points[i].x;
            y1 = points[i].y;
            x2 = points[i - 1].x;
            y2 = points[i - 1].y;

            int count = 0;
            if (x1 == x2 && y1 == y2) {
                for (Point p : points) {
                    if (x1 == p.x && y1 == p.y) {
                        count++;
                    }
                }
            } else {
                for (Point p : points) {
                    x3 = p.x;
                    y3 = p.y;
                    if (x1*y3+x2*y1+x3*y2==x1*y2+x2*y3+x3*y1) {
                        count++;
                    }
                }
            }
            result = Math.max(result, count);
        }

        return result;
    }
}
__________________________________________________________________________________________________
