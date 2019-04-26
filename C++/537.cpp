__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int plus1 = a.find('+'), end1 = a.find('i');
        int x1 = stoi(a.substr(0, plus1)), y1 = stoi(a.substr(plus1 + 1, end1 - plus1 - 1));
        int plus2 = b.find('+'), end2 = b.find('i');
        int x2 = stoi(b.substr(0, plus2)), y2 = stoi(b.substr(plus2 + 1, end2 - plus2 - 1));
        int x3 = x1 * x2 + y1 * y2 * -1, y3 = x1 * y2 + x2 * y1;
        return to_string(x3) + '+' + to_string(y3) + 'i';
    }
};
__________________________________________________________________________________________________
sample 8224 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

#include <complex>

class Solution {
public:
    std::string complexNumberMultiply(
        const std::string& a, const std::string& b) {
        const std::complex<int> c_a = parse(a);
        const std::complex<int> c_b = parse(b);
        const std::complex<int> c_r = c_a * c_b;
        return format(c_r);
    }

private:
    std::complex<int> parse(const std::string& a) {
        std::istringstream ss(a);
        int real;
        int imag;
        char ch;
        ss >> real >> ch >> imag >> ch;
        return std::complex(real, imag);
    }
    
    std::string format(std::complex<int> c) {
        std::ostringstream os;
        os << c.real() << '+' << c.imag() << 'i';
        return os.str();
    }
};
__________________________________________________________________________________________________
