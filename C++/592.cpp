__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
int GCD(int a, int b ){ return (b == 0) ? a : GCD(b, a % b); }
string fractionAddition(string s) {
    int n = 0, d = 1, p = 0, p1 = 0, p2 = 0;
    if (s[0] != '-') s = "+" + s;
    while (p < s.size()) {
        for (p1 = p + 1; s[p1] != '/'; ++p1);
        for (p2 = p1 + 1; p2 < s.size() && s[p2] != '+' && s[p2] != '-'; ++p2);
        auto nn = stoi(s.substr(p + 1, p1 - p - 1)), dd = stoi(s.substr(p1 + 1, p2 - p1 - 1));
        auto gcd = GCD(d, dd);
        n = n * dd / gcd + (s[p] == '-' ? -1 : 1) * nn * d / gcd;
        d *= dd / gcd;
        p = p2;
    }    
    auto gcd = GCD(abs(n), d);
    return to_string(n / gcd) + "/" + to_string(d / gcd);
}
};
__________________________________________________________________________________________________
sample 8788 kb submission
class Solution {
public:

int findgcd(int a, int b) {
    if(b == 0) return a;
    return findgcd(b, a%b);
}
void add(int& a, int& b, int c, int d) {
    int nume = a*d + c*b, deno = b*d;
    int gcd = findgcd(abs(nume), abs(deno));
    a = nume / gcd;
    b = deno / gcd;
}
string fractionAddition(string expression) {
    stringstream ss(expression);
    char op;
    int a, b, c, d;
    ss >> a; 
    ss >> op; 
    ss >> b;
    while(ss >> c) {
        ss >> op; 
        ss >> d;
        add(a, b, c, d);
    }
    return to_string(a) + "/" + to_string(b);
}

};
__________________________________________________________________________________________________
