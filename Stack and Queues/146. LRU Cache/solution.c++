class LRUCache {
public:
    class Node{
    public:
        int key, val;
        Node* prev;
        Node* next; 
        
        Node(int k, int v){
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head; 
    }
    
    void addNode(Node* node){
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

    void deleteNode(Node* node){
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;    
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        addNode(node);
        return node -> val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node -> val = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        if(mp.size() == cap){
            Node* lru = tail -> prev;
            deleteNode(lru);
            mp.erase(lru -> key);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 

//tc :- 1 for get , 1 for put
//sc :- capacity