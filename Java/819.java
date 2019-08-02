__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Trie root = new Trie();
        Trie curr= root;
        for(String ban:banned){
            for(int i=0;i<ban.length();i++){
                int idx = ban.charAt(i)-'a';
                if(curr.next[idx]==null){
                    curr.next[idx]=new Trie();
                }
                curr=curr.next[idx];
            }
            curr.banned=true;
            curr= root;
        }
        paragraph = paragraph.toLowerCase();
        int maxCount=0;
        String mostFrequent="";
        char[] pArray = paragraph.toCharArray();
        for(int i=0,j=0;i<pArray.length;i=j+1){
            while(i<pArray.length && (pArray[i]<'a' || pArray[i]>'z')) i++;
            for(j=i;j<pArray.length && (pArray[j]>='a'&& pArray[j]<='z');j++){
                int idx = pArray[j]-'a';
                if(curr.next[idx]==null){
                    curr.next[idx]=new Trie();
                }
                curr=curr.next[idx];
            }
            if(curr!=root && !curr.banned){
                curr.count++;
                if(curr.count>maxCount){
                    mostFrequent= paragraph.substring(i,j);
                    maxCount++;
                }
            }
            curr=root;
        }
        return mostFrequent;
    }
    class Trie{
        Trie[] next = new Trie[26];
        int count;
        boolean banned=false;
    }
}
__________________________________________________________________________________________________
sample 34680 kb submission
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        if (paragraph == null || banned == null) return "";

        Set<String> ban = new HashSet<>(Arrays.asList(banned));
        String[] words = paragraph.toLowerCase().split("\\W+");
        
        Map<String, Integer> freq = new HashMap<>();
        for (String word : words) {
            if (!ban.contains(word)) freq.put(word, freq.getOrDefault(word, 0) + 1);
        }

        return Collections.max(freq.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
__________________________________________________________________________________________________
