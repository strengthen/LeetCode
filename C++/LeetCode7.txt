__________________________________________________________________________________________________
4ms
class Solution {
public:
    int reverse(int x) {
        if(x >= INT_MAX || x <= INT_MIN){
            return 0;
        }
        
        int temp = x>=0 ? x: (0-x);
        long sum =0;
        while(temp/10 !=0){
            sum = sum*10 + temp%10;
            temp = temp/10;
        }
        
        sum = sum*10 + temp;
        if(sum >= INT_MAX){
            return 0;
        }
        return x>0 ? sum : 0-sum;        
    }    
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    int reverse(int x) {
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        std::reverse(s.begin(),s.end());
        if (s[s.length() - 1] == '-')
            s= '-' + s.substr(0, s.length() - 1);
        ss.clear();
        //stringstream ss2;
        ss << s;
        ss >> x;
        if (x == 0x7fffffff || x == 0x80000000)
            x = 0;
        return x;
    }
};
__________________________________________________________________________________________________
8096 kb
class Solution {
public:
    int reverse(int x) {
        std::ios::sync_with_stdio(NULL);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        long int revNum = 0;
        bool isNeg = x < 0;
        while(x != 0)
        {
            revNum += x % 10;
            x /= 10;
            if(x > 0 || isNeg)
                revNum *= 10;
        }
        if(isNeg)
        {
            revNum /= 10;
        }
        return revNum >= INT_MAX || revNum <= INT_MIN ? 0 : int(revNum);
    }
};
__________________________________________________________________________________________________
8100 kb
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        std::ios::sync_with_stdio(NULL);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        
        constexpr  int max =  INT_MAX / 10;
        constexpr  int min =  INT_MIN / 10;
        
        int r = 0;
        while (x) {
            if ((max < res) || ((max == res) && x > 7) ||
                (res < min) || ((res == min) && x < - 8)) {
                res = 0; x = 0; //*/return 0;
            }
            r = x % 10;
            res = r + 10 * res;
            x /= 10;
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
