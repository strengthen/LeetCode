__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int hash[10001]={0},i,x=0,cnt=0;
        vector<int> v;
        for(i=0;i<deck.size();i++){
            hash[deck[i]]++;
        }
        for(i=0;i<10001;i++){
            if(hash[i]==0)
                continue;
            v.push_back(hash[i]);
        }
        int g=*(v.begin());
        for(auto it: v)
            g=__gcd(it,g);
        return g>1;
    }
};
__________________________________________________________________________________________________
sample 9976 kb submission

//time: O(n(logn)^2)
//space: O(n)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        const int arrayLen = 10000;
        array<int, arrayLen> count{};
        for(int d:deck){++count[d];}
        
        int  g =-1;
        for(int i = 0; i<arrayLen; ++i){
            if(count[i]!=0){
                if(g==-1){
                    g = count[i];
                }
                else{
                    g = gcd(g, count[i]);
                }
            }
        }
        return g>=2;
          
    }

    //while_loop_gcd
    int gcd(int x, int y){
        int small = x<y? x:y;
        int large = x>y? x:y;
        int temp;
        while(small!=0){
            temp = small;
            small = large%small;
            large = temp;
        }
        return large;
    }
};
__________________________________________________________________________________________________
