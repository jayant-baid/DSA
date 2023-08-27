//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    int count[26]={0};
            string ans="";
            
            int nonrepeatingIndex=0;
            count[s[0]-'a']++;
            ans+=s[0];
            
            for(int i=1;i<s.length();i++){
                
                count[s[i]-'a']++;
                
                while(nonrepeatingIndex <= i && count[s[nonrepeatingIndex]-'a'] > 1)
                    nonrepeatingIndex++;
                    
                if(nonrepeatingIndex > i)
                    ans+='#';
                else
                    ans+=s[nonrepeatingIndex];
            }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends