__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public  int minDeletionSize(String[] A) {
		if (A == null) {
			return 0;
		}
		int count =0 ;
		int len = A[0].length();
		
		for (int i = 0; i < len; i++) {
			if(isNoSort(A, i)) count++;
		}
		return count;
    }

	public static boolean isNoSort(String[] A, int num) {
		char c = A[0].charAt(num);
		for(int i =0;i<A.length;i++) {
			if (A[i].charAt(num) < c) return true;
			c = A[i].charAt(num);
		}
		return false;
	}
}
__________________________________________________________________________________________________
sample 38432 kb submission
class Solution {
    public int minDeletionSize(String[] A) {
        int res = 0;
        // M: total words ( rows )
        // N: word length ( cols )
        int M = A.length, N = A[0].length();
        
        for(int i = 0; i < N; i++){
            char[] seq = new char[M];
            for(int j = 0; j < M; j++){
                seq[j] = A[j].charAt(i);
            }
            if(!sorted(seq)){
                res++;
            }
        }
        return res;
    }
    
    private boolean sorted(char[] ch){
        char curr = ch[0];
        for(char c :ch){
            if(c < curr){
                return false;
            }
            curr = c;
        }
        return true;
    }
}
__________________________________________________________________________________________________
