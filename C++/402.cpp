__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(int i = 0; i < num.size(); ++i){
            while(k > 0 && res.size() > 0 && res.back() > num[i]) {
                res.pop_back();
                --k;
            }
            res.push_back(num[i]);
        }
        for(int i = 0; i < k; ++i) res.pop_back();
        int p = res.size();
        for(int i = 0; i < res.size(); ++i) {
            if('0' != res[i]) {
                p = i; break;
            }
        }
        res = res.substr(p);
        if(0 == res.size()) res = "0";
        return res;
    }
};
__________________________________________________________________________________________________
sample 9092 kb submission
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.length())    return "0";
        for(int i=0;i<k;i++){
            int j=0;
            while(num[j]=='0' && j<num.length())  {
                num.erase(j,1);
            }
            int m=num.length();
            for(int j = 1;j<num.length();j++){
                if(num[j]<num[j-1]) {
                    num.erase(j-1,1);
                    //m=j;
                    break;
                }
            }
            if(m==num.length()) num.erase(num.length()-1,1);
        }
        int j=0;
        while(num[j]=='0' && j<num.length())  {
            num.erase(j,1);
        }
        if(num=="")    return "0";
        return num;
    }
};
__________________________________________________________________________________________________
