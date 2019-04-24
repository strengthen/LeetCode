__________________________________________________________________________________________________
88ms
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class LRUCache
{
    typedef struct ListNode
    {
        int item;
        int value;
        ListNode *prev;
        ListNode *next;
        
        ListNode(int item = -1, int value = -1) { prev = nullptr; next = nullptr; this->item = item; this->value = value; }
    }
    *List;
    
    unordered_map<int, List> hashmap;
    List head;
    List tail;
    int count;
    int capacity;
    
    void unplugNodeFromList(List node)
    {
        assert(node != nullptr);
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = node->next = nullptr;
        this->count -= 1;
    }
    
    void plugNodeOnTopOfList(List node)
    {
        assert(this->count < this->capacity);
        
        assert(node != nullptr);
        node->prev = this->head;
        node->next = this->head->next;
        this->head->next->prev = node;
        this->head->next = node;
        this->count += 1;
    }
    
    void updateNodePosition(List node)
    {
        this->unplugNodeFromList(node);
        this->plugNodeOnTopOfList(node);
    }
    
public:
    LRUCache(int capacity)
    {
        this->count = 0;
        this->capacity = capacity;
        this->head = new ListNode();
        this->tail = new ListNode();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    
    int get(int key)
    {
        auto it = hashmap.find(key);
        if (it == hashmap.end())
            return -1;
        
        List node = (*it).second;
        this->updateNodePosition(node);
        return node->value;
    }
    
    void put(int key, int value)
    {
        //cout << "Putting [" << key << ", " << value << "] ";
        auto it = hashmap.find(key);
        if (it == hashmap.end())
        {
            if (this->count == this->capacity)
            {
                // cout << "Removing " << this->tail->prev->value << " due to capacity" << endl;
                List toDelete = this->tail->prev;
                this->hashmap.erase(toDelete->item);
                this->unplugNodeFromList(toDelete);
                delete toDelete;
            }
            
            List toAdd = new ListNode(key, value);
            this->plugNodeOnTopOfList(toAdd);
            hashmap[key] = toAdd;
        }
        else
        {
            List node = (*it).second;
            node->value = value;
            this->updateNodePosition(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
__________________________________________________________________________________________________
36680 kb
class LRUCache {
private:
    struct Node {
        Node *next;
        int val;
        int key;
    };

    Node* MakeLinkedList(int capacity)
    {
        if(capacity <= 0)
            return nullptr;
        Node* start = new Node{nullptr, -1, 0};
        Node* current = start;

        while(--capacity > 0)
        {
            current->next = new Node{nullptr, -1, 0};
            current = current->next;
        }

        return start;
    }
    

    Node* begin;
    int m_capacity;
public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        begin = MakeLinkedList(capacity);
    }
    
    int get(int key) {
        Node* node = getNode(key);
        return node == nullptr ? -1 : node->val;
    }
    
    Node* getNode(int key)
    {
        Node* current = begin;
        
        while(current->key != key)
        {
            current = current->next;
            if(!current)
                return nullptr; // Cannot find key
        }
        
        if(current == begin)
            return current;
		
        MoveNodeToFront(current);
        return current;
    }
    
    Node* getLastNode()
    {
        Node* curr = begin;
		Node* prev = nullptr;
        if(m_capacity == 1)
			return begin;
		
		while(curr)
		{
			prev = curr;
			curr = curr->next;
		}
		
        return prev;
    }
    
    void MoveNodeToFront(Node* current)
    {
		Node* prev = nullptr;
		Node* move = begin;
		
		if(current == begin)
			return;
		
		while(move != current)
		{
			prev = move;
			move = move->next;
		}
		prev->next = current->next;
		current->next = begin;
		begin = current;
    }
    
    void put(int key, int value) {
        
        Node* node = getNode(key);
        if(node == nullptr)
        {
            Node* last = getLastNode();
            last->key = key;
            last->val = value;
            MoveNodeToFront(last);
        }
        else
        {
            node->val = value;
			MoveNodeToFront(node);
        }
		
    }
	
	void print()
	{
		Node* current = begin;
		while(current)
		{
			cout << current->val << " ";
			current = current->next;
		}
		cout << endl;
	}
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
__________________________________________________________________________________________________
