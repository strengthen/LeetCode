__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int characterReplacement(String s, int k) {
        if (s.length() <= k){
            return s.length();
        }
        int[] hash = new int[256];
        int l = 0, r = 0, max = 0, res = 0;
        char[] chs = s.toCharArray();
        while (r < chs.length){
            hash[chs[r]]++;
            if (hash[chs[r]] > max){
                max = hash[chs[r]];
            }
            r++;
            while(r - l - max > k){
                hash[chs[l++]]--;
            }
            res = Math.max(res, r - l);   
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 35112 kb submission
class Solution {
    public static class CharacterCount {
        int count=0;
        void incr() { count++; }
        void decr() { count--; }
    }

    public static void addCharacter(PriorityQueue<CharacterCount> pq, CharacterCount count) {
        pq.remove(count);
        count.incr();
        pq.add(count);
    }

    public static void removeCharacter(PriorityQueue<CharacterCount> pq, CharacterCount count) {
        pq.remove(count);
        count.decr();
        pq.add(count);
    }

    public static int characterReplacement(String s, int k) {
        if (s.isEmpty())
            return 0;
        if (s.length() == 1)
            return 1;
        CharacterCount[] characterCounts = new CharacterCount[26];
        for(int i=0; i<characterCounts.length; i++) {
            characterCounts[i] = new CharacterCount();
        }
        PriorityQueue<CharacterCount> pq = new PriorityQueue<>(characterCounts.length, (c1, c2) -> Integer.compare(c2.count, c1.count));
        int begin=0;
        int maxLength = Integer.MIN_VALUE;
        characterCounts[s.charAt(0)-'A'].incr();
        pq.add(characterCounts[s.charAt(0)-'A']);
        for(int i=1; i<s.length(); i++) {
            addCharacter(pq, characterCounts[s.charAt(i)-'A']);
            while(pq.peek().count+k < i-begin+1) {
                removeCharacter(pq, characterCounts[s.charAt(begin++)-'A']);
            }
            maxLength = Integer.max(maxLength, i-begin+1);
        }

        return maxLength;
    }
}

__________________________________________________________________________________________________
