__________________________________________________________________________________________________
sample 42 ms submission
class Solution {
    public int numberOfBoomerangs(int[][] p) {
        
        int l = p.length;
        int c[] = new int[l<<1];
        int u = 0;
        for(int pr[] : p){
            c[u++] = pr[0];   
            c[u++] = pr[1];
        }
        
        int count = 0;
        Map<Integer,Integer> map = new HashMap<>(u<<1);
        for(int i=0;i<u;i+=2){
            for(int j=0,x = c[i],y = c[i+1];j<u;j+=2){
                int d = (x-c[j])*(x-c[j])+(y-c[j+1])*(y-c[j+1]);
                Integer v = map.get(d);
                if(v!=null){
                    map.put(d,v+1);
                    count+=v<<1;
                } else 
                    map.put(d,1);
            }
            map.clear();
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 38236 kb submission
class Solution {
    public int numberOfBoomerangs(int[][] p) {
        
        int l = p.length;
        int c[] = new int[l<<1];
        int u = 0;
        for(int pr[] : p){
            c[u++] = pr[0];   
            c[u++] = pr[1];
        }
        
        int count = 0;
        Map<Integer,Integer> map = new HashMap<>(u<<1);
        for(int i=0;i<u;i+=2){
            for(int j=0,x = c[i],y = c[i+1];j<u;j+=2){
                int d = (x-c[j])*(x-c[j])+(y-c[j+1])*(y-c[j+1]);
                Integer v = map.get(d);
                if(v!=null){
                    map.put(d,v+1);
                    count+=v<<1;
                } else 
                    map.put(d,1);
            }
            map.clear();
        }
        return count;
    }
}
__________________________________________________________________________________________________
