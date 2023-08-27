class Solution {
	public:
		string FirstNonRepeating(string s){
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans="";
		    
		    for(int i=0;i<s.length();i++){
		        char ch=s[i];
		        count[ch]++;
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()]>1)
		                q.pop();
		            else{
		                ans+=q.front();
		                break;
		            }
		        }
		        if(q.empty())
		            ans+='#';
		    }
		    return ans;
		}
};
