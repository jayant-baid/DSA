//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    void merge(vector<int>& arr, int s, int mid, int e){
        vector<int> temp;
        int left=s, right=mid+1;
        while(left<=mid && right<=e){
            if(arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while(left<=mid)
            temp.push_back(arr[left++]);
        while(right<=e)
            temp.push_back(arr[right++]);
            
        for(int i=s;i<=e;i++)
            arr[i]=temp[i-s];
    }
    int countPairs(vector<int>&arr, int s, int mid, int e){
        int cnt=0;
        int right=mid+1;
        for(int i=s;i<=mid;i++){
            while(right<=e && arr[i] > 2*arr[right])
                right++;
            cnt+=right-(mid+1);
        }
        return cnt;
    }
    int mergeSort(vector<int>&arr, int s, int e){
        int cnt=0;
        if(s>=e)
            return cnt;
        int mid=s+(e-s)/2;
        cnt+=mergeSort(arr, s, mid);
        cnt+=mergeSort(arr, mid+1, e);
        cnt+=countPairs(arr, s, mid, e);
        merge(arr, s, mid, e);
        return cnt;
    }
  public:
    int countRevPairs(int n, vector<int> arr) {
        return mergeSort(arr, 0 ,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends