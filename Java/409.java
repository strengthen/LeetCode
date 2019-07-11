__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int longestPalindrome(String s) {
        int[] countArray = new int[52];
        for(char ch : s.toCharArray()){
            if(ch >= 'a' && ch <= 'z') countArray[ch - 'a']++;
            else countArray[ch-'A'+26]++;
        }
        int count = 0;
        boolean addOne = false;
        for(int i=0; i<countArray.length; i++){
            if(countArray[i] % 2 == 0){
                count = count + countArray[i];
            }else if(countArray[i] > 1) {
                count = count + (countArray[i]-1);
                addOne = true;
            }else if(countArray[i] == 1){
                addOne = true;
            }
        }
        
        if(addOne){
            return ++count;
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 34204 kb submission
class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> frequencyMap = new HashMap<>();

        for(char ch:s.toCharArray()){
            frequencyMap.compute(ch,(key,val)->val==null?1:val+1);
        }

        int totalLen = 0;
        boolean oddPresent = false;

        for(int i:frequencyMap.values()){
            if(i%2==0)
                totalLen+= i;
            else{
                oddPresent = true;
                totalLen += i-1;
            }
        }

        if(oddPresent) totalLen++;

        return totalLen;
    }
}
__________________________________________________________________________________________________
