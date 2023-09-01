class node{
  public:
    int key, value;
    node* next;
    node* prev;
    
    node(int key, int value){
        this->key=key;
        this->value=value;
    }
};

class LRUCache {
public:
    node* head;
    node* tail;
    unordered_map<int, node*> mpp;
    int cap;
    
    LRUCache(int capacity) {
        head=new node(-1, -1);
        tail=new node(-1, -1);
        
        cap=capacity;
        
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node* res=mpp[key];
            int ans=res->value;
            
            // mpp.erase(key);
            deletenode(res);
            addnode(res);
            // mpp[key]=head->next;
            
            return ans; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* existingnode=mpp[key];
            mpp.erase(key);
            deletenode(existingnode);
        }
        else if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mpp[key]=head->next;
    }
    
    
    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;       
        temp->prev=newnode;
    }
    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        
        delprev->next=delnext;
        delnext->prev=delprev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */