__________________________________________________________________________________________________
sample 4 ms submission
void beforeMain(void) __attribute__((constructor));

void beforeMain(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}
class Solution {
 public:
  inline static string frequencySort(string& s) {
    typedef struct {
      char ch;
      int frq;
    } data;
    data Freq[128];
    for (int i = 0; i < 128; ++i) {
      Freq[i].ch = i;
      Freq[i].frq = 0;
    }
    for (const char& c : s) {
      ++Freq[c].frq;
    }
    auto comp = [](const data& d1, const data& d2) { return d1.frq < d2.frq; };
    std::make_heap(Freq, Freq+128, comp);
    std::pop_heap(Freq, Freq+128, comp);
    s.clear();
    for (int i = 127; i >= 0 && Freq[i].frq > 0; --i) {
      s.append(Freq[i].frq, Freq[i].ch);
      std::pop_heap(Freq, Freq + i, comp);
    }
    return s;
  }
};
__________________________________________________________________________________________________
sample 10308 kb submission
vector<int> counts(256,0);
//int counts[256] = {0};
bool myCompare(char& a, char& b){
    cout << a << "xx" << b << endl;
    cout << counts[a] << "vs" << counts[b] << endl;
    return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
}
class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        for(int i = 0; i < 256; i++)
            cout << counts[i];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};
__________________________________________________________________________________________________
