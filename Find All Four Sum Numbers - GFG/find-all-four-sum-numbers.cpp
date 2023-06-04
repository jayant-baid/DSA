//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                long long sum=arr[i]+arr[j];
                long long target=k-sum;
                int front=j+1;
                int back=n-1;
                while(front< back){
                    if(arr[front] + arr[back] < target)
                        front++;
                    else if(arr[front] + arr[back] > target)
                        back--;
                    else{
                        int x=arr[front], y=arr[back];
                        vector<int> temp ={arr[i], arr[j], arr[front], arr[back]};
                        ans.push_back(temp);
                        while(front < back && arr[front] == x)
                            front++;
                        while(front < back && arr[back] == y)
                            back--;
                    }
                }
                while(j+1<n && arr[j] == arr[j+1])
                    j++;
            }
            while(i+1<n && arr[i] == arr[i+1])
                i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends