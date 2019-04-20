__________________________________________________________________________________________________
4ms
static int lambda = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string multiply(string num1, string num2) {
        int s1 = num1.size(), s2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        string result(s1+s2, '0');
        //int offset = 0;
        for (int i = 0; i < s1; ++i) {
            int sum = 0;
            carry = 0;
            int d1 = num1.at(i) - '0';
            for (int j = 0; j < s2 ; ++j) {
                int d2 = num2.at(j) - '0';
                int d3 = result[i + j] - '0';
                sum = (d1*d2 + d3 + carry)%10;
                carry = (d1*d2 + d3 + carry)/10;
                result[i + j] = '0' + sum;
            }
            result[i + s2] += carry;
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            ++i;
        }
        return i == result.size() ? "0" : result.substr(i, result.size());
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int length = m+n;
        int mult,tmp_p = length-1, p;
        string res;
        vector<int> res_v(length,0);
        for (int i = m-1; i >= 0; i--){
            p = tmp_p--;
            for (int j = n-1; j >= 0; j--){
                mult = (num1[i]-'0')*(num2[j]-'0');
                res_v[p-1] += (res_v[p] + mult)/10;
                res_v[p] = (res_v[p] + mult)%10;
                p--;
            }
        }
        bool first = true;
        for (int num:res_v){
            if(num == 0 && first){
                continue;
            }
            first = false;
            res+=(num+'0');
        }
        if (res == "")  res = "0";
        return res;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string s = "";
        int n1 = num1.size(), n2 = num2.size();
        int n = n1 + n2 - 1;
        vector<int> process (n, 0);
        for(int i = 0; i < n2; i++){
            for(int j = 0; j < n1; j++){
                process[i + j] += char2Int(num2[i]) * char2Int(num1[j]);
            }
        }
        int carry = 0;
        for(int i = n - 1; i >= 0; i--){
            int sum = process[i] + carry;
            process[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry) s += to_string(carry);
        for(auto c : process) s += to_string(c);
        return s;
    }
    int char2Int(char c){
        return c - ('0' - 0);
    }
};
__________________________________________________________________________________________________
10176 kb
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res(n1+n2, '0');
        if(n1==0||n2==0) return "";
        for(int i = n1-1;i>=0;i--){
            int add = 0;
            for(int j = n2-1;j>=0;j--){
                int mul = (num1[i]-'0')*(num2[j] -'0');
                int sum = res[i+j+1] + add + mul%10-'0';
                res[i+j+1]='0'+sum%10;
                add=mul/10+sum/10;
            }
            res[i]+=add;
        }
        for(int i=0;i<n1+n2;i++)
            if(res[i]!='0')
                 return res.substr(i);
         return "0";
    }
};
__________________________________________________________________________________________________
10180 kb
class Solution {
public:
    string multiply(string num1, string num2) {
        
        string sum(num1.size() + num2.size()  , '0');
        
        for(int i = num1.size() - 1 ; i>= 0 ;i--){
            int carry = 0;
            for(int j = num2.size() - 1 ; j >= 0; j--){
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                 carry = tmp / 10;
            }
            sum[i] += carry;
            
        }
        size_t startpos = sum.find_first_not_of('0');
        if(string :: npos != startpos){
            return sum.substr(startpos);
        }
        return "0";
    }
};
__________________________________________________________________________________________________