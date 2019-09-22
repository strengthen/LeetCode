__________________________________________________________________________________________________
class Solution {
	    public int smallestCommonElement(int[][] mat) {
	        int n = mat.length;
	        int[] ps = new int[n];
	        int m = mat[0].length;
	        outer:
	        for(int i = 0;i < m;i++){
	        	for(int j = 1;j < n;j++){
	        		while(ps[j] < m && mat[j][ps[j]] < mat[0][i])ps[j]++;
	        		if(ps[j] < m && mat[j][ps[j]] == mat[0][i]){
	        		}else{
	        			continue outer;
	        		}
	        	}
	        	return mat[0][i];
	        }
	        return -1;
	    }
	}	

__________________________________________________________________________________________________

__________________________________________________________________________________________________
