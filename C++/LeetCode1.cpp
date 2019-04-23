__________________________________________________________________________________________________
9124kb
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        for (int i = 0; i < nums.size() ; ++i)
        {
            for (int j = i + 1 ; j < nums.size() ; ++j)
            {
                if (target == nums[i] + nums[j])
                {
                    //solution.reserve(2);
                    solution.push_back(i);
                    solution.push_back(j);
                    return solution;
                }
            }
        }
        throw logic_error("no solution!");
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for(int i=0; i<nums.size(); i++) {
            if(indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i}; 
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberTofind = target - nums[i];
            if (hash.find(numberTofind) != hash.end()) {
                result.push_back(hash[numberTofind]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<size_t, vector<int>> hashmap;
		for (int i = 0; i < nums.size(); ++i)
		{
			int n = nums[i];
			auto pairHash = std::hash<int>{}(target - n);
			auto& pairs = hashmap[pairHash];
			for (int j = 0; j < pairs.size(); j++)
			{
				int index = pairs[j];
				if (n + nums[index] == target)
					return{ i, index };
			}
			hashmap[std::hash<int>{}(n)].push_back(i);
		}
		return {};
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> val_index_map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            auto it = val_index_map.find(comp);
            if (it != val_index_map.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            val_index_map[nums[i]] = i;
        }

        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
__________________________________________________________________________________________________