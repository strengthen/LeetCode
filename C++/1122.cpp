__________________________________________________________________________________________________
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());
        int n = arr1.size();
        vector<bool> used(n, false);
        vector<int> result;

        for (int x : arr2) {
            for (int i = 0; i < n; i++)
                if (arr1[i] == x && !used[i]) {
                    result.push_back(x);
                    used[i] = true;
                }
        }

        for (int i = 0; i < n; i++)
            if (!used[i])
                result.push_back(arr1[i]);

        return result;
    }
};

__________________________________________________________________________________________________
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int pos = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            for (int j = 0; j < arr1.size(); ++j)
                if (arr1[j] == arr2[i]) swap(arr1[j], arr1[pos]), ++pos;
        }
        sort(arr1.begin() + pos, arr1.end());
        return arr1;
    }
};

__________________________________________________________________________________________________
