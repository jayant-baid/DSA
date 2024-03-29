//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        sort(arr1, arr1+n);
        sort(arr2, arr2+m);
        
        int i=0, j=0;
        int ans=-1;

        while(i<n && j<m){
           
            if(arr1[i] < arr2[j]){
                ans=arr1[i];
                i++;
                k--;
            }
            else{
                ans=arr2[j];
                j++;
                k--;
            }
            
             if(k==0)
                return ans;
        }
        while(i<n){
           
    
            ans=arr1[i];
            i++;
            k--;
       
          
            if(k==0)
                return ans;
        }
        
        while(j<m){
                ans=arr2[j];
                j++;
                k--;
            
             if(k==0)
                return ans;
        }
    
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends