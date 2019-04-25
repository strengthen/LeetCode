__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int lengthLongestPath(string input) {
    int n = input.size();
    unordered_map<int,int> lengths; 
    lengths[-1] = 0; 
    int length = 0, level = 0, max_length = 0; 
    bool is_file = false; 
    
    for (int i = 0; i < n; ++i) {
        switch (input[i]) {
            case '\n':
                if (is_file) {
                    max_length = max(max_length, length + lengths[level - 1]);
                }
                else {
                    lengths[level] = length + lengths[level - 1] + 1;   // include slash
                }
                level = 0; 
                length = 0;
                is_file = false; 
                break;
            case '\t':
                ++level;
                break;
            case '.':
                is_file = true;
                ++length;
                break;
            default:
                ++length;
        }
    }

    // Recheck since no \n at end of input
    return (is_file ? max(max_length, length + lengths[level - 1]) : max_length); 
}
};
__________________________________________________________________________________________________
sample 8708 kb submission
class Solution {
public:
    int lengthLongestPath(string input) {
vector<int> levelLen;
        int currentLen = 0;
        int currentLevel = 0;
        int maxLen = 0;
        bool isfile = false;
        for (char a: input)
        {
            if (a == '\n')
            {
                if (levelLen.size() <= currentLevel)
                    levelLen.push_back(currentLen);
                else
                    levelLen[currentLevel] = currentLen;
                
                if(isfile)
                {
                    int sum = 0;
                    for (int i=0; i<=currentLevel; i++)
                        sum += levelLen[i]+1;
                    maxLen = max(maxLen, sum-1);
                    isfile = false;
                }                
                
                currentLen = 0;
                currentLevel = 0;
            }
            else if(a == '\t')
            {
                currentLevel++;
            }
            else
            {
                currentLen++;
                if(a == '.')
                    isfile = true;
            }
        }
        //handle the last file
        if(isfile)
        {
            if (levelLen.size() < currentLevel + 1)
                levelLen.push_back(currentLen);
            else
                levelLen[currentLevel] = currentLen;
            int sum = 0;
            for (int i=0; i<=currentLevel; i++)
                sum += levelLen[i]+1;
            maxLen = max(maxLen, sum-1);
            isfile = false;
        }  
        return maxLen;
    }
};
__________________________________________________________________________________________________
