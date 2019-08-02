__________________________________________________________________________________________________
sample 1 ms submission
/*
自己最开始的想法错了。统计个数的方法无法区分是不是连续，所以像"abaa",["ab"]这个例子本来应该是0，但是我的方法就会返回1。后来看了discuss排名第二的解法，是用双指针来做。我们用i和就分别表示S和word的指针，如果i和j位置不相等就直接返回false，否则我们分别得到重复字母的长度len1和len2。然后的判断逻辑就跟我自己想法中的判断逻辑一样了
*/

class Solution {
    public int expressiveWords(String S, String[] words) {
        int res = 0;
        for (String word : words) {
            if (check(S, word)) {
                res++;
            }
        }
        return res;
    }
    
    public boolean check(String s, String word) {
        int i = 0, j = 0;
        while (i < s.length() && j < word.length()) {
            if (s.charAt(i) != word.charAt(j)) {
                return false;
            }
            int len1 = getRepeatedLength(s, i);
            int len2 = getRepeatedLength(word, j);
            if (len1 < 3 && len1 != len2) {
                return false;
            }
            if (len1 >= 3 && len2 > len1) {
                return false;
            }
            i += len1;
            j += len2;
        }
        //这个不要忘了
        return i == s.length() && j == word.length();
    }
    
    public int getRepeatedLength(String s, int index) {
        char c = s.charAt(index);
        int count = 0;
        while (index < s.length() && s.charAt(index) == c) {
            count++;
            index++;
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 36996 kb submission
class Solution {
    List<Pair> sMap;
    public int expressiveWords(String S, String[] words) {
        sMap = new ArrayList<>();
        int start = 0, pt = 0;
        while(pt < S.length()){
            while(pt+1 < S.length() && S.charAt(pt) == S.charAt(pt+1)){
                pt++;
            }
            sMap.add(new Pair(S.charAt(pt), pt - start + 1));
            pt = start = pt + 1;
        }
        int tot = 0;
        for(String word : words){
            if(isStretchy(word)){
                tot += 1;
            }
        }
        return tot;
    }
    
    public boolean isStretchy(String word){
        int start = 0;
        int pt = 0;
        Pair p;
        int i=0;
        for(; i < sMap.size(); i++){
            p = sMap.get(i);
            if(pt < word.length()){
                if(p.let != word.charAt(pt)){
                    return false;
                }
                while(pt<word.length() && word.charAt(pt)==p.let){
                    pt++;
                }

                if(p.count < pt-start || (p.count > pt-start) && p.count < 3){
                    return false;
                }
                start = pt;
            }
            else{
                break;
            }
        }
        if(pt == word.length() && i == sMap.size()){
            return true;
        }
        else{
            return false;
        }        
    }
    
    class Pair{
        Pair(char let, int num){
            this.let = let;
            this.count = num;
        }
        char let;
        int count;
    }
}
__________________________________________________________________________________________________
