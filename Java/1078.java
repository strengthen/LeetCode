__________________________________________________________________________________________________
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
      String[] t = text.split(" ");
      int ind = 0;
	  
	  //Loop through words, if last two are first and second respectively, then add current to array.
      for(int i = 2; i < t.length; i++)
        if(t[i-1].equals(second) && t[i-2].equals(first)) t[ind++]=t[i];
		
	  //Construct and fill output array.
	  String[] ans = new String[ind];
	  for(int i = 0; i < ind; i++)
	  	  ans[i]=t[i];
			
	  return ans;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
