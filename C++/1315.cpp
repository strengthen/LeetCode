__________________________________________________________________________________________________
sample 24 ms submission
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Containers
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Input/Output
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

// Other
#include <algorithm>
#include <bitset>
#include <chrono>
#include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

// ==================================================

using namespace std;

// constants
const double EPS = 1e-9;
const int MOD = 1000000007;

// type alias
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvi = vector<vector<int>>;
using vvs = vector<vector<string>>;
using mii = map<int, int>;
using mci = map<char, int>;
using si = set<int>;
using spii = set<pair<int, int>>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using umsi = unordered_map<string, int>;
using usi = unordered_set<int>;
using usc = unordered_set<char>;
using uss = unordered_set<string>;
using vpii = vector<pair<int, int>>;

typedef struct TreeNode TreeNode;
using ptn = TreeNode *;
using tn = TreeNode;

// ==================================================

// fast IO
static auto __speedup__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ==================================================

// some macro for less typing
#define qfor(i, n) for (int i = 0; i < n; i++)            //[0, n)
#define qforr(i, n) for (int i = n - 1; i >= 0; --i)      // reverse [0, n)
#define qforup(i, a, b) for (int i = a; i < b; ++i)        // [a, b)
#define qfordown(i, a, b) for (int i = b - 1; i >= a; --i) // reverse [a, b)
#define qunfold(i, arr) for (auto &i : arr)

#define INF 0x3f3f3f3f
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define qall(v) v.begin(), v.end()
#define qsize(v) (int)v.size()
#define qsort(v) sort(v.begin(), v.end())
#define rqsort(v) sort(v.rbegin(), v.rend())
#define qreverse(v) reverse(v.begin(), v.end())

// int to string 
string itos(int n) { return to_string(n); }
// char to string 
string ctos(char c){ return string(1, c); };

inline string upper(string s) {
  string t(s);
  transform(t.begin(), t.end(), t.begin(), ::toupper);
  return t;
}
inline string lower(string s) {
  string t(s);
  transform(t.begin(), t.end(), t.begin(), ::tolower);
  return t;
}

int direction[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                       {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// ==================================================
// ** math function **

// Get all primes under n (inclusive)
vector<int> sieve_primes(int n) {
  vector<int> tables;
  vector<bool> bools(n + 1, true);
  for (int i = 2; i <= n; i++) {
    if (bools[i]) {
      tables.push_back(i);
      for (int j = i << 1; j <= n; j += i)
        bools[j] = false;
    }
  }
  return tables;
}

bool isprime(int x) {
  if (x < 4)
    return x > 1;

  int n = int(sqrt(x)) + 1;
  vector<bool> bools(n + 1, true);
  for (int i = 2; i <= n; i++) {
    if (bools[i]) {
      if (x % i == 0)
        return false;
      for (int j = i << 1; j <= n; j += i)
        bools[j] = false;
    }
  }
  return true;
}


// double equals
bool eq(double a, double b) { return fabs(a - b) < EPS; }

double random_() {
  // generate random number in [0, 1]
  return double(rand()) / RAND_MAX;
}

int random_(int m) {
  // generate random int between [0, m - 1]
  return int(random_() * (m - 1) + 0.5);
}

// ======================================================
// CONVENIENT FUNCTIONS
// whether s is substring of t
bool is_sub(string s, string t) {
  if (s.size() > t.size())
    return false;

  int i = 0, j = 0;
  while (i < s.size() && j < t.size())
    if (s[i] == t[j++])
      i++;

  return (i == s.size());
}

bool isPalindrome(string str) {
  int i = 0, j = str.size() - 1;
  while (i < j)
    if (str[i++] != str[j--])
      return false;
  return true;
}

string join(vs &arr, string del = " ") {
  string res;
  for (auto &s : arr)
    res += s + del;
  return res.substr(0, res.size() - 1);
}

// sort vector of vector<int> by first element
void sort_by_last(vvi &a) {
  sort(a.begin(), a.end(),
       [](const vi &p, const vi &q) { return p.back() < q.back(); });
}

// quick sum, product, max, min elemnt of a vector<int>
// int sum_(vi &a) { return accumulate(a.begin(), a.end(), 0); } quick sum
template <class T> T qsum(const vector<T> &ns) {
  T r = 0;
  for (auto n : ns)
    r += n;
  return r;
}

// Get sum of interval [i, j)
template <class T> T partsum(const vector<T> &ns, int i, int j) {
  T r = 0;
  for (size_t o = i; o < j ; o ++)
    r += ns[o]; 
  return r;
}

template <class T> void reverse_(const vector<T> &vect) {
  reverse(vect.begin(), vect.end());
}

void reverseStr(string &s) { reverse(s.begin(), s.end()); }

unsigned long long product(vector<int> &a) {
  unsigned long long res = 1;
  for (auto &i : a)
    res *= i;
  return res;
}

int vecmax(vector<int>& arr) { return *max_element(arr.begin(), arr.end()); }
int vecmin(vector<int>& arr) { return *min_element(arr.begin(), arr.end()); }

template <class T> unordered_map<T, int> counter(vector<T> &a) {
  unordered_map<T, int> c = {};
  for (auto &x : a) ++c[x];
  return c;
}

// Find the most common element in a vector
template <class T> T most_common(vector<T> &arr) {
  T res = arr[0];
  int cter = 0;
  unordered_map<T, int> um;
  for (auto i : arr) {
    um[i]++;
    if (um[i] > cter) {
      res = i, cter = um[i];
    }
  }
  return res;
}

bool isodd(int n) { return n % 2 == 1; }
bool iseven(int n) { return n % 2 == 0; }

// whether two rectangles a = {x1,x2,y1,y2} and b = {s1,s2,t1,t2} overlap
bool isRectangleOverlap(vector<int> &a, vector<int> &b) {
  if (a[0] > b[0])
    return isRectangleOverlap(b, a);
  return !(a[2] <= b[0] || a[3] <= b[1] || a[1] >= b[3]);
}

// whether a key in a map
template <class K, class V> bool exist(unordered_map<K, V> &m, K key) {
  return m.find(key) != m.end();
}


template <class K, class V> bool exist(map<K, V> &m, K key) {
  return m.find(key) != m.end();
}

template <class K> bool exist(unordered_set<K> &m, K key) {
  return m.find(key) != m.end();
}

template <class K> bool exist(set<K> &m, K key) {
  return m.find(key) != m.end();
}



string lcs(string s, string t) {
  int m = s.size(), n = t.size(), L[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (s[i - 1] == t[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);

  string res(L[m][n], '#');
  int i = m, j = n, index = L[m][n];

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1])
      res[index - 1] = s[i - 1], index--, i--, j--;
    else if (L[i - 1][j] > L[i][j - 1])
      i--;
    else
      j--;
  }
  return res;
}

// shortest common supersequence, e.e., scs("abcde", "pkqcze") = "abpkqcdze"
string scs(string s, string t) {
  int m = s.size(), n = t.size(), L[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (s[i - 1] == t[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);

  string res(m + n - L[m][n], '#');
  int i = m, j = n, index = m + n - L[m][n];

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1])
      res[--index] = s[--i], j--;
    else if (L[i - 1][j] > L[i][j - 1])
      res[--index] = s[--i];
    else
      res[--index] = t[--j];
  }

  if (i + j == 0)
    return res;
  else if (j > 0)
    while (j > 0)
      res[--index] = t[--j];
  else
    while (i > 0)
      res[--index] = s[--i];
  return res;
}

// =========================================================================
// This class represents a directed graph using adjacency list representation
class Graph {
  int V;          // No. of vertices
  list<pii> *adj; // In a weighted graph, we need to store vertex and weight
                  // pair for every edge

public:
  Graph(int V); // Constructor
  void addEdge(int u, int v, int w);
  vi shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V) {
  this->V = V;
  adj = new list<pii>[V];
}

void Graph::addEdge(int u, int v, int w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

// Get shortest paths from src to all other vertices using Dijkstra's algorithm
vector<int> Graph::shortestPath(int src) {
  // Create a priority queue to store vertices that
  // are being preprocessed. This is weird syntax in C++.
  // Refer below link for details of this syntax
  // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  vi dist(V, INF);

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &i : adj[u]) {
      int v = i.first;
      int weight = i.second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  // Print shortest distances stored in dist[]
  // printf("Vertex   Distance from Source\n");
  // for (int i = 0; i < V; ++i)
  //   printf("%d \t\t %d\n", i, dist[i]);

  return dist;
}

template <typename T1, typename T2> void printMap(unordered_map<T1, T2> &m) {
  for (auto iter = m.begin(); iter != m.end(); iter++)
    cout << iter->first << ", " << iter->second << endl;
}

template <typename T1, typename T2> void printMap(map<T1, T2> &m) {
  for (auto iter = m.begin(); iter != m.end(); iter++)
    cout << iter->first << ", " << iter->second << endl;
}
// ==================================================

#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
#endif

TreeNode *growTreeFromList(vector<int> &arr) {
  if (arr.empty())
    return nullptr;
  TreeNode *root = new TreeNode(arr[0]);
  int children = 0, i = 1;
  queue<TreeNode *> q;
  q.push(root);
  while (i < arr.size()) {
    if (children == 2) {
      q.pop();
      children = 0;
    }
    if (arr[i] < INT_MAX) {
      TreeNode *c = new TreeNode(arr[i]);
      if (children == 0)
        q.front()->left = c;
      else
        q.front()->right = c;
      q.push(c);
    }
    ++i, ++children;
  }
  return root;
}

// return level's order travesal of tree.. 
// e.g., [3,9,20,null,null,15,7] to [[3], [9, 20], [15, 7]]
vector<vector<int>> treeToList(TreeNode *root) {
    vector<vector<int>> tower;
    queue<pair<TreeNode *, int>> jobs;
    jobs.push(mp(root, 0));
    
    while (!jobs.empty()) {
      pair<TreeNode *, int> j = jobs.front();
      jobs.pop();
      
      if (j.first == nullptr) continue;
      if (tower.size() <= j.second) tower.pb(vi{j.first->val});
      else tower[j.second].pb(j.first->val);

      jobs.push(mp(j.first->left, j.second + 1));
      jobs.push(mp(j.first->right, j.second + 1));
    }
    return tower;
  }

// Get the depth of Tree
int getTreeDepth(TreeNode *root) {
  if (!root)
    return 0;
  return 1 + max(getTreeDepth(root->left), getTreeDepth(root->right));
}

int bisect_left(vector<int>& arr, int target) {
  int lo = 0, hi = arr.size() - 1, mid ; 
  while (lo < hi) {
      mid = (lo + hi) / 2; 
      if (arr[mid] >= target) hi = mid; 
      else lo = mid + 1 ; 
  }
  return lo;
}

// Find the index of the first number in sorted nums, that is larger than target
int bisect_right(vector<int> &nums, int target) {
  int i = 0, j = nums.size() - 1, mid = 0;
  while (i < j) {
    mid = ceil((i + j) * 1.0 / 2);
    if (nums[mid] > target)
      j = mid - 1;
    else
      i = mid;
  }
  return nums[j] > target ? j : j + 1;
}

bool in(string str1, string str2) { return str1.find(str2) != string::npos; }

// lowest common ancestor of two nodes(values are distinct)
TreeNode *lca(TreeNode *r, int pv, int qv) {
  if (r == NULL || r->val == pv || r->val == qv)
    return r;
  TreeNode *left = lca(r->left, pv, qv);
  TreeNode *right = lca(r->right, pv, qv);
  return left == NULL ? right : (right == NULL ? left : r);
};

/* Travel through a tree and return a list of list, lis[i] is the values of all
 * nodes with depth i
 */
vector<vector<int>> valuesOfTree(TreeNode *r) {
  vector<vector<int>> res;
  stack<pair<int, TreeNode *>> stack;
  stack.push(make_pair(0, r));

  while (!stack.empty()) {
    pair<int, TreeNode *> cur = stack.top();
    stack.pop();
    TreeNode *tn = cur.second;
    if (tn == NULL)
      continue;

    int depth = cur.first;
    if (res.size() <= depth)
      res.push_back({});
    res[depth].emplace_back(tn->val);
    stack.push(make_pair(depth + 1, tn->right));
    stack.push(make_pair(depth + 1, tn->left));
  }
  return res;
}

ListNode *reverseList(ListNode *head) {
  if (!head)
    return head;
  ListNode *pre, *cur;
  pre = NULL;
  while (head) {
    cur = head->next;
    head->next = pre;
    pre = head;
    head = cur;
  }
  return pre;
}

int getListLen(ListNode *head) {
  int len = 0;
  ListNode *dummy = head;
  while (dummy) {
    len++;
    dummy = dummy->next;
  }
  return len;
}

int getLastListValue(ListNode *head) {
  int value = -1;
  ListNode *dummy = head;
  while (dummy) {
    value = dummy->val;
    dummy = dummy->next;
  }
  return value;
}

bool isSortedList(ListNode *head) {
  if (!head)
    return true;
  ListNode *dummy = head;
  while (head->next) {
    if (head->val > head->next->val)
      return false;
    head = head->next;
  }
  return true;
}

/* Translate an array of int to ListNode */
ListNode *arrayToListNode(vector<int> &arr) {
  ListNode *head, *pre;
  if (arr.size() == 0)
    return head;
  head = new ListNode(-0x3f3f3f3f);
  pre = head;
  for (auto &i : arr) {
    ListNode *tmp = new ListNode(i);
    pre->next = tmp;
    pre = tmp;
  }
  return head->next;
}

// Extract the values of nodes into a vector
vector<int> listnodeToArray(ListNode *head) {
  vector<int> vs;
  ListNode *tmp = head;
  while (tmp) {
    vs.push_back(tmp->val);
    tmp = tmp->next;
  }
  return vs;
}

/* Transfer a lowercase string to a vector of int,
each element counting the char in the string */
vector<int> char_counter(string chars) {
  vector<int> cc(26, 0);
  for (auto &c : chars)
    cc[c - 'a'] += 1;
  return cc;
}

vector<int> addTwoVector(vector<int> &a, vector<int> &b) {
  // Add single-digit-numbers in two vectors, the most significant digit comes
  // at array[0] E.g., [5, 6] + [1, 5, 8] = [2, 1, 4] To guarantee the size of b
  // is no smaller than a
  if (a.size() > b.size())
    return addTwoVector(b, a);
  vector<int> res;
  int i = a.size() - 1, j = b.size() - 1, carry = 0;
  while (j >= 0) {
    int s = i >= 0 ? (a[i--] + b[j--] + carry) : (b[j--] + carry);
    res.push_back(s % 10);
    carry = s / 10;
  }
  if (carry == 1)
    res.push_back(1);
  reverse(res.begin(), res.end());
  return res;
}

int last(vector<int> &v) { return v[v.size() - 1]; }

int find(int x, vector<int> &p) {
  if (x != p[x])
    p[x] = find(p[x], p);
  return p[x];
}

// Do not use union, since it's a keyword of CPP
void merge(int x, int y, vector<int> &p) { p[find(x, p)] = find(y, p); }

// print all combination of size r in an array of size n
// void combinationUtil(vector<int> &arr, int r, int index, int data[], int i);

template <class T>
void makeCombiUtil(vector<vector<T>> &ans, vector<T> &arr, vector<T> &tmp,
                   int left, int k) {
  // Pushing this vector to a vector of vector
  if (k == 0) {
    ans.push_back(tmp);
    return;
  }

  // i iterates from 0 to arr.size() - 1. First time left will be 0
  for (int i = left; i < arr.size(); ++i) {
    tmp.push_back(arr[i]);
    makeCombiUtil(ans, arr, tmp, i + 1, k - 1);
    // Popping out last inserted element from the vector
    tmp.pop_back();
  }
}


// Get prefix sum of matrix such that res[i][j] = sum(matrix[0..i-1][0..j-1])
// for i >= 1, j >= 1
vector<vector<int>> getPrefixSum(vvi & mat){
  int m = mat.size(), n = mat[0].size(); 
  vector<vector<int>> res(m+1, vector<int>(n+1, 0)); 
  for (size_t i = 1; i <= m; ++i)
    for (size_t j = 1; j <= n; ++j)
      res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + mat[i-1][j-1]; 
    return res; 
}

// Converting string [[1,2], [3, 4]] to vector(of vector) {{1, 2}, {3, 4}}
vector<vector<int>> extractMatrixFromString(string s){
	vector<vector<int>> res; 
	int carry = INT_MIN;
	for (size_t i = 1; i < s.size() - 1; ++i) {
		if (s[i] == '[') res.push_back(vector<int>{});
		while (isdigit(s[i])) carry = max(carry, 0) * 10 + (s[i++] - '0');
		if (carry > INT_MIN) res.back().push_back(carry); 
		carry = INT_MIN;  
	}
	return res; 
}

class Solution {
public:
    int rec(TreeNode* n, int p, int gp){
      if (n == nullptr) return 0; 
      int ans = gp == 0 ? n->val : 0; 
      ans += rec(n->left, n->val % 2, p);
      ans += rec(n->right, n->val % 2, p);
      return ans ;
    }

    int sumEvenGrandparent(TreeNode* root) {
      return rec(root, 1, 1);
    }
};



static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL);return 0; }();
__________________________________________________________________________________________________
sample 28 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int s = 0;
    void calculateSum(TreeNode* root, int parent, int gp){
        if(gp!=-1 && gp%2==0) s+=root->val;
        if(root->left) calculateSum(root->left,root->val,parent);
        if(root->right) calculateSum(root->right,root->val,parent);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        calculateSum(root,-1,-1);
        return s;
    }
};

static int accelerate = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
sample 32 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        sum=0;
        dfs(root, NULL, NULL);
        return sum;
    }
private:
    void dfs(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if (root==NULL) return;
        if (grandparent!=NULL && grandparent->val%2==0) sum+=root->val;
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }
    
    int sum;
};