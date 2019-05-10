__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    int n;
    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        backtrack(new ArrayList<Integer>(), 1, k);
        return ans;
    }
    
    public void backtrack(ArrayList<Integer> curr , int first  , int k ){
        if (k==0){
            ans.add(new ArrayList<Integer>(curr));
            return;
        }
        for(int i=first;i<=n-k+1;i++){
            curr.add(i);
            backtrack(curr,i+1,k-1);
            curr.remove(curr.size()-1);
        }
    }
}
__________________________________________________________________________________________________
sample 39800 kb submission
class Solution {
    private void p(int begin, int n, int k, List<Integer>l, List<List<Integer>>ls) {
		if (n - begin + 1 + l.size() < k) return;
		if (l.size() == k) {
			ls.add(l);
			return;
		}
		for (int i = begin; i <= n; i++) {
            if (n - i + 1 + l.size() < k) break;
			List<Integer>ll = new ArrayList<Integer>(l);
			ll.add(i);
			p(i+1, n, k, ll, ls);
		}
	}
	
	public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ls = new ArrayList<List<Integer>>();
        for (int i = 1; i <= n; i++) {
        	List<Integer> l = new ArrayList<Integer>();
        	l.add(i);
        	p(i+1, n, k, l, ls);
        }
        return ls;
    }
}
__________________________________________________________________________________________________
