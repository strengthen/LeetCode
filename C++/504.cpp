__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        string minus = "";
        if(num < 0)
        {
            minus = "-";
            num *= -1;
        }
        if(num == 0)
        {
            return "0";
        }
        
        while(num != 0)
        {
            int addednum = num % 7;
            num = num / 7;
            if(num == 0 && addednum == 0)
                break;
            result = std::to_string(addednum) + result;

        }
        return minus+result;
    }
};
__________________________________________________________________________________________________
sample 8304 kb submission
class Solution {
public:
    string convertToBase7(int num) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int index=0;
        string sign="";
        if(num<0) {sign="-";num=-num;}
        else if(num==0) return "0";
        string s="";
        while(num) {
            s=char('0'+num%7)+s;
            num/=7;
        }
        s=sign+s;
        return s;
    }
};
__________________________________________________________________________________________________
