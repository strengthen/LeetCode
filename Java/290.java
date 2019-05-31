__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] match=new String[26];
        int[] matchNum=new int[26];
        for(int i=0;i<26;i++)
            matchNum[i]=0;
        int len1=pattern.length(),len2=str.length();
        int k=0;
        for(int i=0;i<len1;i++)
        {           
            char ch=pattern.charAt(i);
            int j=(int)(ch-'a');
            StringBuffer s = new StringBuffer();
            while(k<len2&&str.charAt(k)!=' ')
            {
                s.append(str.charAt(k));
                k++;
            }
            k++;
            String word=s.toString();
            if(matchNum[j]==0)                
            {
                for(int y=0;y<26;y++)
                    if(matchNum[y]==1&&word.equals(match[y]))
                       return false;
                match[j]=word;
               matchNum[j]=1;
            }
            else
            {
                 if(!match[j].equals(word))
                     return false;
            }           
        }
        if(k-1==len2)
            return true;
        else
            return false;
    }
}
__________________________________________________________________________________________________
sample 32664 kb submission
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        // store char in pattern with matching word
        Map<Character, String> map = new HashMap<>();
        if (pattern.length() != words.length)
            return false;
        
        for (int i = 0; i < words.length; i++)
        {
            char curr = pattern.charAt(i);
            if (map.containsKey(curr))
            {
                // check if word for this char equals the current word
                if (!map.get(curr).equals(words[i]))
                    return false;
            }
            else
            {
                // if word already exists, then return false since it shouldn't be in map yet
                if (map.containsValue(words[i]))
                    return false;
                // put char with current word into map
                map.put(curr, words[i]);
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
