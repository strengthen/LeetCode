__________________________________________________________________________________________________
class Solution {
	    public int equalSubstring(String s, String t, int maxCost) {
	        int n = s.length();
	        int[] a = new int[n];
	        for(int i = 0;i < n;i++){
	        	a[i] = Math.abs(s.charAt(i) - t.charAt(i));
	        }
	        int maxlen = 0;
	        
	        int cost = 0;
	        int j = 0;
	        for(int i = 0;i < n;i++){
	        	cost += a[i];
	        	while(j <= i && cost > maxCost){
	        		cost -= a[j];
	        		j++;
	        	}
	        	maxlen = Math.max(maxlen, i-j+1);
	        }
	        return maxlen;
	    }
	}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
