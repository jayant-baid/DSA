//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool isValid(char ch){
        if(ch >= 'a' && ch<= 'z')
            return true;
        return false;
    }
	bool sentencePalindrome(string s) 
	{
	    // code here
	    int i=0, j=s.length()-1;
	    while(i<j){
	        while(!isValid(s[i]))
	            i++;
	        while(!isValid(s[j]))
	            j--;
	            
	        if(s[i] != s[j])
	            return 0;
	            
	       i++, j--;
	    }
	    return 1;
	    
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends