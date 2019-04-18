__________________________________________________________________________________________________
8ms
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0; 
}();


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                // j = k * (2 * numRows - 2)
                ret += s[j+i];  // k * (2 * numRows - 2) + i
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];  // (k + 1) * (2 * numRows - 2) - i
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int len = s.length();
        int step = 2*(numRows-1);
        int counter = 0;
        int j;
        if (step==0) {
            return s;
        }
        for (int i=0; i<numRows; ++i) {
            j = i;
            int nowSteps = 2*i;
            while (j<len) {
                result.append(1,s[j]);
                if ((step-nowSteps)!=0&&nowSteps!=0) {
                    j = j+step-nowSteps;
                    nowSteps = step-nowSteps;
                }
                else {
                    j = j+step;
                }
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    string convert(string s, int numRows) {
        vector <string> v(min(numRows, int(s.size())));
    if (numRows == 1) return s;
     bool down = false;
     int row = 0;
     for (char c : s) {
         v[row] +=c;
         if (row == 0 || row == numRows -1) down = !down;
          row += down? 1: -1;
     }
     string str;
     for (string v1 : v )
         str +=v1;
    return str;
    }
};
__________________________________________________________________________________________________
10192 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
class Solution {
public:
     string convert(string s, int nRows) {
        if(nRows == 1)return s;
        int len = s.size(), k = 0, interval = (nRows<<1)-2;
        string res(len, ' ');
        for(int j = 0; j < len ; j += interval)//处理第一行
            res[k++] = s[j];
        for(int i = 1; i < nRows-1; i++)//处理中间行
        {
            int inter = (i<<1); //inter == 2i;
            for(int j = i; j < len; j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        for(int j = nRows-1; j < len ; j += interval)//处理最后一行
            res[k++] = s[j];
        return res;
    }
};
__________________________________________________________________________________________________
12660 kb
class Solution {
public:
    string convert(const string &s, int numRows) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(numRows == 1)
            return s;
        int count = 0, m = 0;
        vector<string> row(min(numRows,int(s.size()))); 
        while(count<s.size()) {
            while(m < numRows && count<s.size()) {
                row[m++].push_back(s[count++]); 
            }
            m -= 2;
            while(m >= 0 && count<s.size()) {
                row[m--].push_back(s[count++]); 
            }
            m += 2;            
        }
        string res;
        for(auto &str : row) {
            res += str;
        }
        return res;
    }
};
__________________________________________________________________________________________________
