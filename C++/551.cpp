__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool checkRecord(string s) {
        bool seenA = false;
        char prev = '#';
        int count = 1;
        for(char c : s){
            if (prev != c){
                count = 1;
            }
            else{
                count++;
            }
            if (c == 'A'){
                if (seenA){
                    return false;
                }
                seenA = true;
            }
            else if (c == 'L'){
                if (count == 3){
                    return false;
                }
            }
            prev = c;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 8868 kb submission
class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        
        for (char ch: s) {
            if (ch == 'A') A++;
            
            if (ch == 'L') L++;
            else L = 0;
            
            if (A == 2 || L == 3) return false;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
