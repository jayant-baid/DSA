//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isLeap(int n){
        //code here
        if(n % 400 == 0)
            return 1;
            
        if(n % 4 == 0 && n % 100 != 0)
            return 1;
            
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isLeap(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends