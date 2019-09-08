__________________________________________________________________________________________________
sample 18 ms submission
class Solution {
    public String[] beforeAndAfterPuzzles(String[] phrases) {
        int N = phrases.length;
        Set<String> list = new HashSet<>();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int idx1 = phrases[i].lastIndexOf(" ");
                int idx2 = phrases[j].indexOf(" ");
                
                String w1 = idx1 == -1 ? phrases[i] : phrases[i].substring(idx1 + 1);
                String w2 = idx2 == -1 ? phrases[j] : phrases[j].substring(0, idx2);
                // System
                if (!w1.equals(w2)) continue;
                
                String word = "";
                if (idx1 == -1 && idx2 == -1) {
                    word = w1;
                } else if (idx1 == -1 || idx2 == -1) {
                    word = idx1 == -1 ? phrases[j] : phrases[i];
                } else {
                    word = phrases[i].substring(0, idx1) + " " + phrases[j];
                }
                list.add(word);
            }
        }
        
        String[] res = new String[list.size()];
        int i = 0;
        for (String word : list) {
            res[i++] = word;
        } 
        
        Arrays.sort(res);
        return res;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
