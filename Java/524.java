__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    
    private int[][] arrays;
    public String findLongestWord(String s, List<String> d) {
        if(s.length()==0)
            return "";
        
        createArrays(s);
        
        int longestMatch=0;
        String current="";
        String next;
        for(int i=0;i<d.size();++i)
        {
            next = d.get(i);
            if(next.length()>longestMatch || (next.length()==longestMatch && next.compareTo(current)<0))
            {
                if(canMakeStringFast(next))
                {
                    current = next;
                    longestMatch = current.length();
                }
            }
        }
        
        return current;
    }
    
    private boolean canMakeString(String s, String l)
    {
        int left=0, right=0;
        
        while(true){
            if(s.charAt(left) == l.charAt(right)){
                ++right;
            }
            
            ++left;
            if(right==l.length())
                return true;
            if(left==s.length())
                return false;
        }
    }
    
    private boolean canMakeStringFast(String l)
    {
        int index = 0;
        for(int i=0;i<l.length();++i)
        {
            index = arrays[index][l.charAt(i)-'a'];
            if(index==0)
                return false;
        }
        return true;
    }
    
    private void createArrays(String s)
    {
        arrays = new int[s.length()+1][26];
        int posp1 = s.length();
        int pos = posp1-1;
        
        while(true){
            arrays[pos][s.charAt(pos)-'a'] = posp1;

            --pos;
            --posp1;
            if(pos<0)
                break;
            for( int i =0; i< 26;++i)
                arrays[pos][i]=arrays[posp1][i];
        }
    }
}
__________________________________________________________________________________________________
sample 36156 kb submission
class Solution {
    public String findLongestWord(String s, List<String> d){
        /*
        if a.length() == b.length(), a and b are comparable, we sort a and b in lexicographical order
        Else, we compare a and b according to their length.
        */
        Collections.sort(d, (a, b) -> a.length() == b.length()?
                        a.compareTo(b) : b.length() - a.length());
                        
        for(String word: d){
            int count = 0;
            for(int i = 0; i < s.length(); i++){
                if(count < word.length() && s.charAt(i) == word.charAt(count)) count++; 
            }
            if(count == word.length()) return word;
        }
        return "";
    }
}
__________________________________________________________________________________________________
