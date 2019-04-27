__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string makeLargestSpecial(string S) {
        // like finding and reordering parenthesis sequences, recursively
        if (S.empty()) return "";

        vector<string> sv;
        int cnt = 0, i = 0;
        for (int j = 0; j < S.size(); j++) {
            if (S[j] == '1') cnt++;
            else cnt--;

            if (cnt == 0) {
                string s = '1' + makeLargestSpecial(S.substr(i+1, j-i-1)) + '0';
                sv.push_back(s);
                i = j+1;
            }
        }
        sort(sv.begin(), sv.end(), greater<string>());

        string res = "";
        for (auto &s : sv) res += s;
        return res;
    }
};
__________________________________________________________________________________________________
sample 8668 kb submission
class Solution {
	using uint = unsigned long long;
public:
	uint table[64];
	uint size ;
	string makeLargestSpecial(string S) {
		table[1] = 1;
		for (int i = 2; i < 64; i++)
			table[i] = (table[i - 1] << 1) + 1;
		uint s = transform(S);
		size = S.size();
		uint max = s;	
		while (1)
		{
			s = max;
			int flag = 0;
			for (int i = 0; i + 1 < size; i++)
			{
				auto val = s & (uint(1) << size - i - 1);
				if (!val)
					continue;
				int cnt = 0;
				for (int j = i + 1; j < size; j++)
				{
					auto val = s & (uint(1) << size - j);
					if (val)
						cnt++;
					else
					{
						if (--cnt < 0)
							break;
					}
					val = s & (uint(1) << size - j - 1);
					if (!val)
					{
						continue;
					}
					if (cnt == 0)
					{
						int jcnt = 0;
						for (int k = j + 1; k <= size; k++)
						{
							auto val = s & (uint(1) << size - k);
							if (!val)
							{
								if (--jcnt < 0)
									break;
							}
							else
								++jcnt;
							if (jcnt == 0)
							{
								uint tp = swap(s, i, j, k);
								if (tp > max)
								{
									max = tp;
									flag = 1;
								}
									
							}
						}
					}
				}
			}
			if (!flag)
				break;
		}
		
		return transform(max);
	}
	string transform(uint s)
	{
		string str;
		str.resize(size);
		for (uint i = 0; i < size; i++)
		{
			if (s & uint(1) << i)
				str[size - i - 1] = '1';
			else
				str[size - i - 1] = '0';
		}
		return str;
	}
	uint swap(uint s, int x, int y, int z)
	{
		uint a = table[y - x];
		uint b = table[z - y];
		uint pa = a << (size - y);
		uint pb = b << (size - z);
		uint ia = ~pa;
		uint ib = ~pb;
		uint ga = (pa & s) >> (size - y);
		uint gb = (pb & s) >> (size - z);
		s = s & ia;
		s = s & ib;
		uint rr = (gb << (y - x)) + ga;
		s = s | (rr << (size - z));
		return s;
	}
	uint transform(string S)
	{
		uint ret = 0;
		for (const auto c : S)
		{
			ret = ret << 1;
			if (c == '1')
				ret += 1;			
		}
		return ret;
	}
};
__________________________________________________________________________________________________
