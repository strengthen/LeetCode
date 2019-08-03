__________________________________________________________________________________________________
sample 66 ms submission
class Solution {
    private final int[][] filters = new int[][] {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
    private Map<Integer, Integer> hMap;
    private Map<Integer, Integer> vMap;
    private Map<Integer, Integer> pdMap;
    private Map<Integer, Integer> ndMap;
    private Set<Integer> lampIdx;
    public Solution() {
        hMap = new HashMap();
        vMap = new HashMap();
        pdMap = new HashMap();
        ndMap = new HashMap();
        lampIdx = new HashSet();
    }
    
    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        for (int i = 0; i < lamps.length; i++) {
            lampIdx.add(i);
            turnOn(lamps[i][0], lamps[i][1]);
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length ; i++ ) {
            int x = queries[i][0];
            int y = queries[i][1];
            result[i] = isOn(x, y) ? 1 : 0;
            if (result[i] == 1) query(lamps, x, y);
        }
        return result;        
    }

    private void turnOn(int x, int y) {
        inc(hMap, x);
        inc(vMap, y);
        inc(pdMap, x + y);
        inc(ndMap, y - x);
    }
    private void query(int[][] lamps, int x, int y) {
        List<Integer> listToRemove = new ArrayList();
        for (Integer i : lampIdx) {
            int[] lamp = lamps[i];
            for (int[] filter : filters) {
                if (lamp[0] == (x + filter[0]) && lamp[1] == (y + filter[1])) {
                    dec(hMap, lamp[0]);
                    dec(vMap, lamp[1]);
                    dec(pdMap, lamp[0] + lamp[1]);
                    dec(ndMap, lamp[1] + lamp[0]);
                    listToRemove.add(i);
                }
            }
        }
        for (Integer i : listToRemove) {
            lampIdx.remove(i);
        }
    }
    private void inc(Map<Integer, Integer> map, int key) {
        map.put(key, 1 + map.getOrDefault(key, 0));
    }
    private void dec(Map<Integer, Integer> map, int key) {
        if (map.containsKey(key)) {
            map.put(key, map.get(key) - 1);
            if (map.get(key) == 0) {
                map.remove(key);
            }
        }
    }
    private boolean isOn(int x, int y) {
         return hMap.getOrDefault(x, 0) > 0 || 
             vMap.getOrDefault(y, 0) > 0 || 
             pdMap.getOrDefault(x + y, 0) > 0 || 
             ndMap.getOrDefault(y - x, 0) > 0;        
    }
}
__________________________________________________________________________________________________
sample 59796 kb submission
class Solution {
    private Map<Integer, Integer> horizon = new HashMap<>();
    private Map<Integer, Integer> vertical = new HashMap<>();
    private Map<Integer, Integer> l_oblique = new HashMap<>();
    private Map<Integer, Integer> r_oblique = new HashMap<>();
    
    private Set<Light> lights = new HashSet<>();
    
    private static int n;
    
    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        n = N;
        for (int i = 0; i < lamps.length; ++i) {
            int x = lamps[i][0];
            int y = lamps[i][1];
            lights.add(new Light(x, y));
            horizon.put(x, horizon.getOrDefault(x, 0) + 1);
            vertical.put(y, vertical.getOrDefault(y, 0) + 1);
            l_oblique.put(x+y, l_oblique.getOrDefault(x+y, 0) + 1);
            r_oblique.put(x-y, r_oblique.getOrDefault(x-y, 0) + 1);
        }
        
        int[] ans = new int[queries.length];
        
        for (int i = 0; i < queries.length; ++i) {
            int x = queries[i][0];
            int y = queries[i][1];
            
            if (horizon.getOrDefault(x, 0) > 0 || vertical.getOrDefault(y, 0) > 0 
                || l_oblique.getOrDefault(x+y, 0) > 0 || r_oblique.getOrDefault(x-y,0) > 0) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
            
            int[] dx = new int[]{-1, 0, 1};
            int[] dy = new int[]{-1, 0, 1};
            
            for (int xStep: dx) {
                for (int yStep : dy) {
                    int nx = x + xStep;
                    int ny = y + yStep;
                    Light l = new Light(nx, ny);
                    // 这里写根据hashCode计算同时根据equals比较
                    if (lights.contains(l)) {
                        // System.out.println("debug");
                        lights.remove(l);
                        horizon.put(nx, horizon.get(nx) - 1);
                        vertical.put(ny, vertical.get(ny) - 1);
                        l_oblique.put(nx+ny, l_oblique.get(nx+ny) - 1);
                        r_oblique.put(nx-ny, r_oblique.get(nx-ny) - 1);
                    }
                }
            }
        }
        
        return ans;
    }
    
    private static class Light {
        int xIndex;
        int yIndex;
        
        Light(int x, int y) {
            this.xIndex = x;
            this.yIndex = y;
        }
    
        @Override
        public int hashCode() {
            return xIndex + yIndex * n;
        }
        
        @Override
	    public boolean equals(Object other) {
		    // System.out.println("equals method invoked!");
		
		    if(other == this)
			    return true;
		    if(!(other instanceof Light))
			    return false;
		
		    Light o = (Light)other;
		    return o.xIndex == xIndex && o.yIndex == yIndex;
        }
    }

}
__________________________________________________________________________________________________
