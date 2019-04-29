__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isRationalEqual(string S, string T) {
        return f(S) == f(T);
    }

    double f(string S) {
        auto i = S.find("(");
        if (i != string::npos) {
            string base = S.substr(0, i);
            string rep = S.substr(i + 1, S.length() - i - 2);
            for (int j = 0; j < 20; ++j) base += rep;
            return stod(base);
        }
        return stod(S);
    }
};
__________________________________________________________________________________________________
sample 8344 kb submission
class Solution {
public:
long long __gcd(long long a, long long b) {
    if (a < b) {
        return __gcd(b, a);
    }
    return b == 0 ? a : __gcd(b, a%b);
}

long long digMul(long long r) {
    long long mul = 1;
    while (r > 0) {
        mul *= 10;
        r /= 10;
    }
    return mul;
}

pair<long long, long long> convS(string s) {
    int n = s.length();
    int iP = -1, iS = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            iP = i;
        } else if (s[i] == '(') {
            iS = i;
        }
    }
    if (iP == -1) {
        return {stoi(s), 1};
    }
    long long intPart = stoi(s.substr(0, iP));
    long long nonRepPart = iS == iP+1 || iS == n-1 ? 0 : stoi(s.substr(iP + 1, iS - iP -1));
    string repPart = iS == n ? "0" : s.substr(iS + 1, n - iS - 2);

    long long num = intPart, den = 1;
    if (nonRepPart != 0) {
        long long mul = digMul(nonRepPart);
        num = mul*num + nonRepPart;
        den = mul;
    }

    if (repPart != "0") {
        long long mul = 1;
        for (int i = 0; i < repPart.length(); i++) {
            mul *= 10;
        }
        num = num * mul + stoi(repPart) - num;
        den *= (mul - 1);
    }

    long long d = __gcd(num, den);
    return {num/d, den/d};
}

bool isRationalEqual(string s1, string s2) {
    return convS(s1) == convS(s2);
}

};
__________________________________________________________________________________________________
