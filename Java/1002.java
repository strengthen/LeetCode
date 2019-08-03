__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> resultList = new ArrayList<>();
        int result[] = new int[26];
        for(char c : A[0].toCharArray()){
            result[c-'a']++;
        }
        
        for(int i=1;i<A.length;i++){
            updateChar(result,A[i]);
        }
        
        for(int i=0;i<result.length;i++){
            while(result[i] > 0){
                resultList.add((char) (i+'a') + "");
                result[i]--;
            }
            
        }    
        return resultList;
    }
    
    private void updateChar(int arr[],String s){
        int result[] = new int[26];
        for(char c : s.toCharArray()){
            result[c-'a']++;
        }
        
        for(int i=0;i<result.length;i++){
            if(result[i] < arr[i])
                arr[i]=result[i];
        }
    }
}
__________________________________________________________________________________________________
sample 35600 kb submission
class Solution {
    public List<String> commonChars(String[] A) {
        int[][] freq = new int[26][A.length];
        List<String> result = new ArrayList<>();
        for (int i = 0; i < A.length; i++) {
            for (char c : A[i].toCharArray()) {
                freq[c - 'a'][i]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            int common = Arrays.stream(freq[i]).min().getAsInt();
            for (int k = 0; k < common; k++) result.add(String.valueOf((char)(i + 'a')));
        }
        return result;
    }
}
__________________________________________________________________________________________________
