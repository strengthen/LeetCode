__________________________________________________________________________________________________
sample 4 ms submission
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
private:
	bool isValid(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			return true;
		}
		else { return false; }
	}
public:
	string reverseVowels(string s) {
		for (size_t i = 0, j = s.size() - 1; i < j + 1;) {
			for (; i < j + 1 && !isValid(s[i]);) { ++i; }
			for (; i < j + 1 && !isValid(s[j]);) { --j; }
			if (i < j + 1) { swap(s[i++], s[j--]); }
		}
		return s;
	}
};
__________________________________________________________________________________________________
sample 9512 kb submission
class Solution {
public:
	std::string reverseVowels(std::string s) {
		for (int from = 0, to = s.size() - 1; from < to; ++from, --to)
		{
			from = s.find_first_of("aeiouAEIOU", from);
			to = s.find_last_of("aeiouAEIOU", to);
			if (from < to)
				std::swap(s[from], s[to]);
		}
		return s;
	}
};
__________________________________________________________________________________________________
