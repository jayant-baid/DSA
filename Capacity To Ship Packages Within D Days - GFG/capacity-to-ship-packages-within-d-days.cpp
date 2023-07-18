//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int func(int wt[], int n, int cap){
        int days=1, load=0;
    
        for(int i=0;i<n;i++){
            if(load+wt[i] > cap){
                days++;
                load=wt[i];
            }
            else   
                load+=wt[i];
        }
        return days;
    }
    int leastWeightCapacity(int wt[], int n, int days) {
        // code here
        int maxi=INT_MIN, sum=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi, wt[i]);
            sum+=wt[i];
        }

        // for(int cap=maxi; cap<=sum;cap++){
        //     int reqDays=func(wt, cap);

        //     if(reqDays<= days)
        //         return cap;
        // }
        // return -1;

        int s=maxi, e=sum;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            int reqDays=func(wt,n, mid);
            if(reqDays<=days){
                ans=mid;
                e=mid-1;
            }
            else    
                s=mid+1;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends