__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
      if (N < 10) return N;
      vector<int> digits;
      int last = 9, i = 0, cur, idx = -1, n = N;
      while (n) {
        cur = n % 10;
        digits.push_back(cur);
        n /= 10;
        if (cur > last) idx = i;
        last = cur; i++;
      }
      if (idx == -1) return N;
     // cout << idx << endl;
      i = idx + 1;
      while (i < digits.size() && digits[i] == digits[i - 1]) i++;
      if (i == digits.size() || digits[i] < digits[i - 1]) i--;
     // cout << i  << endl;
      digits[i]--;
      int res = 0, mult = 1;
      for (int j = 0; j < i; j++) {
        res += 9 * mult;
        mult *= 10;
      }
      for (;i < digits.size(); i++) {
        res += digits[i] * mult;
        mult *= 10;
      }
      return res;
    }
};
__________________________________________________________________________________________________
sample 9904 kb submission
 class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N<10)
            return N;
        string str = to_string(N);
        int i;
        for(i=0; i<str.size()-1; ++i)
        {
            if(str[i]>str[i+1])
                break;
        }
        if(i==str.size()-1)
            return N;
        while(i>0 && str[i]==str[i-1])
            --i;
        --str[i];
        for(++i; i<str.size(); ++i)
            str[i]='9';
        return stoi(str);
    }
};
__________________________________________________________________________________________________
