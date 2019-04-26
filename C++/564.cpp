__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string nearestPalindromic(string n) {
        vector<long long int>cand;
        string tmp;
        long nn = mystoi(n);
        int end = (n.size() - 1) / 2, len = n.size();
        for(int i = 0; i <= end; ++i)
            tmp += n[i];
        if(n.size() & 1) end = (n.size() - 1) / 2 - 1;
        for(int i = end; i >= 0; --i)
            tmp += n[i];
        if(tmp != n) cand.push_back(mystoi(tmp));
        if(tmp.size() & 1) {
            int tlen = tmp.size();
            if(tmp[tlen / 2] < '9' ) {
                long long int res = 0;
                for(int i = 0; i < tlen / 2; ++i)
                    res = res * 10 + (tmp[i] - '0');
                res = res * 10 + (tmp[tlen / 2] - '0' + 1);
                for(int i = tlen / 2 + 1; i < tlen; ++i)
                    res = res * 10 + (tmp[i] - '0');
                cand.push_back(res);
            }
            if(tmp[tlen / 2] > '0') {
                long res = 0;
                for(int i = 0; i < tlen / 2; ++i)
                    res = res * 10 + (tmp[i] - '0');
                res = res * 10 + (tmp[tlen / 2] - '0' - 1);
                for(int i = tlen / 2 + 1; i < tlen; ++i)
                    res = res * 10 + (tmp[i] - '0');
                cand.push_back(res);
            }
        } else {
            int tlen = tmp.size();
            if(tmp[tlen / 2 - 1] < '9' ) {
                long res = 0;
                for(int i = 0; i < tlen / 2; ++i)
                    res = res * 10 + (tmp[i] - '0');
                res++;
                long tmp = res;
                while(tmp > 0) {
                    res = res * 10 + (tmp % 10);
                    tmp /= 10;
                }
                cand.push_back(res);
            }
            if(tmp[tlen / 2 - 1] > '0') {
                long res = 0;
                for(int i = 0; i < tlen / 2; ++i)
                    res = res * 10 + (tmp[i] - '0');
                res--;
                long tmp = res;
                while(tmp > 0) {
                    res = res * 10 + (tmp % 10);
                    tmp /= 10;
                }
                cand.push_back(res);
            }
        }
        
        tmp = "1";
        for(int i = 0; i < len - 1; ++i)
            tmp += "0";
        tmp += "1";
        cand.push_back(mystoi(tmp));
        
        tmp = "";
        for(int i = 0; i < len - 1; ++i)
            tmp += "9";
        if(tmp != "") cand.push_back(mystoi(tmp));
        
        long long int mn = 1e9;
        long long int ans;
        for(int i = 0; i < cand.size(); ++i)
            if(abs(nn - cand[i]) < mn) {
                mn = abs(nn - cand[i]);
                ans = cand[i];
            } else if(abs(nn - cand[i]) == mn) {
                ans = min(ans, cand[i]);
            }
        return to_string(ans);
    }
    
    long mystoi(string s) {
        long res = 0;
        for(int i = 0; i < s.size(); ++i) {
            res  = res * 10 + (s[i] - '0');
        }
        return res;
    }    
};
__________________________________________________________________________________________________
sample 9404 kb submission
class Solution {
public:
    string nearestPalindromic(string n) {
        if (n == "1") return "0";
        
        string a = mirroring(n);
        uint64_t diff1 = std::llabs(stoull(n) - stoull(a));
        if (not diff1) diff1 = LLONG_MAX;
        
        string s = n;
        int64_t i = (s.size() - 1) / 2;
        while (i >= 0 and s[i] == '0') {
            s[i--] = '9';
        }
        if (i == 0 && s[i] == '1') {
            s = s.substr(1);
            int mid = (s.size() - 1) / 2;
            s[mid] = '9';
        } else {
            s[i] = s[i] - 1;
        }
        string b = mirroring(s);
        uint64_t diff2 = std::llabs(stoull(n) - stoull(b));
        
        s = n;
        i = (s.size() - 1) / 2;
        while (i >= 0 and s[i] == '9') {
            s[i--] = '0';
        }
        if (i < 0) {
            s.insert(0, 1, '1');
        } else {
            s[i] = s[i] + 1;
        }
        string c = mirroring(s);
        uint64_t diff3 = std::llabs(stoull(n) - stoull(c));
        
        uint64_t aa = stoull(a), bb = stoull(b), cc = stoull(c);
        if (diff1 == diff2 and diff1 <= diff3) return aa < bb ? a : b;
        if (diff1 == diff3 and diff1 <= diff2) return aa < cc ? a : c;
        if (diff2 == diff3 and diff2 <= diff1) return bb < cc ? b : c;
        
        if (diff1 <= diff3 and diff1 <= diff2) return a;
        if (diff2 <= diff1 and diff2 <= diff3) return b;
        return c;
    }
    
    string mirroring(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            s[s.size() - i - 1] = s[i];
        }
        return s;
    }
};
__________________________________________________________________________________________________
