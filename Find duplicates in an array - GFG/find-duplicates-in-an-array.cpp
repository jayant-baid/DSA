//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        int i=0;
        while(i<n){
            int correct=arr[i];
            if(arr[correct] != arr[i])
                swap(arr[correct],arr[i]);
            else 
                i++;
        }
        
        set<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i] != i)
                st.insert(arr[i]);
        }
        if(st.size()==0)
            return {-1};
        for(auto it:st)
            ans.push_back(it);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends