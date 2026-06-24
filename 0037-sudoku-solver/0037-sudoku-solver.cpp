class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 
        solve(board);
       
    }

    bool solve(vector<vector<char>>& board){
        for(int  i = 0;i<9;i++){
            for(int  j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char c = '1';c<='9';c++){
                        if(canplace(c,i,j,board)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;

                }

            }
        }
        return true;
    }

    bool canplace(char ch , int r , int c , vector<vector<char>> & board){
        for(int  i = 0;i<9;i++ ){
            //check row
            if(board[r][i]== ch){
                return false;
            }

            //check column
            if(board[i][c] == ch){
                return false;
            }

            // check 3x3 grid
            if(board[(r/3)*3 + i/3 ][(c/3)*3 + i%3 ]==ch){
                return false;
            }
        }
        return true;

    }


};