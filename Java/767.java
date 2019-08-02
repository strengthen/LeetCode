__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String reorganizeString(String S) {
        int freq[] = new int[26];
        for(int i=0;i<S.length();i++){
            freq[S.charAt(i)- 'a']++;
        }
        
        int max=0; int letter=0;
        for(int j=0;j<freq.length;j++){
            if(freq[j]>max){
                max=freq[j];
                letter=j;
            }
        }
       
        if(max>((S.length()+1)/2))
            return "";
        
        char[] res=new char[S.length()];
        int index=0;
        while(freq[letter]>0){
            res[index]=(char)((letter)+ 'a');
            index+=2;
            freq[letter]--;
        }
        for(int j=0;j<freq.length;j++){
            while(freq[j]>0){
                if(index>=S.length()) index=1;
                res[index]=(char)((j)+ 'a');
                 index+=2;
                freq[j]--;
            }
        }
      return String.valueOf(res);      
  }
}
__________________________________________________________________________________________________
sample 34296 kb submission
import java.util.*;

class Solution {
     public String reorganizeString(String S) {
        int N = S.length();
        int[] count = new int[26];
        for (char c: S.toCharArray()) count[c-'a']++;
        PriorityQueue<MultiChar> pq = new PriorityQueue<MultiChar>((a, b) ->
            a.count == b.count ? a.letter - b.letter : b.count - a.count);

        for (int i = 0; i < 26; ++i) if (count[i] > 0) {
            if (count[i] > (N + 1) / 2) return "";
            pq.add(new MultiChar(count[i], (char) ('a' + i)));
        }

        StringBuilder ans = new StringBuilder();
        while (pq.size() >= 2) {
            MultiChar mc1 = pq.poll();
            MultiChar mc2 = pq.poll();
            /*This code turns out to be superfluous, but explains what is happening
            if (ans.length() == 0 || mc1.letter != ans.charAt(ans.length() - 1)) {
                ans.append(mc1.letter);
                ans.append(mc2.letter);
            } else {
                ans.append(mc2.letter);
                ans.append(mc1.letter);
            }*/
            ans.append(mc1.letter);
            ans.append(mc2.letter);
            if (--mc1.count > 0) pq.add(mc1);
            if (--mc2.count > 0) pq.add(mc2);
            
        }

        if (pq.size() > 0) ans.append(pq.poll().letter);
        return ans.toString();
    }    
}

    class MultiChar {
        int count;
        char letter;
        MultiChar(int ct, char ch) {
            count = ct;
            letter = ch;
        }
    }
__________________________________________________________________________________________________
