__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numJewelsInStones(String J, String S) {
        int[] arr = new int[128];
        for (char ch: S.toCharArray()) {
            arr[ch] += 1;
        }
        int res = 0;
        for (char ch: J.toCharArray()) {
            res += arr[ch];
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 34396 kb submission
class Solution {
    public int numJewelsInStones(String J, String S) {
        Map<Character, Integer> stonesByType = new HashMap<>();
        for (Character c : S.toCharArray()) {
            if (J.indexOf(c) != -1) {
                stonesByType.merge(c, 1, (oldValue, newValue) -> ++oldValue);
            }
        }
        int result = 0;
        for (char c : J.toCharArray()) {
            if (stonesByType.containsKey(c)) {
                result += stonesByType.get(c);
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
