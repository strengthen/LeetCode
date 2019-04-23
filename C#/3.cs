__________________________________________________________________________________________________
76ms
public class Solution {
    public int LengthOfLongestSubstring(string s) {
         int n = s.Length, ans = 0;
            int[] index = new int[128]; // current index of character
                                        // try to extend the range [i, j]
            for (int j = 0, i = 0; j < n; j++)
            {
                var sj = s[j];
                i = Math.Max(index[sj], i);
                ans = Math.Max(ans, j - i + 1);
                index[sj] = j + 1;
            }
            return ans;
    }
}
__________________________________________________________________________________________________
80ms
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        
        if (s.Length == 0) return 0;

        int longestSoFar = 1;
        int startIndex = 0;
        
        for (var endIndex = 0; endIndex < s.Length; endIndex++)
        {
            int currentCount = 1;
            for (var checkIndex = startIndex; checkIndex < endIndex; checkIndex++)
            {
                if (s[checkIndex] == s[endIndex])
                {
                    startIndex = checkIndex + 1;
                    break;
                }
                else
                {
                    currentCount++;
                    longestSoFar = (currentCount > longestSoFar) ? currentCount : longestSoFar;
                }
            }
        }
        
        return longestSoFar;
    }
}
__________________________________________________________________________________________________
84ms
public class Solution 
{
    public int LengthOfLongestSubstring(string s) 
    {
        var charToLastSeenIndexMap = new Dictionary<char, int>();
        
        var longestSubstring = 0;
        
        var indexStartSearch = 0;
        var index = 0;
        foreach (var c in s)
        {
            int lastSeenIndex;
            if (charToLastSeenIndexMap.TryGetValue(c, out lastSeenIndex))
            {
                indexStartSearch = Math.Max(indexStartSearch, lastSeenIndex + 1);
            }
            
            longestSubstring = Math.Max(longestSubstring, index - indexStartSearch + 1);
            
            charToLastSeenIndexMap[c] = index;
            index++;
        }
        
        return longestSubstring;
    }
}
__________________________________________________________________________________________________
22836 kb
public class Solution {
    public int LengthOfLongestSubstring(string s){
            int startIndex = 0;
            int counter = 0;
            int result = 0;
            for(int i = 0; i < s.Length; i++){
                int index = GetIndex(s, s[i], startIndex, i);
                if(index == -1){
                    counter += 1;
                }
                else{
                    counter = (counter - (index - startIndex + 1)) + 1;
                    startIndex = index + 1;
                }

                if(counter > result){
                    result = counter;
                }
            }

            return result;
        }

        public int GetIndex(string s, char c, int startIndex, int endIndex){
            for(int i = startIndex; i < endIndex; i++){
                if(s[i] == c){
                    return i;
                }
            }

            return -1;
        }
}
__________________________________________________________________________________________________
22856 kb
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        
            if (string.IsNullOrEmpty(s))
                return 0;
            int maxLenght = 1;
            int stringLenght = s.Length;
            int index1 = 0;
            int index2 = 0;
            List<char> list = new List<char>();
            list.Add(s[0]);
            
            for(int i=1; i< stringLenght; i++)
            {
                index2++;
                if(!list.Contains(s[index2]))
                {
                    list.Add(s[index2]);
                }
                else
                {
                    maxLenght = (index2 - index1) > maxLenght ? (index2 - index1) : maxLenght;
                    while (s[index1] != s[index2])
                    {
                        list.Remove(s[index1]);
                        index1++;
                    }
                    //list.Remove(s[index1]);
                    index1++;
                }
            }

            maxLenght = (index2 - index1 +1) > maxLenght ? (index2 - index1 + 1) : maxLenght;

            return maxLenght;
        
    }
}
__________________________________________________________________________________________________
