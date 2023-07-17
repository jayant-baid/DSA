//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int n) 
    {
        long long int s=1, e=n;
        long long int ans=-1;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(mid==n/mid)
                return mid;
    
            else if(mid < n/mid){
                ans=mid;
                s=mid+1;
            }
            else 
                e=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends