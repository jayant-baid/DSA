//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int func(int arr[], int n, int pages){
        int studCount=1, pageCount=0;
        
        for(int i=0;i<n;i++){
            if(pageCount + arr[i] <=pages)
                pageCount+=arr[i];
                
            else{
                studCount++;
                pageCount=arr[i];
            }
        }
        return studCount;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n)
            return -1;
            
        int s=*max_element(arr, arr+n);
        int e=accumulate(arr, arr+n, 0);
        
        while(s<=e){
            int mid=s+(e-s)/2;
            int studCount=func(arr, n, mid);
            if(studCount > m)
                s=mid+1;
            else
                e=mid-1;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends