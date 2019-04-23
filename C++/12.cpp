__________________________________________________________________________________________________
8ms
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();


char * base_10[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
char * base_100[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
char * base_1000[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
char * base_10000[10] = {"","M","MM","MMM","","","","","",""};

class Solution {
public:
    string intToRoman(int num) {
        std::string res;
        int x0 = num%10;
        num /= 10;
        int x1 = num%10;
        num /= 10;
        int x2 = num%10;
        num /= 10;
        int x3 = num;
        res = res + base_10000[x3] + base_1000[x2] + base_100[x1] + base_10[x0];
        return res;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    string intToRoman(int num) 
    {
        string r;
                
        int thousands = num / 1000;
        num %= 1000;
        int hundreds = num / 100;
        num %= 100;
        int tens = num / 10;
        num %= 10;
        int ones = num;
        
        // thousands
        for (int i = 0; i < thousands; i++)
        {
            r += 'M';
        }
        
        // hundreds
        if (hundreds == 9)
        {
            r += "CM";
        }
        else if (hundreds == 4)
        {
            r += "CD";
        }
        else 
        {
            if (hundreds >= 5)
            {
                r += 'D';
                hundreds -= 5;
            }
            for (int i = 0; i < hundreds; i++)
            {
                r += 'C';
            }
        }
        
        // tens
        if (tens == 9)
        {
            r += "XC";
        }
        else if (tens == 4)
        {
            r += "XL";
        }
        else
        {
            if (tens >= 5)
            {
                r += 'L';
                tens -= 5;
            }
            for (int i = 0; i < tens; i++)
            {
                r += 'X';
            }
        }
        
        // ones
        if (ones == 9)
        {
            r += "IX";
        }
        else if (ones == 4)
        {
            r += "IV";
        }
        else
        {
            if (ones >= 5)
            {
                r += 'V';
                ones -= 5;
            }
            for (int i = 0; i < ones; i++)
            {
                r += 'I';
            }
        }
        
        return r;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
8300 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

class Solution {
public:
    string intToRoman (int num)
    {
        string res = "";
        while (num >= 1000) 
        {
            num -= 1000;
            res += ('M');
        }
        if (num >= 900) 
        {
            num -= 900;
            res+= ("CM");
        }
        if (num >= 500)
        {
            num -= 500;
            res+= ('D');
        }
        if (num >= 400) 
        {
            num -= 400;
            res+= ("CD");
        }
        while (num >= 100) 
        {
            num -= 100;
            res+= ('C');
        }
        if (num >= 90)
        {
            num -= 90;
            res+= ("XC");
        }
        if (num >= 50)
        {
            num -= 50;
            res+= ('L');
        }
        if (num >= 40)
        {
            num -= 40;
            res+= ("XL");
        }
        while (num >= 10)
        {
            num -= 10;
            res+= ('X');
        }
        if (num >= 9)
        {
            num -= 9;
            res+= ("IX");
        }
        if (num >= 5) 
        {
            num -= 5;
            res+= ('V');
        }
        if (num >= 4)
        {
            num -= 4;
            res+= ("IV");
        }
        while (num > 0)
        {
            num -= 1;
            res+= ('I');
        }
        return res;
    }
};
__________________________________________________________________________________________________
8328 kb
static int pre = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	string intToRoman(int num) {
		string result;
		if (num >= 1000) {
			int count = num / 1000;
			for (int i = 0; i < count; ++i) {
				result += 'M';
			}
			num %= 1000;
		}

		if (num >= 900) {
			result += "CM";
			num -= 900;
		}
		else if (num >= 500) {
			result += 'D';
			num -= 500;
			int count = num / 100;
			for (int i = 0; i < count; ++i) {
				result += 'C';
			}
			num %= 100;
		}
		else if (num >= 400) {
			result += "CD";
			num -= 400;
		}
		else if (num >= 100) {
			int count = num / 100;
			for (int i = 0; i < count; ++i) {
				result += 'C';
			}
			num %= 100;
		}

		if (num >= 90) {
			result += "XC";
			num -= 90;
		}
		else if (num >= 50) {
			result += 'L';
			num -= 50;
			int count = num / 10;
			for (int i = 0; i < count; ++i) {
				result += 'X';
			}
			num %= 10;
		}
		else if (num >= 40) {
			result += "XL";
			num -= 40;
		}
		else if (num >= 10) {
			int count = num / 10;
			for (int i = 0; i < count; ++i) {
				result += 'X';
			}
			num %= 10;
		}

		if (num == 9) {
			result += "IX";
		}
		else if (num >= 5) {
			result += 'V';
			num -= 5;
			for (int i = 0; i < num; ++i) {
				result += 'I';
			}
		}
		else if (num == 4) {
			result += "IV";
		}
		else {
			for (int i = 0; i < num; ++i) {
				result += 'I';
			}
		}
		return move(result);
	}
};
__________________________________________________________________________________________________
