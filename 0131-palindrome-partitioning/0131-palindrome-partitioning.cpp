class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        part(0,s,temp,ans);
        return ans;
    }

    void part(int id , string &s , vector<string>&temp ,vector<vector<string>> &ans){
        if(id == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = id;i<s.size();i++){
            if(isPalin(id,i,s)){
                temp.push_back(s.substr(id,i-id+1));
                part(i+1,s,temp,ans);
                 temp.pop_back();
            }
           
        }
    }

    bool isPalin(int l , int r , string &s){

        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
                l++;
                r--;
        }
        return true;




    }

};