__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int firstUniqChar(String s) {
        int minIndex = Integer.MAX_VALUE;
        for(char c='a'; c<='z'; c++) {
            int i = s.indexOf(c);
            if(i==s.lastIndexOf(c) && i!=-1 && i < minIndex) minIndex = i;
        }
        if(minIndex==Integer.MAX_VALUE) return -1;
        return minIndex;
    }
}
__________________________________________________________________________________________________
sample 35524 kb submission
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> letters = new HashMap<Character,Integer>();
        boolean present;
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            present = letters.containsKey(c);
            if(present){
                letters.put(c, -1);
            }
            else{
                letters.put(c, i);
            }
        }
        int[] min = {Integer.MAX_VALUE};
        boolean[] exist = {false};
        letters.forEach((k, v) -> {
            if(v<min[0] && v>-1){
                min[0] = v;
                exist[0] = true;
            }
        });
        return exist[0] ? min[0] : -1;
    }
}
__________________________________________________________________________________________________
