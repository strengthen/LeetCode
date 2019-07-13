__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String frequencySort(String s) {
        char[] charArr = new char[128];
        
        
        for(char c :  s.toCharArray()) 
            charArr[c]++;
        
        StringBuilder sb = new StringBuilder();

        
        while(sb.length() < s.length()) {
                    char maxChar = 0;
            for(char charCur = 0; charCur < charArr.length; charCur++) {
                
                if(charArr[charCur] > charArr[maxChar]) {
                    maxChar = charCur;
                }
                 }
                while(charArr[maxChar] > 0){
                    sb.append(maxChar);
                    charArr[maxChar]--;
                        
                }
           
        }
        
        return sb.toString();
    }
}
__________________________________________________________________________________________________
sample 35756 kb submission
class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        PriorityQueue<Character> maxHeap = 
            new PriorityQueue<>((c1, c2) -> map.get(c2) - map.get(c1));
        StringBuilder sortedString = new StringBuilder();
        
        for(char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        
        for(char key: map.keySet()) {
            maxHeap.offer(key);
        }
        
        while (!maxHeap.isEmpty()) {
            char key = maxHeap.poll();
            for(int i = 0; i < map.get(key); i++) {
                sortedString.append(key);
            }
        }
        
        return sortedString.toString();
    }
}
__________________________________________________________________________________________________
