__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int N = A.size();
        vector<int> Asorted = A;
        vector<int> ans;
        std::sort(Asorted.begin(), Asorted.end(), [](int a, int b){return a > b; });
        for (int i = 0; i < N-1; i++){//use (N-1) instead of N to skip the smallest element
            int curLargest = Asorted[i];
            int pos = std::find(A.begin(), A.end(), curLargest) - A.begin();
            if (pos < N){
                ans.push_back(pos + 1);
                //reverse first 'pos' elements in A
                std::reverse(A.begin(), A.begin() + pos+1);
                ans.push_back(N - i);
                std::reverse(A.begin(), A.end()-i);
            }else{
                cerr << curLargest << " not found, pos=" << pos << endl;
                exit(1);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 9716 kb submission
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        if(A.size()==0){return vector<int>();}
        
        priority_queue<int,vector<int>,less<int>> pq(A.begin(), A.end());
        vector<int> result;
        int last = A.size()-1;
        
        while(last > 0)
        {
            if(A[last]!=pq.top())
            {
                for(int curr=last-1; curr>=0; --curr)
                {
                    if(A[curr]==pq.top())
                    {            
                        int i,j;
                        if(curr!=0)
                        {
                            i = 0;
                            j = curr;
                            
                            while(i < j) 
                            {
                                int temp = A[i];
                                A[i] = A[j];
                                A[j] = temp;
                                ++i; --j;
                            }
                            result.push_back(curr+1);
                        }
                        
                        i = 0;
                        j = last;
                        while(i < j)
                        {
                            int temp = A[i];
                            A[i] = A[j];
                            A[j] = temp;
                            ++i; --j;
                        }
                        result.push_back(last+1);
                        --last;                        
                        break;
                    }
                }
            }    
            else { --last; }//cout << "skipped last=[" << (last+1) << "]\n"; }
            pq.pop();
        }
        return result;
    }
};
__________________________________________________________________________________________________
