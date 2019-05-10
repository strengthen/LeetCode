__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0 || s.charAt(0) == '0') {
            return 0;
        }
        
        int preTotal = 1;
        int total = 1;
        char prev = s.charAt(0);
        
        for (int i = 1; i < s.length(); ++i) {
            char current = s.charAt(i);
            
            if (current == '0') {
                if (prev == '1' || prev == '2') {
                    total = preTotal;   
                } else {
                    return 0;
                }
            } else if (prev == '1' || (prev == '2' && current < '7')) {
                total += preTotal;
                preTotal = total - preTotal;
            } else {
                preTotal = total;
            }
            
            prev = current;
        }
        
        return total;
    }
}
__________________________________________________________________________________________________
× Close
sample 33172 kb submission
class Solution {
    public int numDecodings(String s) {
        if(s == null || s.length() == 0) return 0;
        int single = 0, couple = 0;
        char[] num = s.toCharArray();
        for(int i= 0; i < num.length; i++){
            if(i == 0) single = 1;
            if(num[i] == '0'){
                if(i == 0 || num[i-1] == '0' || num[i-1] >= '3') return 0;
                else if(num[i-1] <= '2' && num[i-1] >= '1'){
                    int temp = single;
                    single = 0;
                    couple = temp;
                }
            } else if(num[i] >='1' && num[i] <= '6'){
                if(i == 0 || num[i-1] >='3'|| num[i-1] == '0'){
                    single += couple;
                    couple = 0;
                } else if(num[i-1] >= '1' && num[i-1] <='2') {
                    int temp = single;
                    single += couple;
                    couple = temp;
                }
            } else if(num[i] >= '7' && num[i] <= '9'){
                if(i == 0 || num[i-1] != '1') {
                    single += couple;
                    couple = 0;
                } else {
                    int temp = single;
                    single += couple;
                    couple = temp;
                }
            }
            //System.out.println(single+" "+ couple);
        }
        return single + couple;
    }
}
__________________________________________________________________________________________________
