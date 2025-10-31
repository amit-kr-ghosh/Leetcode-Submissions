class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp (s.size(),-1);
        return solve(s,0,dp);    
    }

    int solve(string &s , int i , vector<int> &dp){
        if(i== s.size()){
            return 1;
        }
        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] !=-1){
            return dp[i];
        }

        int res = solve(s,i+1,dp);

        if(i+1<s.size()){
            int num = (s[i]-'0')*10 + s[i+1]-'0';
            if(num>=10 && num<=26){
                res+= solve(s,i+2,dp);
            }
        }

        return dp[i] = res;
    }
};