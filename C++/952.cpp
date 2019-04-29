__________________________________________________________________________________________________
sample 76 ms submission
#include<string.h>

int a[100010], p[100010], num;

int Prime(int N, int *a, int *p, int &num) {
    int i, j;
    memset(a, 0, N * sizeof(a[0]));
    num = 0;
    for(i = 2; i < N; ++i) {
        if(!a[i]) a[i] = p[num++] = i;
        for(j = 0; j < num && i * p[j] < N; ++j) {
            a[i * p[j]] = p[j];
            if(!(i % p[j])) break;
        }
    }
    return num;
}

int _num = Prime(100010, a, p, num);


int bc[20010], h[100010];

int get(int x) {
	if(bc[x] == -1) return x;
	return bc[x] = get(bc[x]);
}

void uni(int x, int y) {
	x = get(x);
	y = get(y);
	if(x == y) return;
	bc[y] = x;
}


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
		memset(bc, -1, sizeof(bc[0]) * n);
		memset(h, -1, sizeof(h));
		for(int i = 0; i < n; ++i) {
			int x = A[i];
			while(x != 1) {
				if(h[a[x]] == -1) {
					h[a[x]] = i;
				} else {
					uni(h[a[x]], i);
				}
				x /= a[x];
			}
		}
		memset(h, 0, sizeof(h[0]) * n);
		int ans = 1;
		for(int i = 0; i < n; ++i) {
			int tmp = ++h[get(i)];
			if(tmp > ans) ans = tmp;
		}
		return ans;
    }
};
__________________________________________________________________________________________________
sample 12044 kb submission
class Solution {
public:
    
    int fa[100001];
    
    int find(int x) { return fa[x] <= 0 ? x : fa[x] = find(fa[x]); }
    
    void unite(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a == b) return;
        if (-fa[a] > -fa[b]) swap(a, b);
        fa[b] += fa[a];
        fa[a] = b;
    }
    
    int largestComponentSize(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) fa[A[i]]--;    
        int ans = 0;
        for (int i = 2; i < 100001; i++) {
            int lst = i;
            for (int j = i + i; j < 100001; j += i) if (fa[j]) {
                unite(lst, j);
                lst = j;
                ans = max(ans, -fa[find(j)]);
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
