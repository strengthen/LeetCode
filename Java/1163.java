__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public String lastSubstring(String S) {
        double mx = 0.0, pre = 0.0;
        int idx = 0, n = S.length();
        for(int i = n - 1; i >= 0; --i) {
            double cur = pre / 26.0 + S.charAt(i) - 'a';
            if (cur > mx) {
                mx = cur;
                idx = i;
            }
            pre = cur;
        }
        return S.substring(idx);
    }
}
__________________________________________________________________________________________________
sample 64 ms submission
class Solution {
    public String lastSubstring(String S) {
        for (char ch = 'z'; ch >= 'a'; ch--) {
            char chUp = (char)(ch + 'A' - 'a');
            // System.out.pr
            if (S.indexOf(ch) == -1 && S.indexOf(chUp) == -1)
                continue;
            // System.out.println(ch);
            List<Integer> list = new ArrayList<>();
            for (int i = S.indexOf(ch); i != -1; ) {
                list.add(i);
                i = S.indexOf(ch, i + 1);
            }
            
            for (int i = S.indexOf(chUp); i != -1; ) {
                list.add(i);
                i = S.indexOf(chUp, i + 1);
            }

            
            PriorityQueue<String> pq = new PriorityQueue<>((a, b) -> (a.compareTo(b)));
            for (int idx : list) {
                String word = S.substring(idx);
                // System.out.p
                pq.offer(word);
                if (pq.size() > 1) {
                    pq.poll();
                }
            }
            return pq.poll();
        }
        return S;
    }
}
__________________________________________________________________________________________________
