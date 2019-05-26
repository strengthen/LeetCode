__________________________________________________________________________________________________
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=2) return barcodes;
		/* maintain a hash table to record value's counter , and sort the hash table */
        unordered_map<int,int> mymap;
        for(int I : barcodes) mymap[I]++;
        vector<std::pair<int,int>> map_pair(mymap.begin(),mymap.end());
        sort(map_pair.begin(),map_pair.end(),[](auto &it1, auto &it2){
           return it1.second > it2.second; 
        });
        vector<int> res(barcodes.size()); // actually we can re-use vector<int>barcodes
        int map_idx = 0;
        for(int i = 0, cnt = 0 ; cnt < barcodes.size() ; i+=2,cnt++){
            res[i] = map_pair[map_idx].first;
            if(--map_pair[map_idx].second == 0)
                map_idx++;
            if(i+2 >= barcodes.size()) // meet upper bound
                i = -1; // next round will be i = 1
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
