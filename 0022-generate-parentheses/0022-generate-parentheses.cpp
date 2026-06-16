class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;

        paren(n,n,temp,ans);
        return ans;
   
    }

    void paren(int o , int c , string &temp , vector<string> & ans){

        if(o == 0 && c== 0){
            ans.push_back(temp);
            return;
        }

        if(o>0){
            temp.push_back('(');
            paren(o-1,c,temp,ans);
            temp.pop_back();
        }
        if(c>o){
            temp.push_back(')');
            paren(o,c-1,temp,ans);
             temp.pop_back();
        }
    }
};