__________________________________________________________________________________________________
sample 116 ms submission
static auto magic = []() {ios_base::sync_with_stdio(false); cin.tie(nullptr); return false;}();

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(),folder.end());
        vector<string> result;
        for(string &s:folder)
            if(result.empty()||result.back().compare(0,result.back().length(),s,0,result.back().length())!=0||s[result.back().length()]!='/') //Check if 1. This is the first string, 2.parent at back is not the parent of `s` by comparing.
                result.push_back(s);                                   //3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
        return result;
    }
};
__________________________________________________________________________________________________
sample 120 ms submission
struct Node {
    string my;
    int cnt;
    Node(): cnt(0) {}
    Node(const string& s): my(s), cnt(0) {}
};

struct MyTreeNode {
    Node my;
    unordered_map<string, MyTreeNode*> nexts;
    MyTreeNode(const string& s): my(s) {}
    MyTreeNode() {}
};
class Solution {
    string join(vector<string>& s) {
        string r = "/";
        for (string& ss : s) {
            r += ss;
            r += "/";
        }
        r.pop_back();
        return r;
    }
    void traverse(MyTreeNode& node, vector<string>& result, string& tmp) {
        tmp += "/";
        tmp += node.my.my;
        if (node.my.cnt == 1) {
            // join by "/"
            result.push_back(tmp);
        } else {
            for (auto& next : node.nexts) {
                traverse(*next.second, result, tmp);
            }
            
        }
        tmp.resize(tmp.size() - 1 - node.my.my.size());
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        MyTreeNode root;
        for (string& s : folder) {
            int size = s.size();
            int i = 1;
            MyTreeNode* cur = &root;
            while (i < size) {
                int j = i;
                if (cur->my.cnt == 1) break;
                while (j < size && s[j] != '/') ++j;
                string n = s.substr(i, j - i);
                if (cur->nexts.find(n) != cur->nexts.end()) {
                    cur = cur->nexts[n];
                } else {
                    cur->nexts[n] = new MyTreeNode(n);
                    cur = cur->nexts[n];
                }
                
                i = j + 1;
            }
            cur->my.cnt = 1;
        }
        vector<string> result;
        string tmp;
        for (auto& node : root.nexts) {
            traverse(*node.second, result, tmp);
        }
        return result;
        
    }
};

auto _ = []() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    return 0;
}();
__________________________________________________________________________________________________
