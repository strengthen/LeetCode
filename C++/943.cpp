__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string findMaxOverlap(const vector<string>& A, vector<string>::const_iterator& p, vector<string>::const_iterator& q) {
        // for all pairs check for suffix and prefix overlap
        // set iterators to 2 strings with max overlap
        // p should always point to string that would come first after join
        int max_overlap = 0;
        string found = "";
        
        for(int i=0; i<A.size(); ++i) {
            for (int j=i+1; j<A.size(); ++j) {
                //suffix overlap; check end of A[i] with start of A[j]
                for (int k =1; k <= min(A[i].length(), A[j].length()); ++k) {
                    if (A[i].compare(A[i].length()-k, k, A[j], 0, k) == 0) {
                        if (k > max_overlap) {
                            max_overlap = k;
                            found = A[i] + A[j].substr(k);
                            p = A.begin()+i;
                            q = A.begin()+j;
                        }
                    }
                }
                
                // prefix overlap, check start of A[i] with end of A[j]
                for (int k=1; k <= min(A[i].length(), A[j].length()); ++k) {
                    if (A[i].compare(0, k, A[j], A[j].length()-k, k) == 0) {
                        if (k > max_overlap) {
                            max_overlap = k;
                            found = A[j] + A[i].substr(k);
                            p = A.begin()+i;
                            q = A.begin()+j;
                        }
                    }
                }
            }
        }
        return found;
    }
    
    string shortestSuperstring(vector<string>& A) {
        // check all pairs for overlap
        // combine 2 strings with max overlap
        // repeat till one string is left
        
        while(A.size() != 1) {
            vector<string>::const_iterator p = A.end();
            vector<string>::const_iterator q = A.end();
            string s = findMaxOverlap(A, p, q);
            if (s.length() > 0) {
                // p and q would point to string to be joined
                A.erase(p);
                A.erase(q-1); // After erasing p iterator vector would shrink and as q its is always to right of p, as it comes from j in outerloop so safe to decrease it by 1.
                A.push_back(s);
                
            } else {
                // no overlap found, so all remaining strings in A should be combined
                for (const auto& a :A) {
                    s+=a;
                }
                return s;
            }
        }
        return A[0];
    }
};
__________________________________________________________________________________________________
sample 164980 kb submission
class Solution {
public:
    
    vector<vector<int>> M;
    unordered_map<int, unordered_map<int, pair<int,vector<int>>>> memo;
    
    int overlap(string &s1, string &s2)
    {
        int l = min(s1.length() , s2.length());
        while(l>0)
        {
            if(s1.substr(s1.length()-l) == s2.substr(0,l))
                return l;
            l--;
        }
        return l;
    }
    
    void fillM(vector<string> &A)
    {
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A.size();j++)
            {
              //  if(i!=j)
                M[i][j] = overlap(A[i], A[j]);
                
    //            cout<<M[i][j]<<' ';
            }
   //         cout<<endl;
        }
    }
    
    pair<int, vector<int>> generate(int vis, int last, int N)
    {
        
        if(vis == ((1<<N)-1))
            return {0, vector<int> ()};
        
        if(memo[vis].find(last) != memo[vis].end())
            return memo[vis][last];
 //       cout<<"vis"<<vis<<endl;
        int minpos;
        int minlen=INT_MAX;
        vector<int> minInd;
        for(int i=0;i<N;i++)
        {
         //   cout<<(vis & (1<<i))<<endl;
            if((vis & (1<<i)) == 0)
            {
                auto p = generate(vis|(1<<i), i, N);
                int tempL(0);
               // if(p.second.size()>0)
               //     tempL = M[i][p.second[0]];
                
                if(last!=-1)
                    tempL = M[last][i];
                
                if(p.first - tempL + M[i][i] < minlen)
                {
                    minlen = p.first-tempL+ M[i][i];
                    p.second.insert(p.second.begin(), i);
                    minInd = p.second;
                }
            }
        }
        int lastlen = (last==-1)?0:M[last][last];
  //      cout<<last<<' '<<minlen<<' '<<vis<<minInd.size()<<endl;
        memo[vis][last]={minlen,minInd};
        return {minlen, minInd};
    }
    
    string createString(vector<string>& A, vector<int>& pos)
    {
        string res;
        for(auto p:pos)
        {
            res += A[p].substr(overlap(res, A[p]));
        }
        return res;
        
    }
    
    string shortestSuperstring(vector<string>& A) {
        
  //      cout<<"started\n";
        M = vector<vector<int>> (A.size(), vector<int> (A.size(), 0));
        
        fillM(A);
   //     cout<<"filled\n";
        auto res = generate(0, -1, A.size());        
        return createString(A,res.second);
    }
};
__________________________________________________________________________________________________
