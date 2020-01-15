__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int width = mat[0].size();
        int height = mat.size();
        vector<int> M;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                int t = 0;
                int z[5];
                z[0] = i*width + j; // spot
                z[1] = (i > 0) ? (i-1)*width + j : -1; // up
                z[2] = (i < height-1) ? (i+1)*width + j : -1; // down
                z[3] = (j > 0) ? i*width + j - 1 : -1; // left
                z[4] = (j < width - 1) ? i*width + j + 1 : -1; // right;
                
                for(int k = 0; k < 5; k++)
                {
                    if(z[k] > -1)
                    {
                        t += (1 << z[k]);
                    }
                }
                M.push_back(t);
            }
        }
        
        int start_state = 0;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                int w = i*width + j;
                if(mat[i][j] == 1)
                {
                    start_state += (1<<w);
                }
            }
        }
        
        int sneed = -1;
        queue< pair<int,int> > X;
        X.push(make_pair(0, 0));
        while(!X.empty())
        {
            int val = X.front().first;
            int index = X.front().second / 100;
            int steps = X.front().second % 100;
            X.pop();
            if(val == start_state)
            {
                sneed = steps;
                break;
            }
            if(index < M.size())
            {
                X.push(make_pair(val ^ M[index], 100*(index+1)+(steps+1)));
                X.push(make_pair(val, 100*(index+1)+steps));
            }
        }
        
        return sneed;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
#define see(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



namespace utils::dynamic_bitset {
template <typename set_t = int, typename... Ts, typename std::enable_if_t<std::conjunction_v<std::is_same<int, Ts>...>>* = nullptr>
int flip(set_t mask, Ts... arg) { return ((mask ^= (1 << arg)), ...); }


template <typename set_t = int, typename... Ts, typename std::enable_if_t<std::conjunction_v<std::is_same<int, Ts>...>>* = nullptr>
bool test(set_t mask, Ts... arg) { return ((mask & (1 << arg)) && ...); }

template <typename set_t = int, typename T, typename std::enable_if_t<std::conjunction_v<std::is_same<int, T>>>* = nullptr>
int count_upto(set_t mask, T n) {
  int acc = 0;
  for (int i = 0; i < n; i++)
    if ((mask & (1 << i)) > 0) acc++;
  return acc;
};

template <typename set_t = int>
void assign_inplace(set_t* mask, int pos, int n) {
  if ((test(*mask, pos) and n == 0)
      or (not test(*mask, pos) and n == 1))
    *mask = flip(*mask, pos);
}
}



class Solution {
 public:
  int minFlips(vector<vector<int>>& mat) {
    using namespace utils::dynamic_bitset;

    const int R = size(mat), C = size(mat[0]);
    constexpr int dr[4] {1, -1, 0, 0};
    constexpr int dc[4] {0 ,0, 1, -1};
    
    auto id = [&](int r, int c) {
      return r * C + c;
    };

    const auto initial_board = [&] {
      int self = 0;
      for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
          assign_inplace(&self, id(r, c), mat[r][c]);
      return self;
    }();

    const int target_board = 0;

    auto valid = [&](int r, int c) {
      return r >= 0 and r < R and c >= 0 and c < C;
    };

    auto flip_board = [&](int board, int r, int c) {
      auto old_board = board;
      board = flip(board, id(r, c));
      for (int i = 0; i < 4; ++i) {
        const auto [nr, nc] = tuple(r + dr[i], c + dc[i]);
        if (valid(nr, nc)) 
          board = flip(board, id(nr, nc));
      }
      return board;
    };

    struct state_t {
      mutable deque<int> Q;
      mutable optional<int> D[1 << 10];
    };

    const auto solution = [&] {
      const auto [Q, D] = state_t{{initial_board}, {}};
      for (D[initial_board] = 0; not empty(Q);) {
        const auto cur_board = Q.front();
        Q.pop_front();
        if (cur_board == target_board) 
          return *D[cur_board];
        for (int r = 0; r < R; ++r)
          for (int c = 0; c < C; ++c) {
            if (const auto next_board = flip_board(cur_board, r, c); not D[next_board]) {
              D[next_board] = *D[cur_board] + 1;
              Q.emplace_back(next_board);
            }
          }
      }
      return -1;
    }();
    return solution;
  }
};
__________________________________________________________________________________________________
