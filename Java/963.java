__________________________________________________________________________________________________
sample 6 ms submission
class Solution {
    public double minAreaFreeRect(int[][] points) {
        Set<Integer> set = new HashSet<>();
        for(int[] point : points) {
            set.add(point[0] * 40001 + point[1]);
        }
        double result = Double.MAX_VALUE;
        for(int n = points.length, i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    result = helper(result, points, i, j, k, set);
                    //result = helper(result, points, j, i, k, set);
                    //result = helper(result, points, k, i, j, set);
                }
            }
        }
        return result == Double.MAX_VALUE ? 0. : Math.sqrt(result);
    }

    static double helper(double result, int[][] points, int i, int j, int k, Set<Integer> set) {
        int[] a = points[i];
        int[] b = points[j];
        int[] c = points[k];
        int ab = distance(a[0], a[1], b[0], b[1]);
        int ac = distance(a[0], a[1], c[0], c[1]);
        int bc = distance(b[0], b[1], c[0], c[1]);
        if (ab + ac == bc) {
            int dx = b[0] + c[0] - a[0];
            int dy = b[1] + c[1] - a[1];
            if (set.contains(dx * 40001 + dy)) {
                result = Math.min(result, 1. * ab * ac);
            }
        }
        return result;
    }
    //
    public double minAreaFreeRect2(int[][] points) {
        Map<Long, List<int[]>> map = new HashMap<>();
        for(int n = points.length, i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) { // no duplicates.
                int[] a = points[i];
                int[] b = points[j];
                int x = a[0] + b[0]; // 2 * center x.
                int y = a[1] + b[1]; // 2 * center y.
                int z = distance(a[0], a[1], b[0], b[1]); // square distance.
                long index = 80001 * x + y;
                index <<= 32;
                index += z;
                List<int[]> list = map.get(index);
                if (list == null) {
                    list = new ArrayList<>();
                    map.put(index, list);
                }
                list.add(new int[] {a[0], a[1], b[0], b[1]});
            }
        }
        double result = Double.MAX_VALUE;
        for(Map.Entry<Long, List<int[]>> entry : map.entrySet()) {
            List<int[]> list = entry.getValue();
            for(int n = list.size(), i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) { // no duplicates.
                    int[] a = list.get(i);
                    int[] b = list.get(j);
                    result = Math.min(result,
                                      ((double) distance(a[0], a[1], b[0], b[1]))
                                      * distance(a[0], a[1], b[2], b[3]));
                }
            }
        }
        return result == Double.MAX_VALUE ? 0. : Math.sqrt(result);
    }

    static int distance(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
}
__________________________________________________________________________________________________
sample 35324 kb submission
import java.awt.Point;

class Solution {
    public double minAreaFreeRect(int[][] points) {
        int N = points.length;
        Point[] A = new Point[N];
        for (int i = 0; i < N; ++i) {
            A[i] = new Point(points[i][0], points[i][1]);
        }
        Map<Integer, Map<Point, List<Point>>> seen = new HashMap<>();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                Point center = new Point(A[i].x + A[j].x, A[i].y + A[j].y);
                int radius = (A[i].x - A[j].x) * (A[i].x - A[j].x);
                radius += (A[i].y - A[j].y) * (A[i].y - A[j].y);
                seen.computeIfAbsent(radius, r -> new HashMap<>()).computeIfAbsent(center, c -> new ArrayList<>()).add(A[i]);
            }
        }
        
        double minArea = Double.MAX_VALUE;
        for (Map<Point, List<Point>> groups : seen.values()) {
            for (Point center : groups.keySet()) {
                List<Point> candidates = groups.get(center);
                for (int i = 0; i < candidates.size(); ++i) {
                    for (int j = i+1; j < candidates.size(); ++j) {
                        Point P = candidates.get(i);
                        Point Q = candidates.get(j);
                        Point Q2 = new Point(center);
                        Q2.translate(-Q.x, -Q.y);
                        double area = P.distance(Q) * P.distance(Q2);
                        if (area < minArea)
                            minArea = area;
                    }
                }      
            } 
        }
        return minArea < Double.MAX_VALUE ? minArea : 0;
    }
}
__________________________________________________________________________________________________
