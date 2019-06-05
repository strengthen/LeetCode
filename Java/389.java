__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public char findTheDifference(String s, String t) {
        char[] sArray = s.toCharArray(), tArray = t.toCharArray();
        char c = tArray[0];
        for (int i = 0; i < sArray.length; i++) {
            c ^= sArray[i] ^ tArray[i + 1];
        }
        return c;
    }
}
__________________________________________________________________________________________________
sample 34616 kb submission
class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> map = new HashMap<>(t.length(), 1);
        for (char c : t.toCharArray()) {
            map.merge(c, 1, (a,b) -> a + 1);
        }
        for (char c : s.toCharArray()) {
            if (map.containsKey(c)){
                Integer value = map.get(c);
                if (value == 1) {
                    map.remove(c);
                } else {
                    map.put(c, value - 1);
                }
            } else {
                return c;
            }
        }
        return map.keySet().iterator().next();
    }
}
__________________________________________________________________________________________________
