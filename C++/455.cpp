__________________________________________________________________________________________________
sample 20 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int partion(vector<int>& arr, int begin, int end){
        int base = arr[end-1];
        
        int i=begin;
        int j=end-1;
        
        while(i<j){
            while(i<j && arr[i]<=base)
                i++;
            arr[j] = arr[i];
            while(i<j && arr[j]>=base)
                j--;
            arr[i] = arr[j];
        }
        arr[j] = base;
        return j;
    }
    
    void quick_sort(vector<int>& arr, int begin, int end){
        if(end - begin <= 1)
            return;
        
        int pivot = partion(arr, begin, end);
        quick_sort(arr, begin, pivot);
        quick_sort(arr, pivot+1, end);
    }
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        quick_sort(g, 0, g.size());
        quick_sort(s, 0, s.size());
        
        int i = 0;
        int count = 0;
        
        for(int j:s){
            if(i >= g.size())
                break;
            if(j >= g[i]){
                count++;
                i++;
            }
        }
        
        return count;
    }
};
__________________________________________________________________________________________________
sample 10248 kb submission
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int s_pos = 0;
        
        if(s.size() == 0) return 0;
        
        for(int i = 0; i < g.size(); i++){
            int ch = g[i];
            if(ch<=s[s_pos]){
                s_pos++;
                if(s_pos == s.size()) break;
            }   
        }
        
        return s_pos;
    }
};

// Fast I/O
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
__________________________________________________________________________________________________
