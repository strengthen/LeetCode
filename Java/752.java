__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    
    private boolean[] v1 = new boolean[10000];
  private boolean[] v2 = new boolean[10000];
  private Queue<Integer> q1 = new LinkedList<>();
  private Queue<Integer> q2 = new LinkedList<>();
  
  private void swap() {
    boolean[] vtmp = v1;
    v1 = v2;
    v2 = vtmp;
    Queue<Integer> qtmp = q1;
    q1 = q2;
    q2 = qtmp;
  }
  
  private boolean next(int val) {
    int base = 1000;
    while (base > 0) {
      int d0 = val / base % 10;
      for (int delta=-1; delta<=1; delta+=2) {
        int d1 = (d0 + delta + 10) % 10;
        int nx = val + (d1 - d0) * base;
        // Note to check v1[nx] before v2[nx] so we won't take
        // deadends as end.
        if (v1[nx]) continue;
        if (v2[nx]) return true;
        v1[nx] = true;
        q1.offer(nx);
      }
      base /= 10;
    }
    return false;
  }
  
  public int openLock(String[] deadends, String target) {
    int t = Integer.parseInt(target);
    for (String s : deadends) {
      int i = Integer.parseInt(s);
      v1[i] = v2[i] = true;
      if (i == 0 || i == t) return -1;
    }
    v1[0] = true;
    v2[t] = true;
    q1.offer(0);
    q2.offer(t);
    for (int ans=1; !q1.isEmpty(); ++ans) {
      for (int i=q1.size(); i>0; --i) {
        if (next(q1.poll())) return ans;
      }
      if (q1.size() > q2.size()) swap();
    }
    
    return -1;
  }
}
__________________________________________________________________________________________________
sample 37704 kb submission
class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> deadSet = new HashSet<String>(Arrays.asList(deadends));
    	Set<String> qs = new HashSet<String>();
    	Set<String> qt = new HashSet<String>();
    	
    	if (deadSet.add("0000")) {
    		qs.add("0000");
    	}
    	if (deadSet.add(target)) {
    		qt.add(target);
    	}
    	int step = 0;
    	while (!qs.isEmpty() && !qt.isEmpty()) {
    		Set<String> tmp = new HashSet<String>();
    		for (String cur : qs) {
    			char[] cs = cur.toCharArray();
                for (int i = 0; i < 4; i++) {
                    char tc = cs[i];
                    
                    cs[i] = (char)((tc-'0'+1)%10+'0');
                    String next = new String(cs);
                    if (qt.contains(next))
                        return step+1;
                    if (deadSet.add(next))
                        tmp.add(next);
                    
                    cs[i] = (char)((tc-'0'+9)%10+'0');
                    next = new String(cs);
                    if (qt.contains(next))
                        return step+1;
                    if (deadSet.add(next))
                        tmp.add(next);
                    
                    cs[i] = tc;
                }
            }
            qs = qt;
            qt = tmp;
            step++;
        }
        return -1;       
    }
}
__________________________________________________________________________________________________
