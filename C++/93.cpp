__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty() || s.size() > 12 || s.size() < 4 ) return {};
        
        vector<string> res;
        restore(s, 0, "", res);
        return res;
    }
    
    void restore(string s, int n, string out, vector<string>& res) {
        //cout << "n = " << n << "\n";
        if (n == 4) {
            if (s.empty()) res.push_back(out);
            return;
        }
        
        for (int i = 1; i < 4; ++i) {
            if (s.size() >= i && valid(s.substr(0, i))) {
                string temp = out + s.substr(0, i) + ((n==3) ? "" : ".");
                //cout << " out = " << out << "\n";
                restore(s.substr(i), n+1, temp, res);
            }
        }
    }
    
    bool valid(string s) {
        if (s.empty() || s.size() > 4 || (s.size() > 1 && s[0] == '0')) return false;
        int num = stoi(s);
        return num <= 255 && num >= 0;
    }    
};
__________________________________________________________________________________________________
8248 kb
class Solution {
  public:
    std::vector<std::string> restoreIpAddresses(std::string s) { return compute(s); }

    static constexpr char DOT = '.';
    static constexpr char ZERO = '0';
    using value_type = std::array<int, 4>;

    std::string getIpAddress(const std::string &s, const int x, const int y, const int z, const int h) {
        std::string ip;
        const char *ptr = s.data();

        // Add the first range
        ip.append(ptr, x);
        ptr += x;
        ip.push_back(DOT);

        // Add the second range
        ip.append(ptr, y);
        ip.push_back(DOT);
        ptr += y;

        // Add the third range
        ip.append(ptr, z);
        ip.push_back(DOT);
        ptr += z;

        // Add the fourth range.
        ip.append(ptr, h);

        return ip;
    }

    int char2num(const char *ptr, const int N) {
        if (N == 1) { return *ptr - ZERO; }
        if (N == 2) return (*ptr - ZERO) * 10 + *(ptr + 1) - ZERO;
        return ((*ptr - ZERO) * 10 + *(ptr + 1) - ZERO) * 10 + *(ptr + 2) - ZERO;
    }
    
        std::vector<std::string> compute(const std::string &s) {
        const int N = s.size();
        const char *data = s.data();
        std::vector<std::string> results;
        if ((N > 12) || (N < 4)) return results;
        const int xmax = (*data == ZERO) ? 1 : std::min(N - 3, 3);
        for (int x = 1; x <= xmax; ++x) {
            if (char2num(data, x) > 255) continue;
            const int ymax = (*(data + x) == ZERO) ? 1 : std::min(N - x - 2, 3);
            for (int y = 1; y <= ymax; ++y) {
                if (char2num(data + x, y) > 255) continue;
                const int zmax = (*(data + x + y) == ZERO) ? 1 : std::min(N - x - y - 1, 3);
                for (int z = 1; z <= zmax; ++z) {
                    if (char2num(data + x + y, z) > 255) continue;
                    const int h = N - x - y - z;
                    if ((h < 1) || (h > 3)) continue;
                    if ((*(data + x + y + z) == ZERO) && (h > 1)) continue;
                    if (char2num(data + x + y + z, h) > 255) continue;
                    results.push_back(getIpAddress(s, x, y, z, h));
                }
            }
        }

        return results;
    }
};
__________________________________________________________________________________________________
