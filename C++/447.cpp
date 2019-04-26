__________________________________________________________________________________________________
sample 148 ms submission
class Solution {
public:
    #define HASH_SIZE 1000
    struct HashNode {
        int val = 0;
        int count = 0;
        HashNode* next = NULL;
    } hashMap[HASH_SIZE];
    
    void add(int key) {
        int index = key%HASH_SIZE;
        struct HashNode* p = &hashMap[index];
        while (p->val != key && p->val != 0) {
            if (p->next == NULL) {
                p->next = new HashNode();
                p = p->next;
                break;
            }
            p = p->next;
        }
        p->val = key;
        p->count++;
    }
    
    int getDist(pair<int,int> a, pair<int,int> b) {
        int first = a.first-b.first;
        int second = a.second-b.second;
        return first*first+second*second;
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        int n = points.size();
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < HASH_SIZE; j++) {
                hashMap[j].val = hashMap[j].count = 0;
                hashMap[j].next = NULL;
            }
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                add(getDist(points[i], points[j]));
            }
            for (int j = 0; j < HASH_SIZE; j++) {
                struct HashNode* p = &hashMap[j];
                while (p) {
                    ret += (p->count * (p->count-1));
                    p = p->next;
                }
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 9944 kb submission
class Solution {
public:
    int getDist(pair<int,int> a, pair<int,int> b) {
        int first = a.first-b.first;
        int second = a.second-b.second;
        return first*first+second*second;
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        int n = points.size();
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = getDist(points[i], points[j]);
            }
        }
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                for (int k = j+1; k < points.size(); k++) {
                    if (i == k) continue;
                    if (dist[i][j] == dist[i][k])
                        ret+=2;
                }
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
