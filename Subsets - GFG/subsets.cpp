//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void func(vector<int>&arr, int i, vector<vector<int>>& ans, vector<int> output){
        if(i==arr.size()){
            ans.push_back(output);
            return;
        }
        
        func(arr, i+1, ans, output);
        
        output.push_back(arr[i]);
        func(arr, i+1, ans, output);
        
        
    }
    
    vector<vector<int> > subsets(vector<int>& arr)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> output;
        
        func(arr, 0, ans, output);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends