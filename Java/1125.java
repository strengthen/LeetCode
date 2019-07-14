__________________________________________________________________________________________________
class Solution {
    public int[] smallestSufficientTeam(String[] sk, List<List<String>> p) {
        int id = 0;
        Map<String,Integer> mp = new HashMap<>();
        for(String s:sk){
            mp.put(s,id++);
        }
        int v[] =new int[1<<id];
        Arrays.fill(v,Integer.MAX_VALUE/2);
        v[0] = 0;
        List nm[] =new List[1<<id];
        for(int st = (1<<id)-1;st>=0;--st){
            nm[st] = new ArrayList();
        }

        int pp = 0;
    
        int g = Integer.MAX_VALUE;
    int gst = -1;
        for(List<String> c:p){
            
            for(int st = (1<<id)-1;st>=0;--st){
                int cur = 0;
                for(String nn:c){
                    if(mp.containsKey(nn)){
                        int cc = mp.get(nn);
                        cur |= 1<<cc;
                    }
                }
                int nst = st|cur;
                
                if(v[st]+1<v[nst]){
                    v[nst] = v[st]+1;
                    nm[nst] = new ArrayList();
                    
                    
                    for(Object xx:nm[st]){
                        nm[nst].add(xx);
                    }
                    nm[nst].add(pp);
                    
                    
                }
            
            }
            ++pp;
        }
    
        int sz =nm[(1<<id)-1].size();
    
            int a[] =new int[sz];
    
    for(int i=0;i<sz;++i){
        a[i] = (int)nm[(1<<id)-1].get(i);
    }
    return a;       
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
