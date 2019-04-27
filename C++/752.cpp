__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> visited(deadends.begin(), deadends.end());
    if (visited.find("0000") != visited.end() || visited.find(target) != visited.end()) return -1;
    vector<string> res;
    for(int i=0; i < target.length(); ++i){
        string tmp = target;
        char last = target[i] == '0' ? '9' : target[i] - 1;
        swap(tmp[i], last);
        if(visited.count(tmp) == 0) res.push_back(tmp);
        char next = target[i] == '9' ? '0' : target[i] + 1;
        swap(tmp[i], next);
        if(visited.count(tmp) == 0) res.push_back(tmp);
    }
    if(res.empty()) return -1;
    int ret = 40;
    for(auto& r : res){
        int temp = 0;
        for(int i = 0; i < 4; ++i){
            int turns = r[i] - '0';
            if(turns > 5)  turns = 10 - turns;
            temp += turns;
        }
        if(temp < ret) ret = temp;
    }
    return ret + 1;
}

};
__________________________________________________________________________________________________
sample 10184 kb submission
static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
       // p：0：往上拨， ：往下拨
    int Op(int value, int pos, int p)
    {
        if (p == 1) {
            // 往下拨
            if (pos == 0) {
                value = value/10*10 + (value%10+1)%10;
            }
            else if (pos == 1) {
                value = value/100*100 + (value%100+10)%100;
            }
            else if (pos == 2) {
                value = value/1000*1000 + (value%1000+100)%1000;
            }
            else if (pos == 3) {
                value = value/10000*10000 + (value%10000+1000)%10000;
            }
        }
        else {
            // 往上拨
            if (pos == 0) {
                if (value%10 == 0) {
                    value += 9;
                }
                else {
                    value -= 1;
                }
            }
            else if (pos == 1) {
                if ((value/10)%10 == 0) {
                    value += 90;
                }
                else {
                    value = value - 10;
                }
            }
            else if (pos == 2) {
                if ((value/100)%10 == 0) {
                    value += 900;
                }
                else {
                    value  = value - 100;
                }
            }
            else if (pos == 3) {
                if ((value/1000)%10 == 0) {
                    value += 9000;
                }
                else {
                    value = value - 1000;
                }
            }
        }
        return value;
    }
    
     int openLock(vector<string>& deadends, string target) {
         // unordered_set<string> sdeadends(deadends.begin(), deadends.end());
         // for (auto s : deadends) {
         //     sdeadends.insert(s);
         // }  

         // vector<bool> vecFlag(10000, false);
         bitset<10000> vecFlag;
         queue<int> qData;
         for (auto str : deadends) {
             vecFlag[atoi(str.c_str())] = 1;
         }
         int itarget = atoi(target.c_str());
         if (vecFlag[0] == 1) {
             return -1;
         }

//         queue<string> qData;
//         unordered_set<string> mData(deadends.begin(), deadends.end());
//        if (mData.count("0000")) {
//             return -1;
//         }
        int round = -1;
        qData.push(0);
        while (qData.empty() == false) {
            round++;
            int k = qData.size();
            for (; k>0; k--) {
                auto tNode = qData.front();
                qData.pop();
                for (int i=0; i<4; i++) {
                    for (int j=0; j<2; j++) {
                        auto ret = Op(tNode, i, j);
                        if (ret == itarget) {
                            return round+1;
                        }
                        // if (mData.count(ret) == 0) {
                        //     mData.insert(ret);
                        //     qData.push(ret);
                        // }
                        if (vecFlag[ret] == 0) {
                            vecFlag[ret] = 1;
                            qData.push(ret);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
__________________________________________________________________________________________________
