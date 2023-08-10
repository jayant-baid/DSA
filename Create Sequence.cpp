void solve(long long value, long long n, vector<long long>& ans){
    if(value!=0)
        ans.push_back(value);
    
    if(value*10+2 <= n)
        solve(value*10+2, n, ans);

    if(value*10+5 <= n)
        solve(value*10+5, n, ans);
}

vector<long long> createSequence(long long n){
    vector<long long> ans;
    solve(0, n, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
