__________________________________________________________________________________________________
sample 4 ms submission
#define V std::vector

class Solution {
public:
    void collect(   std::vector<int>& num,
                    std::vector<int>& op,
                    std::vector<bool>& taken,
                    std::vector<int>& results,
                    int at,
                    std::set<int>& collection )
    {
        
    }
    
    vector<int> diffWaysToCompute(string input) {
        
        std::vector<int> num;
        std::vector<int> op;
        
        auto isNum = [](char c) { return c>='0'&&c<='9'; };
        auto isOp = [](char c) { return (c=='+')||(c=='-')||(c=='*'); };
        
        const auto* p = input.c_str();
        
        auto getNum = [&p,&isNum]
        {
            int n = {};
            while(*p && isNum(*p)) { n*=10; n+=((*p)-'0'); ++p; }
            return n;
        };
        
        while(*p)
        {
            if(isNum(*p)) num.push_back(getNum());
            else if(isOp(*p)) { op.push_back(*p); ++p; }
            else ++p;
        }
        
        auto nN = num.size();
        auto nO = op.size();
        
        if(nN == 0) return {};
        if(nN == 1) return { num[0] };
        if(nN != nO+1) return {};
        
        // can we do ground up?
        
        auto getVal = [](int a, int b, char op)
        {
            if(op=='+') return a+b;
            if(op=='-') return a-b;
            return a*b;
        };
        
        auto v0 = getVal(num[0], num[1], op[0]);        
        if(nN == 2) return { v0 };
        
        V<V<V<int>>> all(nN,V<V<int>>(nN));
        
        for(int aa = 0; aa < nN; ++aa) all[aa][aa].push_back(num[aa]);
        
        all[0][1].push_back(v0);
        
        for(int aa = 1; aa < nN-1; ++aa)
            all[aa][aa+1].push_back(getVal(num[aa], num[aa+1], op[aa]));
        
        for(int len = 3; len <= nN; ++len)
        {
            for(int from = 0; from <= nN-len; ++from)
            {
                int to = from + len - 1;
                
                auto& s = all[from][to];
                
                for(int opAt = from; opAt < to; ++opAt)
                {
                    auto& s1 = all[from][opAt];
                    auto& s2 = all[opAt+1][to];
                    
                    for(auto v1 : s1) for(auto v2 : s2)
                    {
                        s.push_back(getVal(v1, v2, op[opAt]));
                    }
                }
            }
        }
        
        return all[0][nN-1];
    }
};
__________________________________________________________________________________________________
sample 8844 kb submission
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> data;
        vector<char> ops;
        int num = 0;
        char op = ' ';
        istringstream ss(input + "+");
        while(ss >> num && ss >> op) {
            data.push_back(num);
            ops.push_back(op);
        }
        int size = data.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>()));
        for(int i=size-1;i>=0;i--){
            dp[i][i].push_back(data[i]);
            for(int j=i+1;j<size;j++){//calculate dp[i][j] = f(dp[i][i], dp[i+1][j]) + f(dp[i][i+1], dp[i+2][j]) + ... + f(dp[i][j-1], dp[j][j]);
                for(int k=i;k<j;k++){
                    for(auto m:dp[i][k])
                        for(auto n:dp[k+1][j]){
                            if(ops[k]=='+')
                                dp[i][j].push_back(m+n);
                            else if(ops[k]=='-')
                                dp[i][j].push_back(m-n);
                            else
                                dp[i][j].push_back(m*n);
                        }
                }
            }
        }
        return dp[0][size-1];
    }
};
__________________________________________________________________________________________________
