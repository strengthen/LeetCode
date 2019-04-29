__________________________________________________________________________________________________
sample 4 ms submission
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
        vector<int> tmp(cells.size());
        //print_vector2(cells);
        //cout << endl;

        N = N % 14 == 0 ? 14 : N % 14;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j < cells.size() - 1; ++j) {
                if (cells[j - 1] == cells[j + 1])
                    tmp[j] = 1;
                else
                    tmp[j] = 0;
            }
            cells = tmp;
            for (auto& itr : tmp) {
                itr = 0;
            }
            //print_vector2(cells);
            //std::cout << std::endl;
        }

        return cells;
    }
};
__________________________________________________________________________________________________
sample 9704 kb submission
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& c, int N) {
    vector<int> f_c, next_c(c.size(), 0);
    for (int cycle = 0; N-- > 0; c = next_c, ++cycle) {
    for (auto i = 1; i < c.size() - 1; ++i) next_c[i] = c[i - 1] == c[i + 1];
    if (cycle == 0) f_c = next_c;
    else if (next_c == f_c) N %= cycle;
    }
    return c;
    }
};
__________________________________________________________________________________________________
