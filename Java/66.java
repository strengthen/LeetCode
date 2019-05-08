__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] plusOne(int[] digits) {        
    int n = digits.length;
    for(int i=n-1; i>=0; i--) {
        if(digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        
        digits[i] = 0;
    }
    
    int[] newNumber = new int [n+1];
    newNumber[0] = 1;
    
    return newNumber;
}
}
__________________________________________________________________________________________________
sample 34596 kb submission
class Solution {
    public int[] plusOne(int[] digits) {
		  HashMap<Integer, Integer> mp=new HashMap<Integer,Integer>();
		  int j=0,i=0,carry=1,temp=0;
		  for ( j=digits.length-1;j>=0;j--)
		  { 
			    	  temp=((digits[j])+carry)%10;
			    	  if((digits[j])+carry==10)
			    	  carry=1;
			    	  else carry=0;
			      
			    	  mp.put(i,temp);
			    	  i++;
		  }
		  if (carry==1)
			  mp.put(i,carry);

		  int[] newarr=new int[mp.size()];
		  i=0;
		  for (int p=mp.size()-1;p>=0;p--)
		  {
			  newarr[i]=mp.get(p);
			  i++;	
		  }  
		  
		  return newarr;    
	    
    }
}
__________________________________________________________________________________________________
