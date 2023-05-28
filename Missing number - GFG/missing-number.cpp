//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int nums[], int n)
{
    // Your code goes here
    // int n=nums.size();
        // int sum=n*(n+1)/2;
        
        int ans=0;
        
        for(int i=0;i<n-1;i++){
            // sum-=nums[i];
            ans=ans^(i+1);
            ans=ans^nums[i];
        }
        return ans^n;
}