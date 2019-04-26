__________________________________________________________________________________________________
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }
    
    void serializeHelper(Node* node, string& res) {
        if (!node) res += "#";
        else {
            res += to_string(node->val) + " " + to_string(node->children.size()) + " ";
            for (auto child : node->children) {
                serializeHelper(child, res);
            }
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    Node* deserializeHelper(istringstream& iss) {
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *node = new Node(stoi(val), {});
        for (int i = 0; i < stoi(size); ++i) {
            node->children.push_back(deserializeHelper(iss));
        }
        return node;
    }
};
__________________________________________________________________________________________________
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "#";
        string res;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            res += to_string(t->val) + " " + to_string(t->children.size()) + " ";
            for (Node *child : t->children) {
                q.push(child);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        queue<Node*> qNode;
        queue<int> qSize;
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *res = new Node(stoi(val), {}), *cur = res;
        qNode.push(cur);
        qSize.push(stoi(size));
        while (!qNode.empty()) {
            Node *t = qNode.front(); qNode.pop();
            int len = qSize.front(); qSize.pop();
            for (int i = 0; i < len; ++i) {
                if (!(iss >> val)) break;
                if (!(iss >> size)) break;
                cur = new Node(stoi(val), {});
                qNode.push(cur);
                qSize.push(stoi(size));
                t->children.push_back(cur);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
