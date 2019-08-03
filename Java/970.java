__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        List<Integer> ans = new ArrayList<>();
        
        recur(ans,1,1,x,y,bound);
        
        return ans;
    }
    
    public void recur(List<Integer> ans,int xp, int yp,int x,int y, int bound){
        int cur = xp+yp;
        
        if(cur > bound || ans.contains(cur))
            return;
        
        ans.add(cur);
        
        recur(ans,xp*x,yp,x,y,bound);
        recur(ans,xp,yp*y,x,y,bound);
    }    
}
__________________________________________________________________________________________________
sample 32436 kb submission
class Solution {
	public List<Integer> powerfulIntegers(int x, int y, int bound) {

		Set<Integer> set = new HashSet<>();

		for (int a = 1; a <= bound; a *= x) {

			for (int b = 1; a + b <= bound; b *= y) {

				set.add(a + b);

				if (y == 1) {
					break;
				}
			}

			if (x == 1) {
				break;
			}
		}

		return new ArrayList<>(set);
	}
}
__________________________________________________________________________________________________
