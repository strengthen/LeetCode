__________________________________________________________________________________________________
sample 44 ms submission
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class RandomizedSet { 
private:
  // Number of values in set.
  int Size = 0;

  // Map values in the set to their sequential buckets for random access.
  std::unordered_map<int, int *> ValToBucket;

  // Bucket of each value in the set. Used for random access.
  std::deque<int> Buckets;

  // Random number generator.
  std::random_device RandDevice;
  std::mt19937 RandGen;
public:
  RandomizedSet() : RandGen(RandDevice()) {}

  // Inserts a value to the set.
  //
  // \return If the set did not already contain the specified element.
  bool insert(int Val) {
    auto InsertResult = ValToBucket.emplace(Val, nullptr);
    if (!InsertResult.second)
      return false;

    Buckets.push_back(Val);
    InsertResult.first->second = &Buckets.back();
    Size++;
    return true;
  }

  // Removes a value from the set.
  // \return If the set contained the specified element.
  bool remove(int Val) {
    auto FindResult = ValToBucket.find(Val);
    if (FindResult == ValToBucket.end())
      return false;

    const int SwapVal = Buckets.back();
    std::swap(Buckets.back(), *FindResult->second);
    ValToBucket[SwapVal] = FindResult->second;
    ValToBucket.erase(FindResult);
    Buckets.pop_back();
    Size--;
    return true;
  }

  // \return A random element from the set.
  int getRandom() {
    std::uniform_int_distribution<int> Rand(0, Size - 1);
    return Buckets[Rand(RandGen)];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
__________________________________________________________________________________________________
sample 21240 kb submission
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (count(vec.begin(),vec.end(),val)) return false;
        else {
            vec.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it=find(vec.begin(),vec.end(),val);
        if (it != vec.end())
        {
            vec.erase(it);
            return true;
        } else {
            return false;
        }

    }

    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }

private:
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
__________________________________________________________________________________________________
