//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(int arr[], int n, int mid){
        int cnt=1, sum=0;
            
        for(int i=0;i<n;i++){
            if(sum + arr[i] <= mid)
                sum+=arr[i];
            else{
                cnt++;
                sum=arr[i];
            }
        }
        return cnt;
    }
    int splitArray(int arr[] ,int n, int k) {
   
        int s=*max_element(arr, arr+n);
        int e=accumulate(arr, arr+n, 0);
        
        while(s<=e){
            int mid=s+(e-s)/2;
            int painter=func(arr, n, mid);
            if(painter > k){
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return s;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends