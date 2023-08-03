//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        int start=0, end=0;
        for(int i=0; s[i]!='\0'; i++){
            if(s[i] == '.'){
                end=i;
                reverse(s.begin() + start, s.begin() + end);
                start=i+1;
            }
        }
        reverse(s.begin() + start, s.end());
        
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends