__________________________________________________________________________________________________
class Solution {
	    public String removeDuplicates(String s, int k) {
	    	int n = s.length();
	        char[] cs = new char[n];
	        int[] cts = new int[n];
	        int p = 0;
	        for(char c : s.toCharArray()){
	        	if(p > 0 && cs[p-1] == c){
	        		if(++cts[p-1] == k){
	        			p--;
	        		}
	        	}else{
	        		cs[p] = c;
	        		cts[p] = 1;
	        		p++;
	        	}
	        }
	        StringBuilder sb = new StringBuilder();
	        for(int i = 0;i < p;i++){
	        	for(int j = 0;j < cts[i];j++){
	        		sb.append(cs[i]);
	        	}
	        }
	        return sb.toString();
	    }
	}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
