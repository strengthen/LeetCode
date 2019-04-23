__________________________________________________________________________________________________
8ms
class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
    
    // skip the whilespaces
    for(; s[i] == ' '; i++) {}
    
    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
    
    int n_nm, n_pt;
    for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        s[i] == '.' ? n_pt++:n_nm++;       
    if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;
    
    // check the exponent if exist
    if(s[i] == 'e') {
        i++;
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign
        
        int n_nm = 0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }
    
    // skip the trailing whitespaces
    for(; s[i] == ' '; i++) {}
    
    return i == s.size();  // must reach the ending 0 of the string
    }
};
__________________________________________________________________________________________________
4ms
static int fast_io__ = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
    class input {
    public:
        input(string const& s)
            : begin(s.begin()),
              end(s.end()),
              pos(s.begin()),
              eof(false)
        {}
        
        char get() {
            if (pos == end) {
                eof = true;
                return '\0';
            }
            return *pos++;
        }
        
        void unget() {
            if (pos != begin && !eof) {
                --pos;
            }
        }
    
    private:
        string::const_iterator begin;
        string::const_iterator end;
        string::const_iterator pos;
        bool eof;
    };

private:
    void skipWhitespaces(input& in) {
        while (in.get() == ' ') {
        }
        in.unget();
    }
    
    bool mayMatchNumber(input& in) {
        bool matched = false;
        while (isdigit(in.get())) {
            matched = true;
        }
        in.unget();
        return matched;
    }
    
    bool mayHaveChar(input& in, char c) {
        if (in.get() == c) {
            return true;
        }
        in.unget();
        return false;
    }
    
    bool mayHaveSing(input& in) {
        auto c = in.get();
        if (c == '-' || c == '+') {
            return true;
        }
        in.unget();
        return false;
    }
    
public:
    bool isNumber(string& s) {
        auto in = input(s);
        
        skipWhitespaces(in);
        mayHaveSing(in);
        auto matched = mayMatchNumber(in);
        if (mayHaveChar(in, '.')) {
            matched |= mayMatchNumber(in);
        }
        if (!matched) {
            return false;
        }
        
        if (mayHaveChar(in, 'e')) {
            mayHaveSing(in);
            auto matched = mayMatchNumber(in);
            if (!matched) {
                return false;
            }
        }
        
        skipWhitespaces(in);
        return in.get() == '\0';
    }
};
__________________________________________________________________________________________________
8292 kb 
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
	bool isNumber(string s) {
		trim(s);
		if (s.length() == 0 ) return false;
		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
			case '-':
			case '+':
				if (!isValidSign(s, i)) return false;
				break;

			case 'e':
				if (!isValidExponent(s, i)) return false;
				break;

			case '.':
				if (!isValidPoint(s, i)) return false;
				break;
			default:
				if (!is_num(s[i])) return false;
				break;
			}
		}

		return true;
	}

private:
	//去除两端的空格
	void trim(string &s) {
		int i = 0;
		int j = s.length() - 1;
		while (i < j)
		{
			if (s[i] != ' ' && s[j] != ' ') break;
			i = s[i] == ' ' ? i + 1 : i;
			j = s[j] == ' ' ? j - 1 : j;
		}
		s = s.substr(i, j - i + 1);
	}

	//是否为合法的e
	bool isValidExponent(string &s, int &i) {
		if (i == 0 || i == s.length() - 1) return false;
		if (s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == '.') return false;	//如果e的前面不是数字，都要排除
		int j = ((s[i + 1] == '+' || s[i + 1] == '-') && i + 1 < s.length() - 1) ? i + 2 : i + 1;
		for (; j < s.length(); j++)
			if (!is_num(s[j])) return false;

		i = j;
		return true;
	}

	//是否为合法的符号
	bool isValidSign(string &s, int &i) {
		if (i == s.length() - 1) return false;
		if (i > 0 && s[i - 1] != 'e') return false;
		return true;
	}

	//是否为合法的小数点
	bool isValidPoint(string &s, int &i) {
		if (i == s.length() - 1) {
			if (i - 1 >= 0 && s[i - 1] >= 47 && s[i - 1] <= 57) return true;
			return false;
		}
        if (i == 0 && !is_num(s[i + 1])) return false;
		//检查小数点后面的内容是否合法
		int j = i + 2;
		if (s[i + 1] == 'e') {
			if (i + 2 >= s.length()) return false;
		}
		else if (!is_num(s[i + 1])) return false;
		
		for (; j < s.length(); j++) {
			switch (s[j])
			{
				case '-':
				case '+':
					if (!isValidSign(s, j)) return false;
					break;

				case 'e':
					if (!isValidExponent(s, j)) return false;
					break;
				default:
					if (!is_num(s[j])) return false;
					break;
			}
		}
		i = j;
		return true;
	}

	bool is_num(char c) {
		int tmp = (int)c;
		return (tmp >= 47 && tmp <= 57);
	}
};