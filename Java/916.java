__________________________________________________________________________________________________
sample 11 ms submission
class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] count = new int[26];
        for(String b : B) {
            fill(b, count);
        }
        List<String> res = new ArrayList<String>();
        for(String a : A) {
            if(isAnswer(a, count)) {
                res.add(a);
            }
        }
        return res;
    }
    
    private void fill(String b, int[] count) {
        int[] temp = new int[26];
        for(int i = 0; i < b.length(); i++) {
            char c = b.charAt(i);
            int idx = c - 'a';
            temp[idx]++;
            count[idx] = Math.max(count[idx], temp[idx]);
        }
    }
    
    private boolean isAnswer(String a, int[] count) {
        int[] temp = new int[26];
        for(int i = 0; i < a.length(); i++) {
            char c = a.charAt(i);
            temp[c - 'a']++;
        }
        for(int i = 0; i < count.length; i++) {
            if(count[i] == 0) continue;
            if(temp[i] < count[i]) {
                return false;
            }
        }
        return true;
    }  
}
__________________________________________________________________________________________________
sample 48748 kb submission
class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
    	
      int La=A.length, i=0, j=0, Lb=B.length, L=0, t=0;
      String cur;
      char [] cur1;
      int [] cal=new int [26], curCal;
      
      while( i<Lb )
      {
    	cur=B[i];
    	cur1=cur.toCharArray();
    	
    	curCal=new int [26];
    	L=cur.length();
    	j=0;
    	while( j<L )
    	{
    	  curCal[cur1[j]-'a']++;	
    	  j++;	
    	}
    	
    	j=0;
    	while( j<26 )
    	{
    	  t=curCal[j];
    	  if( t>0 && t>cal[j] )
    		cal[j]=t;
    	  j++;	
    	}    	  
        i++;	  
      }
      i=0;
      
      List<String> l=new ArrayList<String>();
      while( i<La )
      {
    	cur=A[i];
    	cur1=cur.toCharArray();
    	
    	curCal=new int [26];
    	L=cur.length();
    	j=0;
    	while( j<L )
    	{
    	  curCal[cur1[j]-'a']++;	
    	  j++;	
    	}
    	
    	j=0;
    	while( j<26 )
    	{    	  
    	  if( curCal[j]<cal[j] )
    		break;
    	  j++;	
    	}
    	
    	if( j==26 )
    	  l.add(cur);
        i++;	  
      }
      return l;        
    }
}
__________________________________________________________________________________________________
