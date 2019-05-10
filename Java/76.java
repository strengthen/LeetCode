__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String minWindow(String s, String t) {
        int arr[] = new int[128];
        int begin = 0, head=0,  end = 0, counter = t.length(), d = Integer.MAX_VALUE;
        for(int i = 0; i < t.length(); i++){
            arr[t.charAt(i)]++;
        }
        while(end < s.length()){
            if(arr[s.charAt(end++)]-- > 0) counter--;
            while(counter == 0){
                if( d > end - begin ){
                    d = end - begin;
                    head = begin;
                }
                if(arr[s.charAt(begin++)]++ == 0) counter++;
            }
        }
        return d == Integer.MAX_VALUE?"":s.substring(head, head+d);
    }
}
__________________________________________________________________________________________________
sample 34704 kb submission
class Solution {
    public String minWindow(String s, String t) {
        if(s == null || s.length() == 0 || t == null || t.length() == 0) return "";
        int[] map = new int[256];
        for(char ch : t.toCharArray()) {
            map[ch]++;
        }
        int count = t.length();
        int shortest = s.length() + 1;
        int start = 0;
       
        int left = 0;
    
        for(int right = 0; right < s.length(); right++) {
            if(--map[s.charAt(right)] >= 0) {
                count--;
            }
            while(count == 0) {
                if(right - left + 1 < shortest) {
                    shortest = right - left + 1;
                    start = left; 
                    
                }
                if(map[s.charAt(left)]++ >= 0) {
                    count++;
                }
               left++;
                
            }
        }
        return shortest == s.length() + 1 ? "" : s.substring(start, start + shortest);
    }
}
__________________________________________________________________________________________________
