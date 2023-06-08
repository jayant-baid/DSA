//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int bs(int arr[], int n, int x, bool b){
    int s=0, e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        
        if(arr[mid] == x){
            if(b){
                ans=mid;
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        else if(arr[mid] < x)
            s=mid+1;
        else 
            e=mid-1;
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans(2);
    ans[0]=bs(arr, n, x, 1);
    ans[1]=bs(arr, n, x, 0);
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends