__________________________________________________________________________________________________
sample 116 ms submission
struct Solution {
	static int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) noexcept {
		if (A.empty() || B.empty() || C.empty() || D.empty()) return 0;

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		sort(D.begin(), D.end());

		auto a_begin = A.begin();
		auto b_begin = B.begin();
		auto c_begin = C.begin();
		auto d_begin = D.begin();

		auto a_end = A.end();
		auto b_end = B.end();
		auto c_end = C.end();
		auto d_end = D.end();

		{
			a_begin = lower_bound(a_begin, a_end, -*make_reverse_iterator(b_end) - *make_reverse_iterator(c_end) - *make_reverse_iterator(d_end));
			a_end = upper_bound(a_begin, a_end, -*b_begin - *c_begin - *d_begin);
			if (a_begin == a_end) return 0;

			b_begin = lower_bound(b_begin, b_end, -*make_reverse_iterator(a_end) - *make_reverse_iterator(c_end) - *make_reverse_iterator(d_end));
			b_end = upper_bound(b_begin, b_end, -*a_begin - *c_begin - *d_begin);
			if (b_begin == b_end) return 0;

			c_begin = lower_bound(c_begin, c_end, -*make_reverse_iterator(a_end) - *make_reverse_iterator(b_end) - *make_reverse_iterator(d_end));
			c_end = upper_bound(c_begin, c_end, -*a_begin - *b_begin - *d_begin);
			if (c_begin == c_end) return 0;

			d_begin = lower_bound(d_begin, d_end, -*make_reverse_iterator(a_end) - *make_reverse_iterator(b_end) - *make_reverse_iterator(c_end));
			d_end = upper_bound(d_begin, d_end, -*a_begin - *b_begin - *c_begin);
			if (d_begin == d_end) return 0;
		}

		unordered_map<int, size_t> ab;
		ab.reserve(A.size() * B.size());

		const auto cd_min = *c_begin + *d_begin;
		const auto cd_max = *make_reverse_iterator(c_end) + *make_reverse_iterator(d_end);
		auto ab_min = INT_MAX;
		auto ab_max = INT_MIN;
		const auto b_last = prev(b_end);
		for (auto b_it = b_begin; b_it != b_end; ++b_it) {
			const auto bx = *b_it;
			auto count = 1;
			while (b_it != b_last && *b_it == *next(b_it)) ++count, ++b_it;
			const auto begin = lower_bound(a_begin, a_end, -bx - cd_max);
			const auto end = upper_bound(begin, a_end, -bx - cd_min);
			for (auto it = begin; it != end; ++it) {
				const auto abx = *it + bx;
				ab_min = min(ab_min, abx);
				ab_max = max(ab_max, abx);
				ab[abx] += count;
			}
		}

		if (ab.empty()) return 0;

		size_t total = 0;
		const auto d_last = prev(d_end);
		for (auto d_it = d_begin; d_it != d_end; ++d_it) {
			const auto dx = *d_it;
			auto count = 1;
			while (d_it != d_last && *d_it == *next(d_it)) ++count, ++d_it;
			const auto begin = lower_bound(c_begin, c_end, -dx - ab_max);
			const auto end = upper_bound(begin, c_end, -dx - ab_min);
			for (auto it = begin; it != end; ++it) {
				auto ab_it = ab.find(-*it - dx);
				if (ab_it != ab.end())
					total += count * ab_it->second;
			}
		}

		return total;
	}
};

static const auto _ = []() noexcept {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();
__________________________________________________________________________________________________
sample 9084 kb submission
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if (n == 0)
            return 0;
        
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tar = -(A[i] + B[j]);
                
                int k = 0, l = n - 1;
                while (k < n && l >= 0) {
                    if (C[k] + D[l] > tar) {
                        int next = l - 1;
                        while (next >= 0 && D[next] == D[l])
                            next--;
                        l = next;
                    }
                    else if (C[k] + D[l] < tar) {
                        int next = k + 1;
                        while (next < n && C[next] == C[k])
                            next++;
                        k = next;
                    }
                    else {
                        int next1 = k + 1;
                        while (next1 < n && C[next1] == C[k])
                            next1++;
                        int next2 = l - 1;
                        while (next2 >= 0 && D[next2] == D[l])
                            next2--;
                        
                        res += (next1 - k) * (l - next2);
                        
                        k = next1;
                        l = next2;
                    }
                }
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
