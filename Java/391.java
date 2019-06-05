__________________________________________________________________________________________________
sample 19 ms submission
class Solution {
    private static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return 31 * 31 * x + y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Point) {
                Point p = (Point) obj;

                return this.x == p.x && this.y == p.y;
            }

            return false;
        }
    }

    // This is from the best submission!
    /*
    1. The areas should be the same
    2. Apart from the 4 points of the final rectangle, every point is overlapped by 2 and only 2 rectangles!
    */
    public boolean isRectangleCover(int[][] rectangles) {
        if (rectangles.length == 0) {
            return true;
        }

        // At first, get the bottomLeft and upperRight of the final rectangle.
        Point bottomLeft = new Point(rectangles[0][0], rectangles[0][1]);
        Point upperRight = new Point(rectangles[0][2], rectangles[0][3]);

        Set<Point> points = new HashSet<>();
        int area = 0;

        for (int[] rect : rectangles) {

            if (rect[0] <= bottomLeft.x && rect[1] <= bottomLeft.y) {
                bottomLeft = new Point(rect[0], rect[1]);
            }

            if (rect[2] >= upperRight.x && rect[3] >= upperRight.y) {
                upperRight = new Point(rect[2], rect[3]);
            }

            area += getArea(rect);

            for (Point point : new Point[]{
                    new Point(rect[0], rect[1]),
                    new Point(rect[0], rect[3]),
                    new Point(rect[2], rect[1]),
                    new Point(rect[2], rect[3])}) {
                if(!points.add(point)) {
                    points.remove(point);
                }
            }
        }

        if(area != getArea(new int[] {bottomLeft.x, bottomLeft.y, upperRight.x, upperRight.y})) {
            return false;
        }

        return points.size() == 4
                && points.contains(bottomLeft)
                && points.contains(upperRight)
                && points.contains(new Point(bottomLeft.x, upperRight.y))
                && points.contains(new Point(upperRight.x, bottomLeft.y));
    }

    //89 ms, faster than 15.44%
    public boolean isRectangleCoverByBuildingOneByOne(int[][] rectangles) {
        if (rectangles.length == 0) {
            return true; //??
        }

        // At first, get the bottomLeft and upperRight of the final rectangle.
        int[] bottomLeft = new int[]{rectangles[0][0], rectangles[0][1]};
        int[] upperRight = new int[]{rectangles[0][2], rectangles[0][3]};

        int area = getArea(rectangles[0]);

        for (int i = 1; i < rectangles.length; i++) {
            if (rectangles[i][0] <= bottomLeft[0] && rectangles[i][1] <= bottomLeft[1]) {
                bottomLeft = new int[]{rectangles[i][0], rectangles[i][1]};
            }

            if (rectangles[i][2] >= upperRight[0] && rectangles[i][3] >= upperRight[1]) {
                upperRight = new int[]{rectangles[i][2], rectangles[i][3]};
            }

            area += getArea(rectangles[i]);
        }

        // All area should be the same with the final rectangle candidate.
        if (area != getArea(new int[]{bottomLeft[0], bottomLeft[1], upperRight[0], upperRight[1]})) {
            return false;
        }

        // Now let's get the final rectangle one by one from left to right, down to up
        Arrays.sort(rectangles, (a, b) -> a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]);

        int[] heights = new int[upperRight[0] - bottomLeft[0] + 1];

        for (int[] rect : rectangles) {
            // Pay attention that x should not be equal to rect[2]
            for (int x = rect[0]; x < rect[2]; x++) {
                if (heights[x - bottomLeft[0]] != rect[1] - bottomLeft[1]) {
                    return false;
                }

                heights[x - bottomLeft[0]] += rect[3] - rect[1];
            }
        }

        return true;
    }

    private int getArea(int[] rect) {
        return (rect[2] - rect[0]) * (rect[3] - rect[1]);
    }
}
__________________________________________________________________________________________________
sample 41848 kb submission
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {

        Arrays.sort(rectangles, (a, b)->{
            if(a[1] != b[1]) return a[1]-b[1];
            else{
                return a[0]-b[0];
            }
        });

        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE;
        int maxY = Integer.MIN_VALUE;
        
        for(int i = 0; i < rectangles.length; i++){
            int[] rect = rectangles[i];
            minX = Math.min(rect[0], minX);
            minY = Math.min(rect[1], minY);
            maxX = Math.max(rect[2], maxX);
            maxY = Math.max(rect[3], maxY);
        }

        int [] l = new int[maxX-minX];
        Arrays.fill(l, minY);
        
        for(int i = 0; i < rectangles.length; i++){
            int[] rect = rectangles[i];
            if(rect[2] > maxX) return false;
            if(rect[0] < minX) return false;
            for(int j = rect[0]; j < rect[2]; j++){
                if(l[j-minX] != rect[1]) return false;
                l[j-minX] = rect[3];
            }
        }

        for(int i : l) if(i != maxY) return false;
        return true;
    }
}
__________________________________________________________________________________________________
