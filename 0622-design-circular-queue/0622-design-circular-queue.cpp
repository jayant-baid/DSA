class MyCircularQueue {
public:
    int * arr;
    int front;
    int rear;
    int size;
    int cnt;
    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        front=0;
        rear=0;
        cnt=0;
    }
    
    bool enQueue(int value) {
        if(cnt == size)
            return false;
        
        arr[rear]=value;
        rear=(rear+1)%size;
        cnt++;
        return true;
        
    }
    
    bool deQueue() {
        if(cnt==0)
            return false;
        
        // arr[front]=-1;
        front=(front+1)%size;
        cnt--;
        return true;
    }
    
    int Front() {
        if(cnt==0)
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(cnt==0)
            return -1;
        if(rear==0)
            return arr[size-1];
        return arr[rear-1];
    }
    
    bool isEmpty() {
        if(cnt == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(cnt==size)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */