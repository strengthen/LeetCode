__________________________________________________________________________________________________
sample 36 ms submission
const static int _= []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int numOfRows = wall.size();
		unordered_map<int, int> numToCount;
		for (int i = 0; i < numOfRows; i++) {
			int offset = 0;
			for (int j = 0; j < wall[i].size() - 1; j++) {
				offset += wall[i][j];
				numToCount[offset]++;
			}
		}
		int maxCount = 0;
		for (auto it = numToCount.begin(); it != numToCount.end(); it++) {
			if (it->second > maxCount) {
				maxCount = it->second;
			}
		}

		int res = numOfRows - maxCount;
		return res;
	}
};
__________________________________________________________________________________________________
sample 18124 kb submission
#include <algorithm>

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       
        if(wall.size()==0)
            return 0;
        
        vector<int> arr;
        
        for(int i=0; i < wall.size(); i++ )
        {
            arr.push_back( wall[i][0] );
            
            for(int j = 1; j < wall[i].size()  ; j++)
            {
                wall[i][j] += wall[i][j-1];
                arr.push_back(wall[i][j]);
            }
            
        }

        sort(arr.begin(),arr.end());
        
        if (arr [0] == arr[arr.size()-1])
            return wall.size ();
        
        int num=arr[0],m=-1,t=1;
        for(int i=1;i<arr.size() && num != arr [arr.size()-1];i++)
        {
            if(arr[i]==num)
                t++;
            else
            {
                if(t>m)
                    m=t;
                t=1;
                num=arr[i];
            }
        }
        if (t>m)
            m=t;
        
        return wall.size()-m;        
    }
};
__________________________________________________________________________________________________
