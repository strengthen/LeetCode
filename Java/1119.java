__________________________________________________________________________________________________
class Solution {
    public String removeVowels(String S) {
        StringBuilder sb = new StringBuilder();
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        for (int i = 0; i < S.length(); i++) {
            if (set.contains(S.charAt(i))) continue;
            sb.append(S.charAt(i));
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
