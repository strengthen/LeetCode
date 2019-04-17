__________________________________________________________________________________________________
1ms
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char [] str;
        if(s!=null&&s.length()!=0)
            str = s.toCharArray();
        else return 0;
        int first = 0,cur = 1;
        int maxlenth = 1;
        for(cur = 1;cur < s.length();cur++){
            for(int i = first;i < cur;i++){
                if(str[i] == str[cur])
                {
                    first = i+1;
                    break;
                }
            }
            maxlenth = ((cur - first + 1)>maxlenth)?(cur - first + 1):maxlenth;
        }
        return maxlenth;

    }
}
__________________________________________________________________________________________________
2ms
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        int[] index = new int[128]; // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            i = Math.max(index[s.charAt(j)], i);
            ans = Math.max(ans, j - i + 1);
            index[s.charAt(j)] = j + 1;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s == null || s.length() == 0) {
            return 0;
        }  
        int longestSubstringWithoutRepeatingCharLength = 0;
        int currentSubstringWithoutRepeatingCharStart = 0;
        
        for(int i=0;i<s.length();i++) {
          int sameCharIndex = hasChar(s,currentSubstringWithoutRepeatingCharStart, i, s.charAt(i));  
          if(sameCharIndex != -1) {
             currentSubstringWithoutRepeatingCharStart = sameCharIndex+1; 
          } else {
             longestSubstringWithoutRepeatingCharLength = Math.max(i-currentSubstringWithoutRepeatingCharStart +1, longestSubstringWithoutRepeatingCharLength); 
          }

        }
        return longestSubstringWithoutRepeatingCharLength;
    }
    
    private int hasChar(String s, int start, int end, char c) {
        for(int i=start;i<end;i++) {
            if(s.charAt(i) == c) {
                return i;
            }
        }
        return -1;
    } 
}
__________________________________________________________________________________________________
4ms
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()<=1){
            return s.length();
        }
        BitSet bitSet=new BitSet(0x0100);
        int length=1;
        int index0=0;
        for(int index1=0;index1<s.length();++index1){
            char ch1=s.charAt(index1);
            while(bitSet.get(ch1)){
                char ch0=s.charAt(index0);
                bitSet.set(ch0,false);
                ++index0;
            }
            bitSet.set(ch1,true);
            if(length<index1-index0+1){
                length=index1-index0+1;
            }
        }
        return length;
     }
}
__________________________________________________________________________________________________
35812 kb
class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        if(s.length()==0)
            return 0;
        int startIndexOfSubStr = 0;
        int length = 1;

        HashMap<String, Integer> map = new HashMap<>();

        map.put(s.substring(0,1), 0);

        for (int index = 1; index < s.length(); index++) {
            String substr = s.substring(index, index+1);
            if (map.containsKey(substr)) {
               
                int a = map.get(substr);
                if (a >= startIndexOfSubStr) {
                    startIndexOfSubStr = a + 1;
                }
            }
            
            map.put(substr, index);
            int lengthOfSubstr = index - startIndexOfSubStr + 1;
            length = Math.max(length, lengthOfSubstr);
        }
        return length;
    }
}
__________________________________________________________________________________________________
