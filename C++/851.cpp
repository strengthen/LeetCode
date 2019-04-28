__________________________________________________________________________________________________
sample 68 ms submission
static int x = [](){std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0;}();

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();        
        vector<int> quietest_richer(n);

        for (int i = 0; i < n; i++)
            quietest_richer[i] = i;
        
        for (int i = richer.size() - 1; i >= 0; i--) {
            updateQuietRicher(richer[i][0], richer[i][1], 
                              richer, quiet, quietest_richer);       
        }

        for (int i = 0, l = richer.size(); i < l; i++) {
            updateQuietRicher(richer[i][0], richer[i][1], 
                              richer, quiet, quietest_richer);
        }
        
        return quietest_richer;
    }
private:
    void updateQuietRicher(int r, int p, vector<vector<int>> &richer, 
                           vector<int> &quiet, vector<int> &quietest_richer) {
        int qr = quietest_richer[r];
        int qrq = quiet[qr];

        if (quiet[r] < qrq) {
            quietest_richer[r] = r;
            qrq = quiet[r];
            qr = r;
        }
            
        int qp = quietest_richer[p];
        int qpq = quiet[qp];
        if (quiet[p] < qrq) {
            if (qpq > quiet[p])
                quietest_richer[p] = p;
        } else {
            if (qrq < qpq)
                quietest_richer[p] = qr;
        }        
    }
};
__________________________________________________________________________________________________
sample 29564 kb submission
class Solution {
public:
    void dfs(vector<vector<int>>& richer, vector<int>& quiet, int p, vector<int>& res) {
        if (res[p]>=0) return;
        for (int i=0; i<richer.size(); ++i) {
            int idx=richer[i][0];
            if (richer[i][1]==p) {
                dfs(richer,quiet,idx,res);
                if (res[p]<0 || quiet[res[idx]]<quiet[res[p]]) res[p]=res[idx];
            }
        }
        if (res[p]<0 || quiet[res[p]]>quiet[p]) res[p]=p;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> res(quiet.size(),-1);
        for (int i=0; i<quiet.size(); ++i) {
            if (res[i]>=0) continue;
            dfs(richer,quiet,i,res);
        }
        return res;        
    }
};
__________________________________________________________________________________________________
