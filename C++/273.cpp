__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string oneDigitNumbers(int num) {
        string result;
        switch (num) {
            case 1: result = " One"; break;
            case 2: result = " Two"; break;
            case 3: result = " Three"; break;
            case 4: result = " Four"; break;
            case 5: result = " Five"; break;
            case 6: result = " Six"; break;
            case 7: result = " Seven"; break;
            case 8: result = " Eight"; break;
            case 9: result = " Nine"; break;
            case 0: result = ""; break;
        }
        return result;
    }
    
    string twoDigitSpecial(int num) {
        string result;
        switch (num) {
            case 10: result = " Ten"; break;
            case 11: result = " Eleven"; break;
            case 12: result = " Twelve"; break;
            case 13: result = " Thirteen"; break;
            case 14: result = " Fourteen"; break;
            case 15: result = " Fifteen"; break;
            case 16: result = " Sixteen"; break;
            case 17: result = " Seventeen"; break;
            case 18: result = " Eighteen"; break;
            case 19: result = " Nineteen"; break;
        }
        return result;
    }
    
    string twoDigitNumbers(int num) {
        string oneDigit = oneDigitNumbers(num % 10);
        string result;
        switch(num/10) {
            case 1: result = twoDigitSpecial(num); break;
            case 2: result = " Twenty" + oneDigit; break;
            case 3: result = " Thirty" + oneDigit; break;
            case 4: result = " Forty" + oneDigit; break;
            case 5: result = " Fifty" + oneDigit; break;
            case 6: result = " Sixty" + oneDigit; break;
            case 7: result = " Seventy" + oneDigit; break;
            case 8: result = " Eighty" + oneDigit; break;
            case 9: result = " Ninety" + oneDigit; break;
            case 0: result = oneDigit; break;
        }
        return result;
    }
    
    string threeDigitNumbers(int num) {
        string twoDigit = twoDigitNumbers(num % 100);
        string firstDigit = oneDigitNumbers(num / 100);
        if (firstDigit.empty() && twoDigit.empty()) {
            return "";
        } else if (firstDigit.empty()) {
            return twoDigit;
        } else {
            return firstDigit + " Hundred" + twoDigit;
        }
    }
    
    string getThousandPrefix(int i) {
        switch (i) {
            case 1: return " Thousand";
            case 2: return " Million";
            case 3: return " Billion";
        }
        return "";
    }
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string result;
        int i = 0;
        while (num != 0) {
            string threeDigit = threeDigitNumbers(num % 1000);
            if (i == 0) {
                result = threeDigit;
            } else {
                string prefix = threeDigit.empty() ? "" : getThousandPrefix(i);
                result = threeDigit + prefix + result;
            }
            i++;
            num = num / 1000;
        }
        if (result[0] == ' ') {
            result = result.substr(1);
        }
        return result;
    }
};
__________________________________________________________________________________________________
sample 8404 kb submission
class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string thousands[]  = { "", " Thousand", " Million", " Billion" };
        int i=0;
        string res = "";
        while(num){
            if(num%1000!=0){
                res = helper(num%1000) + thousands[i] + (res.size()!=0 ? " ":"") + res;
            }
            num = num/1000;
            i++;
        }
        return res;
    }
    string helper(int num){
        string lessThan20[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(num >=100){
            return helper(num/100) + " Hundred" + (num%100!=0 ? " ":"") + helper(num%100);
        }
        else if(num >=20){
            return tens[(num/10)] + (num%10!=0 ? " ":"") + helper(num%10);
        }
        else
            return lessThan20[num];
    }
};
__________________________________________________________________________________________________
