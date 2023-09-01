//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> prevsmaller(int arr[], int n){
        vector<int> prev(n);
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()] >= arr[i])
                st.pop();
                
            prev[i]=st.top();
            st.push(i);
        }
        return prev;
    }
    
    vector<int> nextsmaller(int arr[], int n){
        vector<int> next(n);
        stack<int> st;
        st.push(n);
    
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && arr[st.top()] >= arr[i])
                st.pop();
            
            next[i]=st.top();
            st.push(i);
        }
        return next;
    }
    
    vector <int> maxOfMin(int arr[], int n) 
    {
        vector<int> ans(n, INT_MIN);
        
        vector<int> prev=prevsmaller(arr, n);
        vector<int> next=nextsmaller(arr, n);
        
        for(int i=0;i<n;i++){
            int len=next[i]-prev[i]-1;
            ans[len-1]=max(ans[len-1], arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
            ans[i]=max(ans[i], ans[i+1]);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends