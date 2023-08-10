class Solution {
public:
    bool solve(int index, int i, int j, vector<vector<char>>& board, string word){
        if(index == word.size())
            return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j] != word[index])
            return false;
        
        char ch=board[i][j];
        board[i][j]='#';
        
        int delr[]={1, 0, -1, 0};
        int delc[]={0, 1, 0, -1};
        
        for(int d=0;d<4;d++){
            if(solve(index+1, i+delr[d], j+delc[d], board, word))
                return true;
        }
        board[i][j]=ch;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(solve(0, i, j, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};