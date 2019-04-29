__________________________________________________________________________________________________
sample 48 ms submission
class Solution
{
  public:
    int oddEvenJumps(vector<int> const &v)
    {
        vector<pair<int, size_t>> w;
        for (size_t i = 0; i < v.size(); i++)
            w.emplace_back(v[i], i);
        
        vector<int> odd(v.size(), -1), even(v.size(), -1);
        
        stack<pair<int, size_t>> s;
        
        sort(w.begin(), w.end());
        for (auto const &p : w)
        {
            while (! s.empty() && s.top().second <= p.second)
            {
                odd[s.top().second] = p.second;
                s.pop();
            }
            
            s.emplace(p);
        }
        
        s = {};
        sort(w.begin(), w.end(), [] (pair<int, size_t> const &a, pair<int, size_t> const &b)
             {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first > b.first;
             });
        for (auto const &p : w)
        {
            while (! s.empty() && s.top().second <= p.second)
            {
                even[s.top().second] = p.second;
                s.pop();
            }
            
            s.emplace(p);
        }
        
        int count = 1;
        vector<int> state(v.size());
        state.back() = 0b11;
        for (int i = v.size() - 2; i >= 0; i--)
        {
            if (odd[i] != -1 && state[odd[i]] & 0b01)
            {
                state[i] |= 0b10;
                count++;
            }
            if (even[i] != -1 && state[even[i]] & 0b10)
                state[i] |= 0b01;
        }
        
        return count;
    }
};


static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
__________________________________________________________________________________________________
sample 56 ms submission
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<pair<int,int>> v;
        for(int i=0;i<A.size();i++){
            v.push_back(make_pair(A[i],i));
        }
        
                
        vector<int> nxtodd(A.size(),-1);
        vector<int> nxteven(A.size(),-1);        
        sort(v.begin(),v.end());
        make(nxtodd,v);
        
            
        for(int i=0;i<A.size();i++){
            v[i].first = -v[i].first;
        }
        sort(v.begin(),v.end());
        make(nxteven,v);
        
        
        vector<int> even(A.size(),0);
        vector<int> odd(A.size(),0);
        
        // for(int i=0;i<nxtodd.size();i++)
        //     cout << nxtodd[i] << " ";
        // cout << endl;
        // for(int i=0;i<nxteven.size();i++)
        //     cout << nxteven[i] << " ";
        
        odd[A.size()-1]=even[A.size()-1]=1;
        for(int i=A.size()-2;i>=0;i--){
            
            if(nxtodd[i]!=-1)   odd[i] = even[nxtodd[i]];
            if(nxteven[i]!=-1)  even[i] = odd[nxteven[i]];
        }
        
        return accumulate(odd.begin(),odd.end(),0);
    }
    
    void make(vector<int>& nxt,vector<pair<int,int>>& v){
        stack<int> st;
        for(int i=0;i<v.size();i++){
            while(!st.empty() && v[i].second>st.top()){
                nxt[st.top()] = v[i].second;
                st.pop();
            }
            st.push(v[i].second);
        }
    }
};
__________________________________________________________________________________________________
sample 10600 kb submission
class Solution {
public:
   int oddEvenJumps(vector<int>& A) {
	vector<vector<bool>>fuck;
	int count = 0, minn, maxx, temp1, temp2;
	fuck.resize(2);
	fuck[0].resize(A.size(),0);
	fuck[1].resize(A.size(),0);
	fuck[0][A.size() - 1] = 1;
	fuck[1][A.size() - 1] = 1;
	for (int i = A.size() - 2; i >= 0; i--) {
		minn = 100001;
		maxx = -1;
		for (int k = 1; i + k < A.size(); k++) {
			if (A[i] <= A[i+k]&&A[i + k] < minn) {
				minn = A[i + k];
				temp1 = i + k;
			}
			if (A[i] >= A[i+k]&&A[i + k] > maxx) {
				maxx = A[i + k];
				temp2 = i + k;
			}
		}
		if (minn < 100001) {
			if (fuck[0][temp1] == 1)
				fuck[1][i] = 1;
		}
		if (maxx > -1) {
			if (fuck[1][temp2] == 1)
				fuck[0][i] = 1;
		}
	}
       for (int i = 0; i < A.size(); i++) {
			if (fuck[1][i] == 1){
                count++;
            }
		}
	return count;
}
};