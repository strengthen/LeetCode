__________________________________________________________________________________________________
24ms
static const auto ____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> bSet{beginWord};
        unordered_set<string> eSet{endWord};
        unordered_set<string> wSet(wordList.begin(),wordList.end());
        if(wSet.find(endWord) == wSet.end())
            return 0;
        int res = 1;
        
        while(!bSet.empty())
        {
            unordered_set<string> tSet;
            ++res;
            for(auto w : bSet)
            {
                wSet.erase(w);
            }
            for(auto word : bSet)
            {
                for(int i = 0;i < word.size();i++)
                {
                    string w = word;
                    for(auto j = 'a' ;j <= 'z';j++)    
                    {
                        w[i] = j;
                        if(wSet.find(w) == wSet.end())
                        {
                            continue;
                        }
                        if(eSet.find(w) != eSet.end())
                        {
                            return res;
                        }
                        tSet.insert(w);           
                    }
                }

            }
            if(tSet.size() >= eSet.size())
            {
                bSet = eSet;
                eSet = tSet;
            }
            else
            {
                bSet = tSet;
            }
        }
        return 0;
    }
};
__________________________________________________________________________________________________
11072 kb
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if (beginWord == endWord) return  2;        
        
        queue<pair<int,int>> myQueue;
        vector<bool> unvisited(wordList.size(),true);
        bool endWordExist = false;
        for (int i=0;i<wordList.size();i++)
        {
            if (endWord == wordList[i]) endWordExist = true;
        }
        
        if (!endWordExist) return 0;

        myQueue.push(pair<int,int>(-1,1 ));
        
        while(!myQueue.empty() )
        {
            int currIdx = myQueue.front().first;
            int currLength = myQueue.front().second;
            myQueue.pop();
            
            string currWord;
            if (currIdx == -1)
            {
                currWord = beginWord;
            }
            else
            {
                currWord = wordList[currIdx];
            }
            
            currLength++;
            if(isAdj(currWord, endWord)) 
            {
                // cout << currWord <<"," << endWord << endl;
                return currLength;
            }
            
            for (int i=0; i <unvisited.size();i++ )
            {
                if (unvisited[i])
                {
                    if(isAdj(currWord, wordList[i]))   
                    {
                        myQueue.push(pair<int,int>(i,currLength));
                        unvisited[i]=false;
                    }
                }
            }           
        }
        
        return 0;
 
    }

    bool isAdj(string s1, string s2)
    {
        int count =0;
        for (int i=0; i < s1.size();i++)
        {
            if (s1[i]!=s2[i]) count++;
            if (count>1) return false;
        }
        // cout << s1<< "," << s2 << "," << (count==1) << endl;
        return true;
    }   
};
__________________________________________________________________________________________________
