//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> s;
public:

    void enqueue(int x) {
        s.push(x);
    }

    int dequeue() {
        if(s.empty())
            return -1;
            
        if(s.size() == 1){
            int ans=s.top();
            s.pop();
            return ans;
        }
        
        int tp=s.top();
        s.pop();
        int ans=dequeue();
        s.push(tp);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends