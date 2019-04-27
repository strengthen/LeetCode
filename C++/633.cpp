__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c <2 ) return true;
        int tryTill = ceil(sqrt(c));
        // std::cout << "---------------------------\n";
        // std::cout << "For C= " << c <<" we will TryTill " << tryTill << "\n";
        
        // Perfect squares are always true 0*0 + sqrt(c)*sqrt(c)
        if (c%tryTill == 0 && c/tryTill == tryTill) { 
            // std::cout << "Perfect Square \n"; 
            return true; 
        }
        
        for (int i = 1; i < tryTill; ++ i) {
            int diff = c - (i*i);
            if (diff < 0) {
                // std::cout << "overshot, not true\n";
                return false;
            }
            int sqrtDiff = sqrt(diff);
            
            //if (static_cast<int>(ceil(sqrtDiff)) == static_cast<int>(sqrtDiff))  
            //{ 
            //    std::cout << "a = " << i <<  " b = " << diff << ", sqrtDiff: " << sqrtDiff << ", ceil: " << static_cast<int>(ceil(sqrtDiff)) << ", int cast: " << static_cast<int>(sqrtDiff) << "\n";    
            //    return true;
            //}
            if (diff == (sqrtDiff*sqrtDiff)) return true;
        }
        // std::cout << "out of bounds\n";
        return false;
        
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = sqrt(c); i >= 0; --i) {
            if (i * i == c) return true;
            int d = c - i * i, t = sqrt(d);
            if (t * t == d) return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 8608 kb submission
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0, b=(int)sqrt(c);
        while(a<=b){
            if((long)(a*a)+(long)(b*b)==c) return true;
            else if((long)(a*a)+(long)(b*b)<c) a++;
            else b--;
        }
        return false;
    }
};