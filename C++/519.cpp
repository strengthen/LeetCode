__________________________________________________________________________________________________
sample 20 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

std::random_device rd;

class Solution {
public:
  Solution(int n_rows, int n_cols): _gen(rd()), _cols(n_cols), 
									_count(n_rows * n_cols), 
									_dis(0, _count - 1) {
  }
    
  vector<int> flip() {
	while (true) {
	  int random_number = _dis(_gen);
	  if (_indexes.insert(random_number).second)
		return {random_number / _cols, random_number % _cols};
	}

	return {};
  }
    
  void reset() {
	_indexes.clear();
  }
private:
  unordered_set<int> _indexes;
  int _cols;
  int _count;
  std::mt19937 _gen;
  std::uniform_int_distribution<> _dis;
};
__________________________________________________________________________________________________
sample 12280 kb submission
class Solution
	{
		unordered_set< int >m_ones;
		int m_nr, m_nc;
	public:
		Solution(int n_rows, int n_cols) : m_nr(n_rows), m_nc(n_cols)
		{			
		}
		vector<int> flip() 
		{
			int j, np = m_nc * m_nr;
			do 
			{
				j = rand() % np;
			} while (m_ones.find(j) != m_ones.end());
			m_ones.insert(j);

			int r = j / m_nc;
			int c = j - r * m_nc;
			return vector<int>({ r, c });
		}

		void reset() 
		{
			m_ones.clear();
		}
	};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
__________________________________________________________________________________________________
