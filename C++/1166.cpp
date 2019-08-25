__________________________________________________________________________________________________
class FileSystem {
  vector<string> split(string& s,char c){
    int n=s.size();
    vector<string> res;
    for(int i=0;i<n;i++){
      if(s[i]==c) continue;
      string t;
      while(i<n&&s[i]!=c) t.push_back(s[i++]);
      res.push_back(t);
    }
    return res;
  }
public:
  struct Node{
    map<string, Node*> nxt;
    int value;
    Node(){}
    Node(int value):value(value){}
  };
  Node* root;
  FileSystem() {
    root=new Node();
  }

  bool create(string path, int value) {
    auto vs=split(path,'/');
    Node* pos=root;
    for(int i=0;i+1<(int)vs.size();i++)
      if(pos) pos=pos->nxt[vs[i]];
    if(!pos) return false;
    pos->nxt[vs.back()]=new Node(value);
    return true;
  }

  int get(string path) {
    auto vs=split(path,'/');
    Node* pos=root;
    for(int i=0;i<(int)vs.size();i++)
      if(pos) pos=pos->nxt[vs[i]];
    if(!pos) return -1;
    return pos->value;
  }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
