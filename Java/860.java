__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    
    // Greedy? Use biggest first
    public boolean lemonadeChange(int[] bills) {
        if (bills == null) {
            return false;
        }
        if (bills.length == 0) {
            return true;
        }
        // No need for twenty
        // int five = 0, ten = 0, twenty = 0;
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                    // twenty++;
                } else if (five >= 3) {
                    five -= 3;
                    // twenty++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 39820 kb submission
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0;
        int tens = 0;
        boolean allHappy = true;
        for(int i =0; i<bills.length; i++){
            int bill = bills[i];
                System.out.println(bills[i]+ "      "+five + "     "+ tens + "     ");
            if(bill == 5){
                //nothing to do
                five++;
            }
            if(bill == 10){
                if(five == 0){
                    allHappy = false;
                    break;
                }else{
                    tens++;
                    five--;
                }
            }
            if(bill == 20){
                if(tens == 0 && five<3){
                    allHappy = false;
                }else if(tens >= 1 && five<1){
                    allHappy = false;
                }else if(tens >= 1 && five>=1){
                    tens--;
                    five--;
                }else if(tens == 0 && five>=3){
                    five--;
                    five--;
                    five--;
                }
            }            
        }
        return allHappy;
    }
}
__________________________________________________________________________________________________
