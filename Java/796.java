__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean rotateString(String A, String B) {
        if (A.length() != B.length()) {
            return false;
        }
        String str = A + A;
        int idx = str.indexOf(B);
        return idx != -1;
    }
}
__________________________________________________________________________________________________
sample 34484 kb submission
class Solution {
    public boolean rotateString(String A, String B) {
        if(A.length() != B.length()) {
            return false;
        } else if(A.equals(B)) {
            return true;
        }
        List<Character> charsA = A.chars()  			// IntStream
								.mapToObj(e -> (char)e) // Stream<Character>
								.collect(Collectors.toList());   
        
        List<Character> charsB = B.chars()  			// IntStream
								.mapToObj(e -> (char)e) // Stream<Character>
								.collect(Collectors.toList()); 
        int charsASize = charsA.size();     
        for(int i=0; i<charsASize; i++) {
            charsA.add(charsASize, charsA.get(0));
            charsA.remove(0);
            if(charsA.equals(charsB)) {
                return true;
            }
        }  
        return false;
    }
}
__________________________________________________________________________________________________
