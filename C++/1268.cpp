__________________________________________________________________________________________________
sample 20 ms submission
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
         sort(products.begin(),products.end());
         vector<vector<string>> vec(searchWord.size());
         for(int i=0;i<products.size();i++)
         {
             for(int k=0;k<searchWord.size();k++)
             {
                 if(searchWord[k]==products[i][k])
                 {
                    if(vec[k].size()<3)
                       vec[k].push_back(products[i]);
                 }    
                 else
                    break; 
             }
         }
         return vec;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
         sort(products.begin(),products.end());
         vector<vector<string>> vec(searchWord.size());
         for(int i=0;i<products.size();i++)
         {
             for(int k=0;k<searchWord.size();k++)
             {
                 if(searchWord[k]==products[i][k])
                 {
                    if(vec[k].size()<3)
                       vec[k].push_back(products[i]);
                 }    
                 else
                    break; 
             }
         }
         return vec;
    }
};
__________________________________________________________________________________________________
