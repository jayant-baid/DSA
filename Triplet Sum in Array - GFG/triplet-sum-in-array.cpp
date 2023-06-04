//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int k)
    {
        sort(arr, arr+n);

        for(int i=0;i<n;i++){
            int target=k-arr[i];
            int front=i+1;
            int back=n-1;

            while(front < back){
                int sum=arr[front]+arr[back];
                if(sum < target)
                    front++;
                else if(sum>target)
                    back--;
                else{
                    return true;
                } 
            }
            while(i+1<n && arr[i] == arr[i+1])
                i++;
        }
        return false;

    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends