__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:

    vector<string> invalidTransactions(vector<string>& A) {
        int n = A.size();
        map < string, vector < pair < int, pair < string, int > > > > M;
        for(int i = 0;i < n;++i) {
            string x;
            vector < string > info;
            for(int j = 0;j <= A[i].size();++j) {
                if(A[i][j] == ',' or j == A[i].size()) {
                    info.push_back(x);
                    x.clear();
                } else {
                    x += A[i][j];
                }
            }
            int t = stoi(info[1]);
            int amount = stoi(info[2]);
            
            M[info[0]].push_back({t, {info[3], amount}});
        }
        
        vector < string > ans;
        for(auto it = M.begin();it != M.end();++it) {
            string name = it->first;
            auto &adj = it -> second;
            // sort(adj.begin(), adj.end());
            for(int j = 0;j < adj.size();++j) {
                if(adj[j].second.second > 1000) {
                    ans.push_back(name + "," + to_string(adj[j].first) + "," + to_string(adj[j].second.second) + "," + adj[j].second.first);
                    continue;
                }
                for(int k = 0;k < adj.size();++k) {
                    if(abs(adj[j].first - adj[k].first) < 61 and adj[j].second.first != adj[k].second.first) {
                        ans.push_back(name + "," + to_string(adj[j].first) + "," + to_string(adj[j].second.second) + "," + adj[j].second.first);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
struct Transaction {
    string name, city;
    int time, amount;
    string raw;
    Transaction() {}
    Transaction(string&_raw) {
        raw = _raw;
        istringstream iss(raw);
        string buf;
        getline(iss, name, ',');
        getline(iss, buf, ',');
        time = stoi(buf);
        getline(iss, buf, ',');
        amount = stoi(buf);
        getline(iss, city, ',');
        //cout << name << time << amount << city;
    }
} ;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> tr;
        vector<string> invalid_tr;
        for(auto transaction: transactions) {
            tr.push_back(Transaction(transaction));
        }
        for(int i=0; i<tr.size(); ++i) {
            bool invalid = false;
            if(tr[i].amount >= 1000) invalid = true;
            for(int j=0; !invalid && j<tr.size(); ++j) {
                if(i != j && tr[i].name == tr[j].name && tr[i].city != tr[j].city && abs(tr[j].time - tr[i].time) <= 60) {
                    invalid = true;
                }
            }
            if(invalid) invalid_tr.push_back(tr[i].raw);
        }
        return invalid_tr;
    }
};
__________________________________________________________________________________________________
