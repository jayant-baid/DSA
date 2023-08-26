class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int size;
    int cnt;
    MyCircularDeque(int k) {
        size=k;
        arr=new int[size];
        front=0;
        rear=0;
        cnt=0;
    }
    
    bool insertFront(int value) {
        if(cnt==size)
            return false;
        
        front=front==0 ? front=size-1 : front-1;
        arr[front]=value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cnt==size)
            return false;
        arr[rear++]=value;

        rear=rear%size;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(cnt==0)
            return false;
        
        //arr[front%size]=-1;
        front=(front+1)%size;
        cnt--;
        
        return true;
    }
    
    bool deleteLast() {
        if(cnt==0)
            return false;
        
        //arr[rear%size]=-1;
        rear=rear==0? size-1 : rear-1;
        
        cnt--;
        
        return true;
    }
    
    int getFront() {
        if(cnt==0)
            return -1;
        
        return arr[front];
    }
    
    int getRear() {
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */