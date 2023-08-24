//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> prev(n);
        vector<long long> next(n);
        
        stack<long long> st;
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(!st.empty() && arr[st.top()] >= curr)
                st.pop();
            if(st.empty())
                prev[i]=0;
            else
                prev[i]=st.top()+1;
                
            st.push(i);
        }
        while(!st.empty())  st.pop();
        
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            
            while(!st.empty() && arr[st.top()] >= curr)
                st.pop();
                
            if(st.empty())
                next[i]=n-1;
            else
                next[i]=st.top()-1;
                
            st.push(i);
        }
        
        long long area=INT_MIN;
        for(int i=0;i<n;i++){
            long long l=arr[i];
            
            long long b=next[i] - prev[i] + 1;
            area=max(area, l*b);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends