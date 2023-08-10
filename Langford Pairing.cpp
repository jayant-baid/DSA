#include <bits/stdc++.h> 
bool solve(int n, vector<int>& ans){
    if(n==0)
        return true;
    
    for(int i=0;i<ans.size()-n-1;i++){
        if(ans[i] == 0 && ans[i+n+1] == 0){
            ans[i]=n;
            ans[i+n+1]=n;
            if(solve(n-1, ans))
                return true;
            ans[i]=0;
            ans[i+n+1]=0;
        }
    }
    return false;
}

vector<int> findLangford(int n){
    if(n%4 == 1 || n%4 == 2)
        return {-1};

    vector<int> ans(2*n, 0);
    solve(n, ans);
    return ans;
} 
