class Solution
{
    public:
    void delfunc(stack<int>&s, int size, int cnt){
        if(cnt == size/2){
            s.pop();
            return;
        }
            
        int tp=s.top();
        s.pop();
        delfunc(s, size, cnt+1);
        s.push(tp);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        delfunc(s, sizeOfStack, 0);
    }
};
