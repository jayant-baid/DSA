//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if(s.size() & 1)
        return -1;
        
    while(s.length()!=0 && s.find("{}") < s.length())
        s.erase(s.find("{}"), 2);
        
    
    int a=0, b=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '{')
            a++;
        else
            b++;
    }
    return (a+1)/2 + (b+1)/2;
}