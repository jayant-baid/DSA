class Solution {
public:
    bool match(char open, char closed){
        if(open =='[' && closed==']' )
            return true;
        if(open =='(' && closed==')' )
            return true;
        if(open =='{' && closed=='}' )
            return true;
        
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch =='[' || ch=='(' || ch=='{')
                st.push(ch);
            else{
                if(!st.empty()){
                    if(match(st.top(), ch))
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        
        if(st.empty())
            return true;
        return false;
    }
};