__________________________________________________________________________________________________
4ms
class Solution {
public:
    static inline int sumBinary(int a, int b) {
        return (a+b)%2;
    }
    static inline int sumBinary3(int a, int b, int c) {
        return sumBinary(a, sumBinary(b, c));
    }
    static inline int carryBinary(int a, int b) {
        return (a+b)/2;
    }
    static inline int carryBinary3(int a, int b, int c) {
        return carryBinary(a, b) || carryBinary(b, c) || carryBinary(a, c);
    }
    static inline void maxMin(string* a, string* b) {
        if((*b).length() > (*a).length()) {
            string temp = *a;
            *a = *b;
            *b = temp;
        }
    }
    string addBinary(string a, string b) {
        maxMin(&a, &b);
        int carry = 0;
        int i,j;
        for(i=a.length()-1, j=b.length()-1; i>=0 && j>=0; --i, --j) {
            int c = carryBinary3((a[i]-'0'), (b[j]-'0'), carry);
            a[i] = sumBinary3((a[i]-'0'), (b[j]-'0'), carry) + '0';
            carry = c;
        }
        if(carry == 1 && i==-1)
            a = "1" + a;
        else if(carry == 1) {
            for(;i>=0; --i) {
                int c = carryBinary((a[i]-'0'), carry);
                a[i] = sumBinary((a[i]-'0'), carry) + '0';
                carry = c;
            }
            if(carry == 1) {
                a = "1" + a;
            }
        }
        return a;
    }
};
__________________________________________________________________________________________________
8228 kb
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);
        string res(a.size() + 1, '0');
        int idx1 = a.size() - 1, idx2 = b.size() - 1, carry = 0;
        while(idx1 >= 0){
            // cout << carry << endl;
            if(idx2 < 0){
                carry = (a[idx1] - '0') + carry;
                res[idx1 + 1] = carry%2 == 1? '1' : '0';
                carry >>= 1;
                --idx1;
            }else{
                carry = (a[idx1] - '0') + carry + (b[idx2] - '0');
                res[idx1 + 1] = carry%2 == 1? '1': '0';
                carry >>= 1;
                --idx1;
                --idx2;
            }
        }
        if(carry == 1){
            res[0] = '1';
            return res;
        }else{
            return res.substr(1);
        }
    }
};
__________________________________________________________________________________________________
