__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    //upper cse: >0 upper, <0, lower, vice versa
    public static int cross(int[]o, int[] a, int[]b){
        return (b[1]-o[1])*(a[0]-o[0]) - (a[1]-o[1])*(b[0]-o[0]);
    }

    public static int[][] outerTrees(int[][] points) {
        int n = points.length;
        int k=0;
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0]!=o2[0]){
                    return o1[0]-o2[0];
                }else{
                    return o1[1]-o2[1];
                }
            }
        });

        int[] h= new int[n*2];
        for(int i=0;i<2*n;i++){
            h[i] = -1;
        }
        for(int i=0;i<n;i++){
            while(k>=2 && cross(points[h[k-2]], points[h[k-1]], points[i])>0){
                k--;
            }
            h[k++] = i;
        }
        for(int i=n-2, t=k+1; i>=0; i--){
            while(k>=t && cross(points[h[k-2]], points[h[k-1]], points[i])>0){
                k--;
            }
            h[k++] = i;
        }
        HashSet<Integer> set = new HashSet<Integer>();
        for(int a=0;a<k;a++){
            int i = h[a];
            if(i>=0)
                set.add(i);
        int[][] res = new int[set.size()][2];

        int m =0 ;
        for(int i:set){
            res[m++] = points[i];
        }
        return res;

    }

}
__________________________________________________________________________________________________
sample 47564 kb submission
class Solution {
    class Point{
        int x;
		int y;
		Point() { x = 0; y = 0; }
		Point(int a, int b) { x = a; y = b; }

        public String toString() {
			return "[" + x + "," + y + "]";
		}	
    }
    public boolean above(Point l, Point r, Point u) {
			return (r.x - l.x) * (u.y - l.y) > (r.y - l.y) * (u.x - l.x); 
		}
    public boolean below(Point l, Point r, Point u) {
        return (r.x - l.x) * (u.y - l.y) < (r.y - l.y) * (u.x - l.x); 
    }
    public boolean collinear(Point l, Point r, Point u) {
        return (r.x - l.x) * (u.y - l.y) == (r.y - l.y) * (u.x - l.x); 
    }
    public int[][] outerTrees(int[][] points) {
        List<Point>lh = new ArrayList<>();
        List<Point>uh = new ArrayList<>();
        List<Point> P = Arrays.stream(points)
                .map(p -> new Point(p[0], p[1])).collect(Collectors.toList());
        Collections.sort(P, (a, b) -> ((a.x == b.x) ? (a.y - b.y) : a.x - b.x));
        Point l = P.get(0);
        Point r = P.get(P.size() - 1);
        lh.add(l);
        uh.add(l);
        for(int i = 1; i < P.size(); i++) {
            Point u = P.get(i);
            if(above(l, r, u) || collinear(l, r, u)) {
                if(uh.size() == 1) {
                    uh.add(u);
                    continue;
                }
                while(uh.size() > 1 && above(uh.get(uh.size() - 2)
                        , uh.get(uh.size() - 1), u))uh.remove(uh.size()-1);
                uh.add(u);
            }
            if(below(l, r, u) || collinear(l, r, u)) {
                if(lh.size() == 1) {
                    lh.add(u);
                    continue;
                }
                while(lh.size() > 1 && below(lh.get(lh.size() - 2)
                        , lh.get(lh.size() - 1), u))lh.remove(lh.size()-1);
                lh.add(u);
            }
            else {

            }
        }
        Set<Point> hull = new TreeSet<>((a, b) -> (a.x == b.x)? (a.y - b.y)
                : (a.x - b.x));
        hull.addAll(lh);
        hull.addAll(uh);
        return hull.stream().map(x -> new int[] {x.x, x.y}).toArray(s -> new int[s][]);
    }
}    
__________________________________________________________________________________________________
