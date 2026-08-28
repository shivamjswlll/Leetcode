class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
class LRUCache{
public:
    int size;
    unordered_map<int,pair<int,Node*>> mp;
    Node* head,*tail;
    LRUCache(int capacity){
        this->size = capacity;
        tail = new Node(-1);
        head = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.contains(key)){
            int v = mp[key].first;
            Node* node = mp[key].second;
            DeleteNode(node);
            InsertAtHead(node);
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)){
            Node* node = mp[key].second;
            DeleteNode(node);
            InsertAtHead(node);
            mp[key].first = value;
        }
        else{
            Node* newNode = new Node(key);
            InsertAtHead(newNode);
            mp[key] = {value,newNode};
        }
        if(mp.size() > size){
            Node* deleteNode = tail->prev;
            int v = deleteNode->data;
            DeleteNode(deleteNode);
            mp.erase(v);
            delete deleteNode;
        }
    }
    void InsertAtHead(Node* node){
        Node* nxt = head->next;
        head->next = node;
        node->prev = head;
        node->next = nxt;
        nxt->prev = node;
    }
    void DeleteNode(Node* node){
        Node* nxt = node->next;
        Node* prv = node->prev;
        prv->next = nxt;
        nxt->prev = prv;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */