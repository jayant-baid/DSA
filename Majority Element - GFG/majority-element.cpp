//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // arr: input array
    // n: size of input array
    int majorityElement(int arr[], int n)
    {
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int ans=-1;
        
        for(int i=0;i<n;i++){
            if(mpp[arr[i]] > n/2){
                ans=arr[i];
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends