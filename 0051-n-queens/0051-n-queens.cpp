class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> temp(n,string(n,'.'));
        N(0,n,temp,ans);
        return ans;
        
    }


    void N(int r ,int n, vector<string> & temp , vector<vector<string>> &ans){
        if(r == n){
            ans.push_back(temp);
            return;
        }

            for(int c = 0;c<n;c++){
                if(isValid(r,c,temp)){
                    temp[r][c] = 'Q';
                    N(r+1,n,temp,ans);
                    temp[r][c] = '.';
                }

            }
    }

    bool isValid(int r , int c , vector<string>&temp){
        //check columns
        for(int i = 0 ;i<=r;i++){
            if(temp[i][c] == 'Q'){
                return false;
            }
        }
        for(int i = c,j= r;i>=0 && j>=0;i--,j--){
            if(temp[j][i] == 'Q'){
                return false;
            }
        }
        for(int i = c,j= r;i<temp.size() && j>=0;i++,j--){
            if(temp[j][i] == 'Q'){
                return false;
            }
        }
        return true;

    }
};