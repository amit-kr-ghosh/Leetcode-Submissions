class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string text1 = s;
           reverse(s.begin(),s.end());
        string text2 = s;
     
            vector<vector<int>> dp (text1.size(),vector<int> (text2.size(),-1) );
        return lcs(text1,text2,0,0,dp);
        

    }

     int lcs(string &text1,string &text2 , int id1 , int id2 , vector<vector<int>>&dp){

            if(id1==text1.size()||id2 == text2.size()){
                return 0;
            }
            if(dp[id1][id2]!=-1){
                return dp[id1][id2];
            }
    

            if(text1[id1] == text2[id2]){
               return dp[id1][id2] = 1+ lcs(text1,text2,id1+1,id2+1,dp);
            }

                return dp[id1][id2] = max(lcs(text1,text2,id1+1,id2,dp),lcs(text1,text2,id1,id2+1,dp));
            
          }

};