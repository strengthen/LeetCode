__________________________________________________________________________________________________
sample 1 ms submission
import java.util.*;
import static java.util.Arrays.asList;

class Solution {
    
    public String reverseVowels(String s) {
        if( s == null || s.length() == 0 ) return s;
        boolean[] vowels = new boolean[256];
        char[] v = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        for( char c : v ) vowels[c] = true;
        int left = 0, right = s.length() - 1;
        char[] array = s.toCharArray();
        while( left < right ) {
            while( left < right && !vowels[array[left]] ) left++;
            while( right > left && !vowels[array[right]] ) right--;
            if( left >= right ) break;
            char temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
        return new String( array );
    }
}
__________________________________________________________________________________________________
sample 35940 kb submission
class Solution {
    public String reverseVowels(String s) {
      //input validation
        if(s==null || s.length()==0)
            return s;
          char[] result = s.toCharArray();  // is a must to let swap works
        int start= 0 , end = s.length()-1;
       while( start < end){
           
           while (start < end && !isVowel(result[start]) )  // start < end should be added not to exceed the string's length
               start++;
           
            while (start < end && !isVowel(result[end]))
              end--;
           
           swap(result, start , end );
           
           start++;  // for new start and end
            end--;
           
       }
   // return s; // dont forget return statment.
        return new String(result);
    }  
    
    private boolean isVowel(char c ){
        c = Character.toLowerCase(c);
        if (c == 'a' ||c == 'e' || c == 'o' || c == 'i' || c == 'u' )
            return true;
        else return false;
    }
    
    private void swap(char[] s , int i , int j){
        if (s[i] == s[j]) return; // no need for swap
        
         char temp =  s[i];
         s[i] = s[j];
         s[j] = temp;
    }    
}
__________________________________________________________________________________________________
