__________________________________________________________________________________________________
struct LogNode{
    int time;
    int A, B;
}logNode[10050];

inline bool cmp(const LogNode &a, const LogNode &b){
    return a.time<b.time;
}

class Solution {
public:
    int fa[550];
    
    int getFather(int x){
        return fa[x]=(fa[x]==x?x:getFather(fa[x]));
    }
    
    bool mergeFather(int x, int y){
        int fx=getFather(x), fy=getFather(y);
        if (fx==fy) return false;
        if (fx>fy) swap(fx, fy);
        fa[fx]=fy;
        return true;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int N) {
        for (int i=0; i<N; i++) fa[i]=i;
        
        int n=logs.size();
        for (int i=0; i<n; i++){
            logNode[i].time=logs[i][0];
            logNode[i].A=logs[i][1];
            logNode[i].B=logs[i][2];
        }
        
        sort(logNode, logNode+n, cmp);
        
        int cnt=N;
        for (int i=0; i<n; i++){
            int A=logNode[i].A, B=logNode[i].B;
            if (mergeFather(A, B)) --cnt;
            // printf("i:%d\n", cnt);
            if (cnt==1) return logNode[i].time;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
class Solution {
    int[] father;
	int find(int x) {
		if (father[x] == x) return x;
		return father[x] = find(father[x]);
	}
	
    public int earliestAcq(int[][] logs, int N) {
        father = new int[N];
        for (int i = 0; i < N; i++) father[i] = i;
        Arrays.sort(logs, new Comparator<int[]>() {

			@Override
			public int compare(int[] a, int[] b) {
				// TODO Auto-generated method stub
				return a[0] - b[0];
			}
        	
        });
        int res = 0;
        for (int i = 0; i < logs.length; i++) {
        		int a = logs[i][1];
        		int b = logs[i][2];
        		int fa = find(a);
        		int fb = find(b);
        		if (fa != fb) {
        			res = logs[i][0];
        			father[fa] = fb;
        		}
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) if (father[i] == i) cnt++;
        if (cnt > 1) return -1;
        return res;
    }    
}
__________________________________________________________________________________________________
