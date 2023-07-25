//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numberOfGasStations(vector<int> &arr, double dist){
        int cnt=0;
    
        for(int i=0;i<arr.size()-1;i++){
            int numberInBetween = (arr[i+1]-arr[i])/dist;
    
            if(arr[i+1]-arr[i] == numberInBetween*dist)
                numberInBetween--;
    
            cnt+=numberInBetween;
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &arr, int k){
        int n=arr.size();
    
        double low=0, high=0;
        for(int i=0;i<n-1;i++)
            high=max(high,(double)(arr[i+1] - arr[i]));
    
        double diff=1e-6;
        // double ans=-1;
    
        while(high - low > diff){
            double mid=(low+high)/(2.0);
    
            int cnt=numberOfGasStations(arr,mid);
            if(cnt > k)
                low=mid;
            else{
                // ans=mid;
                high=mid;
            }
        }
        return high + 0.000001;
        
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends