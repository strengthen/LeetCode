__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int uniqueLetterString(String S) {
        int[] lastPosition = new int[26];
        int[] contribution = new int[26];
        int result = 0;
        
        // at each iteration, we count the contribution of all the characters to all the substrings ending till that point
        for(int i = 0; i < S.length(); i++) {
            int current = S.charAt(i) - 'A';
            
            // update contribution to current character.
            // total # of substrings ending at i are i + 1. If it was a unique character, it would contribute to all of the substrings and its contribution is i + 1
            // if it is repeating, then it was contributed previously, so we will subtract its previous contribution
            // these are the contributions for strings which start after this character's last occurence and end at i
            int totalNumOfSubstrings = i + 1;
            contribution[current] = totalNumOfSubstrings - lastPosition[current];
            
            // the contribution of all other charcters will remain the same
            
            // count the current answer by adding all the contributions, only 26 letters in alphabet
            int curr = 0;
            for(int j = 0; j < 26; j++) {
                curr += contribution[j];
            }
            
            // add current value to final answer
            result += curr;
            
            // update last position of the current character
            lastPosition[current] = i + 1;
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 35660 kb submission
class Solution {
     public int uniqueLetterString(String S) {
        Map<Character, List<Integer>> index = new HashMap();
        for (int i = 0; i < S.length(); ++i) {
            char c = S.charAt(i);
            index.computeIfAbsent(c, x-> new ArrayList<Integer>()).add(i);
        }

        long ans = 0;
        for (List<Integer> A: index.values()) {
            for (int i = 0; i < A.size(); ++i) {
                long prev = i > 0 ? A.get(i-1) : -1;
                long next = i < A.size() - 1 ? A.get(i+1) : S.length();
                ans += (A.get(i) - prev) * (next - A.get(i));
            }
        }

        return (int) ans % 1_000_000_007;
    }
}
__________________________________________________________________________________________________
