__________________________________________________________________________________________________
sample 0 ms submission

using U32 = uint32_t;
using U64 = uint64_t;

using I32 = int32_t;
using I64 = int64_t;

const auto verbose = false;

constexpr I64 powerOfTen(U32 power) {
  I64 result = 1;
  for (auto counter = power; counter > 0; counter--) {
    result *= 10;
  }
  return result;
}

struct PermutationVector {
  std::vector<U64> permutation;

  template <typename T>
  [[nodiscard]] std::vector<T> apply(const std::vector<T> &other) const {
    if (permutation.size() != other.size()) {
      throw std::invalid_argument("Size mismatch.");
    }
    std::vector<T> result(other.size());
    for (U64 i = 0; i < permutation.size(); i++) {
      result[i] = other[permutation[i]];
    }
    return result;
  }

  template <typename T>
  [[nodiscard]] std::vector<T> applyInverse(const std::vector<T> &other) const {
    if (permutation.size() != other.size()) {
      throw std::invalid_argument("Size mismatch.");
    }
    std::vector<T> result(other.size());
    for (U64 i = 0; i < permutation.size(); i++) {
      result[permutation[i]] = other[i];
    }
    return result;
  }
};

/**
 * Gives a permutation vector that sorts a vector by non-increasing order.
 */
template <typename T>
PermutationVector getPermutationVectorToSortByNonIncreasing(const std::vector<T> &vector) {
  std::vector<std::pair<T, U64>> taggedVector;
  for (U64 i = 0; i < vector.size(); i++) {
    taggedVector.push_back({vector[i], i});
  }
  const auto isOfGreaterOrEqualMagnitude = [](const std::pair<T, U64> &a, const std::pair<T, U64> &b) {
    return std::abs(a.first) >= std::abs(b.first);
  };
  std::sort(std::begin(taggedVector), std::end(taggedVector), isOfGreaterOrEqualMagnitude);
  std::vector<U64> permutation;
  for (const auto value : taggedVector) {
    permutation.push_back(value.second);
  }
  return PermutationVector{permutation};
}

constexpr bool canChangeEnough(I64 value, I64 changeLowerBound, I64 changeUpperBound) {
  if (value < 0) {
    return value + changeUpperBound >= 0;
  } else if (value == 0) {
    return true;
  } else {
    return value + changeLowerBound <= 0;
  }
}

std::optional<std::vector<I64>> findSolution(std::vector<I64> coefficients, std::vector<bool> nonZeros) {
  const auto permutationVector = getPermutationVectorToSortByNonIncreasing(coefficients);
  coefficients = permutationVector.apply(coefficients);
  nonZeros = permutationVector.apply(nonZeros);
  std::vector<I64> changeLowerBound(coefficients.size());
  std::vector<I64> changeUpperBound(coefficients.size());
  for (U64 i = 0; i < coefficients.size(); i++) {
    const auto index = coefficients.size() - 1 - i;
    if (index + 1 < coefficients.size()) {
      changeLowerBound[index] += changeLowerBound[index + 1];
      changeUpperBound[index] += changeUpperBound[index + 1];
    }
    if (coefficients[index] > 0) {
      changeUpperBound[index] += 9 * coefficients[index];
    } else {
      changeLowerBound[index] += 9 * coefficients[index];
    }
  }
  if (verbose) {
    for (U64 i = 0; i < coefficients.size(); i++) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << changeUpperBound[i];
    }
    std::cout << "\n";
  }
  std::vector<bool> used(10);
  std::vector<I64> values(coefficients.size(), -1);
  I64 value = 0;
  std::vector<I64> digits;
  const std::function<bool(U32)> tryToSolveRemaining = [&](U32 i) {
    if (i == coefficients.size()) {
      return value == 0;
    }
    if (!canChangeEnough(value, changeLowerBound[i], changeUpperBound[i])) {
      return false;
    }
    for (I64 digit = 0; digit < 10; digit++) {
      if (digit == 0 && nonZeros[i]) {
        continue;
      }
      if (used[digit]) {
        continue;
      }
      used[digit] = true;
      values[i] = digit;
      value += coefficients[i] * values[i];
      if (tryToSolveRemaining(i + 1)) {
        return true;
      }
      value -= coefficients[i] * values[i];
      values[i] = -1;
      used[digit] = false;
    }
    return false;
  };
  if (tryToSolveRemaining(0)) {
    return permutationVector.applyInverse(values);
  }
  return {};
}

void writeProblem(const std::map<char, U32> &characterToIndex,
                  const std::vector<I64> &coefficients,
                  const std::optional<std::vector<I64>> &solution) {
  auto first = true;
  for (const auto mapping : characterToIndex) {
    if (!first) {
      if (coefficients[mapping.second] < 0) {
        std::cout << " - ";
      } else {
        std::cout << " + ";
      }
    }
    if (first) {
      std::cout << coefficients[mapping.second];
    } else {
      std::cout << std::abs(coefficients[mapping.second]);
    }
    first = false;
    std::cout << " * ";
    if (solution) {
      std::cout << solution->at(mapping.second);
    } else {
      std::cout << mapping.first;
    }
  }
  std::cout << " = 0" << '\n';
}

class Solution {
 public:
  bool isSolvable(const std::vector<std::string> &words, const std::string &result) {
    std::map<char, U32> characterToIndex;
    std::vector<I64> coefficients;
    std::vector<bool> nonZeros;
    const auto addToCoefficients = [&](const std::string &string, I32 multiple) {
      for (U32 d = 0; d < string.size(); d++) {
        const auto c = string[string.size() - 1 - d];
        if (characterToIndex.count(c) == 0) {
          const auto index = coefficients.size();
          coefficients.resize(index + 1);
          characterToIndex[c] = index;
        }
        coefficients[characterToIndex[c]] += multiple * powerOfTen(d);
      }
      nonZeros.resize(coefficients.size());
      nonZeros[characterToIndex[string.front()]] = true;
    };
    for (const auto &word : words) {
      addToCoefficients(word, 1);
    }
    addToCoefficients(result, -1);
    if (verbose) {
      std::cout << "Non-zeros: ";
      auto first = true;
      for (U64 i = 0; i < nonZeros.size(); i++) {
        if (nonZeros[i]) {
          if (!first) {
            std::cout << ", ";
          }
          std::cout << i;
          first = false;
        }
      }
      std::cout << '\n';
    }
    if (verbose) {
      writeProblem(characterToIndex, coefficients, {});
    }
    const auto &solution = findSolution(coefficients, nonZeros);
    if (verbose) {
      if (solution) {
        writeProblem(characterToIndex, coefficients, solution);
      } else {
        std::cout << "No solution." << '\n';
      }
    }
    return solution.has_value();
  }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    queue<int> qq;
    vector<int> ppp;
    vector<int> max_p;
    bool dfs(vector<int>& cnt,vector<bool>& notz,int n,int sum,int used){
        if(n==cnt.size()) return sum==0;
        if(cnt[ppp[n]]==0) return dfs(cnt,notz,n+1,sum,used);
        if(abs(sum)>max_p[n]) return false;
        int len=qq.size();
        while(len--){
            int i=qq.front();
            qq.pop();
            if((notz[ppp[n]]&&i==0)||(used&(1<<i))){
            qq.push(i);
            continue;
        }
        if(dfs(cnt,notz,n+1,sum+cnt[ppp[n]]*i,used|(1<<i))) return true;
            qq.push(i);
        }
            return false;
        }
    public:
    bool isSolvable(vector<string>& words, string result) {
        vector<int> mm(26,-1);
        int p=0;
        words.push_back(result);
        for(int i=0;i<words.size();i++){
            for(char c:words[i]){
                if(mm[c-'A']==-1) mm[c-'A']=p++;
            }
        }

        vector<bool> notz(p,false);
        vector<int> cnt(p,0);

        for(int i=0;i<words.size();i++){
            int t=1;
            for(int j=words[i].size()-1;j>=0;j--){
                int idx=mm[words[i][j]-'A'];
                if(j==0&&words[i].size()>0) notz[idx]=true;
                if(i==words.size()-1)
                    cnt[idx]-=t;
                else cnt[idx]+=t;
                t*=10;
            }
        }
        qq=queue<int>();
        for(int i=0;i<=9;i++) qq.push(i);
        for(int i=0;i<p;i++) ppp.push_back(i);
        sort(ppp.begin(),ppp.end(),[&](int a,int b){
            return abs(cnt[a])>abs(cnt[b]);
        });
        int sum=0;
        for(int i=ppp.size()-1;i>=0;i--){
            sum+=abs(cnt[ppp[i]]*9);
            max_p.push_back(sum);
        }
        reverse(max_p.begin(),max_p.end());
        return dfs(cnt,notz,0,0,0);
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int mp[26], use[10], isLead[26];

    bool isSolvable(vector<string>& words, string result) {
        int mx = 0, n = result.length();
        memset(mp, -1, sizeof(mp));
        memset(use, 0, sizeof(use));

        for (auto& w : words) {
            int l = w.length();
            if (l > 1) isLead[w[0] - 'A'] = 1;
            reverse(begin(w), end(w));
            mx = max(mx, l);
        }
        if (mx < n - 1 || n < mx) return false;
        if (n > 1) isLead[result[0] - 'A'] = 1;
        reverse(begin(result), end(result));

        return dfs(0, 0, 0, words, result);
    }
    bool dfs(int st, int i, int sum, vector<string>& words, string& result) {
        if (st == result.length()) return true;
        if (i < words.size()) {
            string& w = words[i];
            if (st >= w.size()) {
                return dfs(st, i + 1, sum, words, result);
            }
            int c = w[st] - 'A';
            if (mp[c] != -1) return dfs(st, i + 1, sum + mp[c], words, result);
            else
                for (int j = 0; j < 10; j++) {
                    if (!j && isLead[c] || use[j]) continue;
                    use[j] = 1, mp[c] = j;
                    if (dfs(st, i + 1, sum + mp[c], words, result)) return true;
                    mp[c] = -1, use[j] = 0;
                }
        }
        else {
            int c = result[st] - 'A';
            if (mp[c] != -1) {
                if (sum % 10 != mp[c]) return false;
                return dfs(st + 1, 0, sum / 10, words, result);
            }
            else {
                int k = sum % 10;
                if (!use[k]) {
                    if (!(isLead[c] && k == 0)) {
                        use[k] = 1, mp[c] = k;
                        if (dfs(st + 1, 0, sum / 10, words, result)) return true;
                        mp[c] = -1, use[k] = 0;
                    }
                }
            }
        }
        return false;
    }

};