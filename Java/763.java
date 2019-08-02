__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<Integer> partitionLabels(String S) {
                char[] cc = S.toCharArray();
        int[] charIndex = new int[26];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < cc.length; i++) {
            charIndex[cc[i] - 'a'] = i;
        }
        for (int i = 0; i < cc.length; ) {
            int lastIndex = charIndex[cc[i] - 'a'];
            for (int j = i + 1; j < lastIndex; j++) {
                int lastIndexJ = charIndex[cc[j]-'a'];
                if (lastIndexJ > lastIndex)
                    lastIndex = lastIndexJ;
            }
            res.add(lastIndex - i + 1);
            i = lastIndex + 1;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 34592 kb submission
class Solution {
    private static int index = -1;
    private static int last = -1;

  
    public List<Integer> partitionLabels(String S) {
      List<Integer> parts = new ArrayList<>();
      int[] count = new int[26];
      
      for (int nn = 0; nn < S.length(); ++nn) {
        ++count[S.charAt(nn) - 'a'];
      }
      
      Set<Integer> track = new HashSet<>();
            
      S.chars().forEach(c -> {
        ++index;
        --count[c - 'a'];

        if (count[c - 'a'] != 0) track.add(c);
        else track.remove(c);
        
        if (track.size() == 0) {
          parts.add(index - last);
          last = index;
        }
      });
      
      return parts;
    }
}
__________________________________________________________________________________________________
