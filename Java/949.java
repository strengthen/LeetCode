__________________________________________________________________________________________________
sample 0 ms submission

class Solution {
    int[] digits = new int[10];
    char[] time = new char[5];
    
    public String largestTimeFromDigits(int[] A) {
        time[2] = ':';
        
        for (int i = 0; i < 4; i ++)
            digits[A[i]] ++;
        
        if (digits[2] >= 1 &&
            digits[0] + digits[1] + digits[2] + digits[3] >= 2 && 
            digits[0] + digits[1] + digits[2] + digits[3] + digits[4] + digits[5] >= 3) {
                
            time[0] = '2';
            digits[2] --;
            
            select(1, 3);
        }
        else if (digits[0] + digits[1] >= 1 &&
                 digits[0] + digits[1] + digits[2] + digits[3] + digits[4] + digits[5] >= 2) {
            
            select(0, 1);
            select(1, 9);
        }
        else
            return "";
        
        select(3, 5);
        select(4, 9);
        return new String(time);
    }
    
    public void select(int index, int start) {
        for (int j = start; j >= 0; j --) {
            if (digits[j] > 0) {
                time[index] = (char) (j + 48);
                digits[j] --;
                break;
            }
        }
    }
}
__________________________________________________________________________________________________
sample 36016 kb submission
class Solution {
    private static final char[] letters = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    public static String largestTimeFromDigits(int[] A) {
        Arrays.sort(A);
        if(A[0] > 2) return "";
        int first = 4, second = 4;
        while(--first >= 0 && A[first] > 2);
        if(A[first] == 2){
        	if(A[2] > 5){
        		while(--first >= 0 && A[first] == 2);
        		if(first == -1) return "";
        		second = 3;
        	}else{
        		while((--second >= 0 && A[second] > 3) || second == first);
        		if(second == -1) return "";
        	}
        }else{
            second = first != 3 ? 3 : first - 1;
        }
        int third = -1;
        while(++third < 4 && (third == first || third == second));
        if(A[third] > 5) return "";
        int fourth = 6 - first - second - third;
        if(A[fourth] > 5){
        	return new String(new char[]{letters[A[first]], letters[A[second]], ':', letters[A[third]], letters[A[fourth]]});
        }else{
        	return new String(new char[]{letters[A[first]], letters[A[second]], ':', letters[A[fourth]], letters[A[third]]});
        }
    }
}
__________________________________________________________________________________________________
