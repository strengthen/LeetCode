__________________________________________________________________________________________________
4ms
class Solution {
	class trie;
	using pointers = array<trie*, 0x100>;
	using bits = bitset<0x100>;

	class trie : variant<pointers, bits> {
		using variant::variant;
		static constexpr size_t SIZE = sizeof(unsigned) - 1;

		static void traverse(const trie* node, unsigned n, bool& has_last, unsigned& last, unsigned& max_gap) noexcept
		{
			if (holds_alternative<pointers>(*node)) {
				for (size_t i = 0; i < 0x100; ++i)
					if (get<pointers>(*node)[i]) traverse(get<pointers>(*node)[i], (n << 8) + i, has_last, last, max_gap);
				return;
			}

			for (size_t i = 0; i < 0x100; ++i)
				if (get<bits>(*node).test(i)) {
					if (has_last) max_gap = max(max_gap, unsigned((n << 8) + i - last));
					else has_last = true;
					last = (n << 8) + i;
				}
		}

	public:
		void insert(int n) noexcept {
			auto unsigned_n = unsigned(n);
			auto ptr = this;
			for (size_t depth = 0; depth < SIZE; ++depth) {
				auto& ptr_ind = get<pointers>(*ptr)[unsigned_n >> (SIZE << 3)];
				if (ptr_ind) ptr = ptr_ind;
				else ptr = ptr_ind = depth == SIZE - 1
					? new trie{ in_place_type_t<bits>{} }
				: new trie{ in_place_type_t<pointers>{} };
				unsigned_n <<= 8;
			}
			get<bits>(*ptr).set(unsigned_n >> (SIZE << 3));
		}

		int find_max_gap() const noexcept {
			bool has_last = false;
			unsigned last = 0;
			unsigned max_gap = 0;
			traverse(this, 0, has_last, last, max_gap);
			return int(max_gap);
		}
	};

public:
	static int maximumGap(vector<int>& nums) noexcept {
		switch (nums.size())
		{
		case 0:
		case 1:
			return 0;
		case 2:
			return abs(nums[0] - nums[1]);
		default:
			if (nums.size() > 9000) {
				trie t;
				for (int n : nums) t.insert(n);
				return t.find_max_gap();
			}
			sort(nums.begin(), nums.end());
			int max_gap = 0;
			for (size_t i = 2; i < nums.size(); ++i)
				max_gap = max(max_gap, nums[i] - nums[i - 1]);
			return max_gap;
		}
	}
};

static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
9208 kb
class Solution {
public:
int maximumGap(vector<int>& nums)
{
    if (nums.size() < 2) {
        return 0;
    }
    
    std::sort(nums.begin(), nums.end());
    
    int max_gap = nums[1] - nums[0];
    
    int max_possible = (nums[nums.size() - 1] - nums[0]) / 2;     
        
    for (size_t i=2; i < nums.size() && max_gap < max_possible; ++i) {
        max_gap = std::max(max_gap, nums[i] - nums[i - 1]);
    }    

    return max_gap;
}
};
__________________________________________________________________________________________________
