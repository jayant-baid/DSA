int func(vector<int> &arr, int n, int board){
        int painter=1, wall=0;
        
        for(int i=0;i<n;i++){
            if(wall + arr[i] <= board)
                wall+=arr[i];
            else{
                painter++;
                wall=arr[i];
            }
        }
        return painter;
    }
int findLargestMinDistance(vector<int> &arr, int k)
{
    int n=arr.size();
    int s=*max_element(arr.begin(), arr.end());
    int e=accumulate(arr.begin(), arr.end(), 0);
    while(s<=e){
        int mid=s+(e-s)/2;
        int painter=func(arr, n, mid);
        if(painter > k){
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return s;
    
}
