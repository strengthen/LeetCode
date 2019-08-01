__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean detectCapitalUse(String word) {
        String lWord = word.toLowerCase();
        //before lowercase
        if(lWord.equals(word)) {
            return true;
        }
        
        int diff=0;
        //before all caps
        for(int i=0;i<word.length();i++) {
            if(word.charAt(i) != lWord.charAt(i)) {
                diff++;
            }
        }
        
        if(diff==1 && lWord.charAt(0) != word.charAt(0)) {
            return true;
        } 
        
        if(diff==word.length()) {
            return true;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 36684 kb submission
class Solution {
    public boolean detectCapitalUse(String word) {
        int len=word.length();
        int u=0,i,l=0,c=0;
        char ch,ch1;
        for(i=0;i<len;i++)
        {
            ch=word.charAt(i);
            if(ch>=65 && ch<=90)
                u++;
        }
        
         for(i=0;i<len;i++)
        {
            ch=word.charAt(i);
             if(ch>=97 && ch<=122)
                l++;
        }
        ch1=word.charAt(0);
         if(ch1>=65 && ch1<=90 ) c=1;
         for(i=1;i<len;i++)
        {       
            ch=word.charAt(i);
            if (ch>=97 && ch<=122)        c++;
        }
          if(u==len||l==len||c==len)
              return true;
        else
            return false;
            
        }
    }
__________________________________________________________________________________________________
