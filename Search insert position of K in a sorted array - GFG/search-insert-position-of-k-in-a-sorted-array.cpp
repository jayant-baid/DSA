//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // code here
        int ans=-1;
        int s=0, e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==k)
                return mid;
            else if(arr[mid] < k){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans+1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends