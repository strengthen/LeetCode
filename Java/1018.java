__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> result = new ArrayList<>(A.length);
        int remainder = 0;
        for (int a : A) {
            remainder = ((remainder << 1) + a) % 5;
            result.add(remainder == 0);
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 39448 kb submission
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean>  resp = new ArrayList<Boolean>();
			int total=0;
			for(int i=0;i<A.length;i++){
				total=total*2+A[i];
				if(total%5==0){
					resp.add(true);
				}else{
					resp.add(false);
				}
                total%=5;
			}	
		return resp; 
    }
}
__________________________________________________________________________________________________
