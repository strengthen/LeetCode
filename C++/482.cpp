__________________________________________________________________________________________________
sample 8 ms submission
static const int _x_ = [] () { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; } ();

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int total = 0;
        for (auto c : S) {
            if (c != '-') {
                ++total;
            }
        }

        int first_segment = total % K;

        string res;
        if (total > 1) {
            res.reserve(total + total / K + (first_segment > 0 ? 0 : -1));
        }

        int i = 0;
        while (first_segment > 0) {
            if (S[i] != '-') {
                res.push_back(toupper(S[i]));
                if (--first_segment == 0 && (total / K) > 0) {
                    res.push_back('-');
                }
            }
            
            ++i;
        }
        
        int written = 0;
        for (i; i < S.size(); ++i) {            
            if (S[i] != '-') {
                if (written > 0 && written % K == 0) {
                    res.push_back('-');
                }
                res.push_back(toupper(S[i]));
                ++written;
            }
        }

        return res;
    }
};
__________________________________________________________________________________________________
sample 10100 kb submission
class Solution {
public:
    char upperCaseChar(char c){
        if(c<='9'&&c>='0') return c;
        if(c>='a'&&c<='z') return c+('A'-'a');
        return c;
    }
    string licenseKeyFormatting(string S, int K) {

        int count_k = 0;
        bool insert_dash = false;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='-'){
                S.erase(S.begin()+i);
            }else{
                count_k++;
                S[i] = upperCaseChar(S[i]);
                if(insert_dash){
                    S.insert(i+1,"-");
                    insert_dash = false;
                }
                if(count_k==K){
                    insert_dash = true;
                    count_k = 0;
                }
            }
        }
       // if(S[0]=='-') S = S.substr(1);
        return S;
    }
};
__________________________________________________________________________________________________
