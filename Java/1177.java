__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public List canMakePaliQueries(String s, int[][] queries) {
        int[] cache = new int[s.length() + 1];
        for(int i = 0; i < s.length(); i++) {
            cache[i + 1] = cache[i] ^ (1 << (s.charAt(i) - 'a'));
        }
        List ans = new ArrayList<>();
        for(int[] query : queries) {
            if(query[2] >= 13) {
                ans.add(true);
            }
            else {
                int cnt = convert(cache[query[1] + 1] ^ cache[query[0]]); //convert bitmap form to number
                if(query[2] < cnt / 2) ans.add(false);
                else ans.add(true);
            }
        }
        return ans;
    }
    private int convert(int num) {
        int cnt = 0;
        while(num > 0) {
            cnt += num % 2;
            num /= 2;
        }
        return cnt;
    }
}
__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public List canMakePaliQueries(String s, int[][] queries) {
        int[] cache = new int[s.length() + 1];
        int uniqueCharCounter = 0;
        for(int i = 0; i < s.length(); i++) {
            int bitmap = 1 << (s.charAt(i) - 'a');
            if((uniqueCharCounter & bitmap) != 0) uniqueCharCounter -= bitmap;
            else uniqueCharCounter += bitmap;
            cache[i + 1] = uniqueCharCounter;
        }
        List ans = new ArrayList<>();
        for(int[] query : queries) {
            if(query[2] >= 13) {
                ans.add(true);
                continue;
            }
        int uni = cache[query[1] + 1] ^ cache[query[0]]; // unique characters in substring
        int cnt = convert(uni); //convert bitmap form to number
        if(query[2] < cnt / 2) ans.add(false);
        else ans.add(true);
        }
        return ans;
    }
    private int convert(int num) {
        int cnt = 0;
        while(num > 0) {
            cnt += num % 2;
            num /= 2;
        }
        return cnt;
    }
}
__________________________________________________________________________________________________
