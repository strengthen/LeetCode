__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String removeDuplicates(String S) {
        char[] sChars = S.toCharArray();
        int prevLength = -1, currentLength = S.length();
        if(S.length() < 2){
            return S;
        }
        while(prevLength != currentLength){
           prevLength = currentLength;
           currentLength = findDuplicates(sChars, prevLength);
        }
        return new String(sChars).substring(0, currentLength);      
    }
    int findDuplicates(char[] sChars, int length){
        int k = 0;
		char prev = '\0';
        //System.out.println("Round starting");
        for(int i=0;i<length;i++){
            if(prev != sChars[i]){
                sChars[k++] = sChars[i];
                prev = sChars[i];
            }
            else{
                k--;
                if(k>0){
                    prev = sChars[k-1];
                   
                }
                else{
                    prev = '\0';
                    k = 0;
                }
                
            }
            //System.out.println("prev:"+ prev + ",k:"+k + ",i:"+i);
        }
        //System.out.println("EOD:"+ new String(sChars).substring(0, k));
        return k;
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public String removeDuplicates(String S) {
        if(S == null || S.length() < 2) return S;
        
        int index = 0;
        char[] chars = new char[S.length()];
        
        for(char c : S.toCharArray()) {
            if(index != 0 && chars[index - 1] == c) {
                index--;
            }
            else {
                chars[index++] = c;
            }
        }
        
        return new String(chars).substring(0, index);
    }
}
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public String removeDuplicates(String S) {
        if(S.length()<=1){
            return S;
        }
        //"abbaca"
        // e     i 
        char[] array = S.toCharArray();
        //index we are checking
        int index = 1 ;
        //last valid character
        int end = 0;
        while(index<array.length){
            if(end>=0 &&array[index] == array[end]){
                    index++;
                end--;
            } else {
                 array[++end] = array[index++];
            }    
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<=end; i++){
            sb.append(array[i]);
        }
        return sb.toString();       
    }
}