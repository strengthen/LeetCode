__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
 
   
   long M= (long)1e9+7;
    public int rectangleArea(int[][] rectangles) {
        long res= 0;
        for (int[] r: rectangles) res+=areaOf(r[0], r[1], r[2], r[3]);
        for (int i=0; i<rectangles.length; i++){
            long overlap= overlap(rectangles, rectangles[i], i+1);
            res=(res-overlap+M)%M;
        }
        return (int)res;
    }
    public long areaOf(int x1, int y1, int x2, int y2){
        return (long)(x2-x1)*(y2-y1);
    }
    public long overlap(int[][] recs, int[] a, int idx){
        if (idx==recs.length) return 0;
        int[] b= recs[idx++];
        int left= Math.max(a[0], b[0]), right= Math.min(a[2], b[2]), down= Math.max(a[1], b[1]), up= Math.min(a[3], b[3]);
        if (left>=right || up<=down) return overlap(recs, a, idx);
        long res=areaOf(left, down, right, up);
        if (a[0]<b[0]) res=(res+overlap(recs, new int[]{a[0], a[1], b[0], a[3]}, idx))%M;
        if (b[2]<a[2]) res=(res+overlap(recs, new int[]{b[2], a[1], a[2], a[3]}, idx))%M;
        if (a[1]<b[1]) res=(res+overlap(recs, new int[]{left, a[1], right, b[1]}, idx))%M;
        if (b[3]<a[3]) res=(res+overlap(recs, new int[]{left, b[3], right, a[3]}, idx))%M;
        return res;
    }
}
__________________________________________________________________________________________________
sample 34824 kb submission
class Solution {
    class Point {
        int x, y, val;
        Point(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }
    public int rectangleArea(int[][] rectangles) {
        int M = 1000000007;
        List<Point> data = new ArrayList<>();
        for (int[] r : rectangles) {
            data.add(new Point(r[0], r[1], 1));
            data.add(new Point(r[0], r[3], -1));
            data.add(new Point(r[2], r[1], -1));
            data.add(new Point(r[2], r[3], 1));
        }
        Collections.sort(data, (a, b) -> {
            if (a.x == b.x) {
                return b.y - a.y;
            }
            return a.x - b.x;
        });
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int preX = -1;
        int preY = -1;
        int result = 0;
        for (int i = 0; i < data.size(); i++) {
            Point p = data.get(i);
            map.put(p.y, map.getOrDefault(p.y, 0) + p.val);
            if (i == data.size() - 1 || data.get(i + 1).x > p.x) {
                if (preX > -1) {
                    result += ((long)preY * (p.x - preX)) % M;
                    result %= M;
                }
                preY = calcY(map);
                preX = p.x;
            }
        }
        return result;
    }
    private int calcY(TreeMap<Integer, Integer> map) {
        int result = 0, pre = -1, count = 0;
        for (Map.Entry<Integer, Integer> e : map.entrySet()) {
            if (pre >= 0 && count > 0) {
                result += e.getKey() - pre;
            }
            count += e.getValue();
            pre = e.getKey();
        }
        return result;
    }
}
__________________________________________________________________________________________________
