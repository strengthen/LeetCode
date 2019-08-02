__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int [] result = new int[quiet.length];
        for (int i = 0; i < result.length; i++)
            result[i] = i;
        while (true) {
            boolean changed = false;
            for (int[] r : richer) {
                if (quiet[result[r[0]]] < quiet[result[r[1]]]) {
                    result[r[1]] = result[r[0]];
                    changed = true;
                }
            }
            if (!changed) break;
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 47516 kb submission
class Solution {
public class Nd{
	int quiet;
	int ind;
	Nd qtest;
	ArrayList<Integer> richer = new ArrayList<>();
	ArrayList<Integer> poorer = new ArrayList<>();

	public Nd(int ind, int quiet){
		this.ind = ind;
		this.quiet = quiet;
	}
}

HashMap<Integer,Nd> ndMap = new HashMap<>();
    
public int[] loudAndRich(int[][] richer, int[] quiet) {
    
      for(int i = 0; i < quiet.length; i++){
          ndMap.putIfAbsent(i,new Nd(i,quiet[i]));
      }
    
      for(int[] r : richer){
           int p1 = r[0];
           int p2 = r[1];
      	   Nd n1 = ndMap.containsKey(p1) ? ndMap.get(p1) : new Nd(p1,quiet[p1]);
      	   Nd n2 = ndMap.containsKey(p2) ? ndMap.get(p2) : new Nd(p2,quiet[p2]);

      	   n1.poorer.add(p2);
      	   n2.richer.add(p1);

      	   ndMap.putIfAbsent(p1,n1);
      	   ndMap.putIfAbsent(p2,n2);
      }

      int[] answer = new int[quiet.length];

      for(int i = 0; i < answer.length; i++){
      	  answer[i] = dive(ndMap.get(i)).qtest.ind;
      }

      return answer;
}

public Nd dive(Nd nd){
	
	if(nd.richer.isEmpty()){
		nd.qtest = nd;
		return nd;
	}
    
    if(nd.qtest != null) return nd.qtest;

	Nd best = null;
	for(int uid : nd.richer){
        Nd rich = ndMap.get(uid);
		Nd ret = dive(rich);
		if(best == null) best = ret;
		else{
			if(ret.quiet < best.quiet) best = ret;
		}
	}

    if(nd.quiet < best.quiet) best = nd;
	nd.qtest = best;

	return best;
  }
}
__________________________________________________________________________________________________
