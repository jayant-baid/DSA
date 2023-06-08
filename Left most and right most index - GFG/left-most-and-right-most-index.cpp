//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    long bs(vector<long long> &arr, int n, long long x, bool b){
        int s=0, e=n-1;
        long  ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(arr[mid] == x){
                if(b){
                    ans=mid;
                    e=mid-1;
                }
                else{
                    ans=mid;
                    s=mid+1;
                }
            }
            else if(arr[mid] < x)
                s=mid+1;
            else 
                e=mid-1;
        }
        return ans;
    }
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int n=v.size();
        pair<long,long> p;
        p.first=bs(v, n, x, 1);
        p.second=bs(v, n, x, 0);
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends