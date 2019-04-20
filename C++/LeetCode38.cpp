__________________________________________________________________________________________________
4ms
class Solution {
public:
    string countAndSay(int n) {
        int count = 1;
        string tmp, result = "1";
        for (int i = 1; i < n; i++) {
            tmp = result + 'x';
            result = "";
            for (int j = 1; j < tmp.size(); j++) {
                if (tmp[j] == tmp[j - 1]) {
                    count++;
                } else {
                    result += '0' + count;
                    result += tmp[j - 1];
                    count = 1;
                }
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    string countAndSay(int n) {
        if (n<1) return "";
        string res = "1";
        while(--n)
        {
            string cur = "";
            for (int i = 0; i < res.size(); i++)
            {
                int cnt = 1;
                while(i+1 < res.size() && res[i] == res[i+1])
                {
                    cnt++;
                    i++;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    string countAndSay(int n) {
        int count = 1;
        string result = "1x";
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    result.replace(j - count, count - 1, 1, '0' + count);
                    j -= count - 2;
                    count = 1;
                }
            }
        }
        
        result.resize(result.size() - 1);
        return result;
    }
};
__________________________________________________________________________________________________
8512 kb
class Solution {
public:
    string countAndSay(int n) {
        string start="1";
        int k=1;
        while(k<n)
        {
            string tem="";
            char temc=start[0];
            int count=1;
            for(int i=1;i<start.size();i++)
            {
                if(start[i]==temc)
                {
                    count++;
                }
                if(start[i]!=temc)
                {
                    tem.push_back(count+'0');
                    tem.push_back(temc);
                    temc=start[i];
                    count=1;
                }
            }
            tem.push_back(count+'0');
            tem.push_back(temc);
            start=tem;
            k++;
        }
        return start;
    }
};
__________________________________________________________________________________________________
8524 kb
class Solution {
public:
    string countAndSay(int n) {
        string prestr = "1";
        string str;
        if (n == 1) return prestr;
        for (int i=2; i <= n; i++){
            int count = 0;
            for (int j = 0; j < prestr.size(); j++){
                count++;
                if (j+1 < prestr.size() && prestr[j] == prestr[j+1])    continue;
                str.push_back('0' + count);
                str.push_back(prestr[j]);
                count = 0;
            }
            prestr = str;
            str.clear();
        }
        
        return prestr;
    }
};
__________________________________________________________________________________________________