__________________________________________________________________________________________________
sample 4 ms submission

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result;
        int N1, N2;
        string c1, c2;
        if (A >= B) {
            N1 = A;
            N2 = B;
            c1 = "a";
            c2 = "b";
        }
        else {
            N1 = B;
            N2 = A;
            c1 = "b";
            c2 = "a";
        }

        if (N1 - 2 >= N2) {
            result = result + c1 + c1;
            N1 -= 2;
        }
        
        while (N1 != 0 && N2 != 0) {
            if (N1 > N2) {
                result += c2 + c1 + c1;
                N1 -= 2;
                N2 -= 1;
            }
            else {
                result += c2 + c1;
                N1 -= 1;
                N2 -= 1;
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
sample 8552 kb submission
static const auto _____ = []() { ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ret;
        ret.reserve(A + B);
        
        int last_a_count = 0;
        int last_b_count = 0;
        while(A+B > 0)
        {
            if((A > B || last_b_count == 2) && last_a_count != 2)
            {
                ret.push_back('a');
                A--;
                last_b_count = 0;
                last_a_count++;
            }
            else
            {
                ret.push_back('b');
                B--;
                last_b_count++;
                last_a_count = 0;
            }
        }
        return ret; 
    }
};
__________________________________________________________________________________________________
