class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow=0, erow=matrix.size()-1;
        int scol=0, ecol=matrix[0].size()-1;
        
        vector<int> ans;
        
        while(srow <= erow && scol <= ecol){
            for(int col=scol; col<=ecol; col++)
                ans.push_back(matrix[srow][col]);
            
            srow++;
            
            for(int row=srow; row<=erow; row++)
                ans.push_back(matrix[row][ecol]);
            
            ecol--;
            
            if(srow <= erow){
                for(int col=ecol; col>=scol; col--)
                    ans.push_back(matrix[erow][col]);

                erow--;
            }
                
            if(scol <= ecol){
                for(int row=erow; row>=srow; row--)
                ans.push_back(matrix[row][scol]);
            
                scol++;
            }
             
        }
        return ans;
    }
};