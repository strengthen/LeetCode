__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string countOfAtoms(string formula) {
        if (formula.empty()) return formula;
		// used to calculate the count of parentheses
        vector<int> factors{1};
        int fact = 1;
		// number of element
        int num = 0;
		// element name
        string element = "";
		// which digit is this number
        int digit = 1;
		// counts
        map<string, int> cnts;
        for (int i = formula.size() - 1; i >= 0; --i) {
			// if we see a ')', we need to calculate the current count of the parentheses
            if (formula[i] == ')') {
			// if we don't have a numer, then the number is 1
                if (!num) num = 1;
                factors.push_back(num);
                fact *= num;
                num = 0;
                digit = 1;
			// '(' means we are going out one parentheses, lower the counts
            } else if (formula[i] == '(') {
                fact /= factors.back();
                factors.pop_back();
			// if it's a number, we can calculate the current number
            } else if (formula[i] >= '0' && formula[i] <= '9') {
                num += (formula[i] - '0') * digit;
                digit *= 10;
			// if it's a char, means it's part of a element
            } else if (formula[i] >= 'a' && formula[i] <= 'z') {
                element.push_back(formula[i]);
			// Upper case means we have finished reading an element
            } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
				// set num to 1 if there is no number
                if (!num) num = 1;
				// element should be at most 2 chars, num is the current number, fact is the accumulate count of parentheses
                element = string(1, formula[i]) + element;
                cnts[element] += num * fact;
				// ready to record a new element
                element.clear();
				// ready to record a new number
                num = 0;
                digit = 1;
            }
        }
        string res = "";
		// write the result
        for (auto& p : cnts) res += p.first + ((p.second > 1) ? to_string(p.second) : "");
        return res;
    }
};
__________________________________________________________________________________________________
sample 9156 kb submission
class Solution {
public:
    int pos, n;
    string s;
    
    int parseNumber()
    {
        int ans = 0;
        while (pos < n && isdigit(s[pos]))
            ans = ans * 10 + s[pos++] - '0';
        return ans;
    }
    
    string parseName()
    {
        string ans = "";
        ans += s[pos++];
        while (pos < n && islower(s[pos]))
            ans += s[pos++];
        return ans;
    }
    
    string countOfAtoms(string formula) {
        vector<pair<string,int>> v;
        pos = 0;
        n = formula.size();
        s = formula;
        while (pos < n)
        {
            if (s[pos] == '(')
            {
                v.push_back({"(", 0});
                pos++;
            }
            else if (s[pos] == ')')
            {
                pos++;
                int k = 1;
                if (pos < n && isdigit(s[pos]))
                {
                    k = parseNumber();
                }
                for (int i = v.size() - 1; i >= 0; i--)
                {
                    if (v[i].first == "(")
                    {
                        v[i].first = ".";
                        break;
                    }
                    v[i].second *= k;
                }
            }
            else
            {
                string name = parseName();
                int k = 1;
                if (pos < n && isdigit(s[pos]))
                    k = parseNumber();
                v.emplace_back(name, k);
            }
        }
        
        map<string, int> cnt;
        for (auto p : v)
            if (p.first != ".")
                cnt[p.first] += p.second;
        string ans = "";
        for (auto p : cnt)
        {
            ans += p.first;
            if (p.second > 1)
            {
                stringstream ss;
                ss << p.second;
                ans += ss.str();
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
