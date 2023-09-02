class Node{
public:
    int key, value, freq;
    Node* next;
    Node* prev;
    
    Node(int key, int val){
        this->key=key;
        this->value=val;
        freq=1;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    int size;
    
    List(){
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        size=0;
        
        head->next=tail;
        tail->prev=head;
    }
    
    void addfront(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
        
        size++;
    }
    void removenode(Node* node){
        Node* delprev=node->prev;
        Node* delnext=node->next;
        
        delprev->next=delnext;
        delnext->prev=delprev;
        
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, List*> freqlistmap;
    unordered_map<int, Node*> keynode;
    int currsize;
    int maxsize;
    int minfreq;
    
    LFUCache(int capacity) {
        maxsize=capacity;
        currsize=0;
        minfreq=0;
    }
    
    void updatefreqlistmap(Node* node){
        keynode.erase(node->key);
        freqlistmap[node->freq]->removenode(node);
        
        if(node->freq == minfreq && freqlistmap[node->freq]->size == 0)
            minfreq++;
        
        List* nexthigherfreqlist=new List();
        if(freqlistmap.find(node->freq + 1) != freqlistmap.end())
            nexthigherfreqlist=freqlistmap[node->freq + 1];
        
        node->freq++;
        nexthigherfreqlist->addfront(node);
        freqlistmap[node->freq]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key) != keynode.end()){
            Node* node=keynode[key];
            int ans=node->value;
            updatefreqlistmap(node);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0)
            return;
        if(keynode.find(key) != keynode.end()){
            Node* node=keynode[key];
            node->value=value;
            updatefreqlistmap(node);
        }
        else{
            if(currsize == maxsize){
                List* list=freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                list->removenode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1;
            
            List* freqlist=new List();
            if(freqlistmap.find(minfreq) != freqlistmap.end())
                freqlist=freqlistmap[minfreq];

            Node* node = new Node(key, value);
            freqlist->addfront(node);
            freqlistmap[node->freq]=freqlist;
            keynode[node->key]=node;   
        }
    }
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */