//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int cnt=0;
    void merge(long long arr[], long long s, long long mid, long long e){
        vector<long long> temp;
        long long left=s, right=mid+1;
        while(left <= mid && right <= e){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                cnt+=mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= e){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=s;i<=e;i++)
            arr[i]=temp[i-s];
    }
    
    void mergeSort(long long arr[],long long s, long long e){
        if(s>= e)
            return;
            
        long long mid=s+(e-s)/2;
        mergeSort(arr, s,mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
    long long int inversionCount(long long arr[], long long n)
    {
        mergeSort(arr, 0, n-1);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends