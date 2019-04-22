__________________________________________________________________________________________________
4ms
int _=[](){ios::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
string minWindow(string s, string t) {
        std::array<int, 128> map{0};
        for(auto c: t) map[c]++;
        int counter=t.size(), left = 0, right = 0, d = INT_MAX, head = 0;
    
        while(right < s.size()){
            if(map[s[right]] > 0) {
                --counter;                
            }
            
            // Decrease values of map elements.
            --map[s[right]];
            ++right;
        
            // Reupdate the map untill all characters that are not in t are added back to the map (pay attention to --map[s[right]])
            while(counter == 0) {
                if((right - left) < d)  {
                    head = left;
                    d = right - head;
                };
                if(map[s[left]] == 0) counter++;
                ++map[s[left]];
                ++left;
                
            }  
        }
        return d == INT_MAX? "" : s.substr(head, d);
    }    
};
__________________________________________________________________________________________________
9300 kb
class Solution {
public:
    string minWindow(string s, string t) {   
        int i = 0;
        int j = 0;
        int world_map[128] = {0};
        for(auto & word : t)
            world_map[word]++;
        int table[128] = {0};
        int result_size = INT_MAX;
        bool full_cover = false;
        int start = 0;
        
        while(j < s.length()) {
            table[s[j]]++;
            if(!full_cover && world_map[s[j]]) {
                full_cover = true;
                for(auto & word : t) {
                    if(table[word] < world_map[word]) {
                        full_cover = false;
                        break;
                    }
                }
            }
            if(full_cover && j-i+1 < result_size) {
                result_size = j-i+1;
                start = i;
            }
            while(full_cover && table[s[i]] > world_map[s[i]]) {
                table[s[i]]--;
                i++;
                if(j-i+1 < result_size) {
                    result_size = j-i+1;
                    start = i;
                }
            }
            j++;
        }
        if(result_size == INT_MAX)
            return "";
        return s.substr(start, result_size);
    }
};
__________________________________________________________________________________________________
