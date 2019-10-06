__________________________________________________________________________________________________
16ms
class Solution {
private:
	//Binary Search
    bool search(vector<int>& vec, int item)
    {
        int low = 0, high = vec.size()-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(vec[mid] == item)
                return true;
            if(vec[mid] > item)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return false;
    }
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        vector<int> temp, result;
        
		//Creating an intersection of arr1 and arr2 into temp
        for(int i=0; i<arr2.size(); i++)
        {
            if(search(arr1,arr2[i]))
                temp.push_back(arr2[i]);
        }
        
		//Creating intersection of temp and arr3 into result
        for(int i=0; i<temp.size(); i++)
        {
            if(search(arr3,temp[i]))
                result.push_back(temp[i]);
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    unordered_map<int, int> C;
    for (int x : arr1) ++ C[x];
    for (int x : arr2) ++ C[x];
    for (int x : arr3) ++ C[x];
    vector<int> ans;
    for (const auto& kv : C) {
      if (kv.second == 3) {
        ans.push_back(kv.first);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> m;
        for (int a : arr1) m[a]++;
        for (int a : arr2) m[a]++;
        for (int a : arr3) m[a]++;
        vector<int> res;
        for (auto p : m) if (p.second == 3) res.push_back(p.first);
        return res;
    }
};