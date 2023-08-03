class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char ch : s){
            if(!st.empty()){
                if(st.top().first == ch)
                    st.top().second++;
                else 
                    st.push({ch, 1});

                if(st.top().second == k)
                    st.pop();
            }   
            else
                st.push({ch, 1});
        }
        // if(st.empty())
        //     return "";

        string ans="";
        while(!st.empty()){
            auto tp=st.top();
            st.pop();
            for(int i=0;i<tp.second;i++)
                ans.push_back(tp.first);

        };
        reverse(ans.begin(), ans.end());
        return ans;
    }
};