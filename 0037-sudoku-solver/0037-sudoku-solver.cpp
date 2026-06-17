class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sud(board);
    }

    bool sud(vector<vector<char>>&board){
        for(int r = 0;r<9;r++){
            for(int c = 0;c<9;c++){
                if(board[r][c] == '.'){
                    for(char x = '1';x<='9';x++){
                        if(isSafe(r,c,x,board)){
                            board[r][c] = x;
                            if(sud(board)){
                                return true;
                            }
                            board[r][c] = '.';
                        }
                    }
                return false;

                }
              
            }
        }
        return true;
    }

    bool isSafe(int r , int c , char x , vector<vector<char>> &board){
        for(int i = 0;i<9;i++){
            //check row
            if(board[r][i]== x){
                return false;
            }

            //check column
            if(board[i][c] == x){
                return false;
            }

            //check 3x3 grid
            if(board[(r/3)*3+i/3][(c/3)*3+i%3]== x){
                return false;
            }
        }
        return true;
    }

};