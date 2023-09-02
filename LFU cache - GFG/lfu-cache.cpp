//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Node{
public:
    int key, value, freq;
    Node* next;
    Node* prev;
    
    Node(int key, int value){
        this->key=key;
        this->value=value;
        freq=1;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    int size;
    
    List(){
        size=0;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
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
    unordered_map<int, Node*> keynode;
    unordered_map<int, List*> freqlistmap;
    int maxsize, currsize;
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
            
        List* nexthigherlist=new List();
        if(freqlistmap.find(node->freq +1) != freqlistmap.end())
            nexthigherlist=freqlistmap[node->freq+1];
            
        node->freq++;
        nexthigherlist->addfront(node);
        freqlistmap[node->freq] = nexthigherlist;
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
            if(maxsize == currsize){
                List* list=freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                list->removenode(list->tail->prev);
                currsize--;
            }
            
            currsize++;
            minfreq=1;
            
            List* list=new List();
            if(freqlistmap.find(minfreq) != freqlistmap.end())
                list=freqlistmap[minfreq];
            
            Node* node=new Node(key, value);
            list->addfront(node);
            freqlistmap[minfreq] = list;
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

//{ Driver Code Starts.

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        int capacity; cin >> capacity;
        LFUCache* obj = new LFUCache(capacity);

        int runs; cin >> runs;
        for(int i = 0;i<runs;i++){
            int s; cin >> s;
            if(s==1){
                int key; cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }else{
                int key,value;
                cin >> key >> value;
                obj->put(key,value);
            }
            
            
            
        }
        


    }
}

// } Driver Code Ends