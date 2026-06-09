class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        comb(1,k,temp,ans,n);

        return ans;

    }


    void comb(int idx , int k , vector<int> &temp, vector<vector<int>> &ans ,int n){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(idx == n+1){
            return;
        }

    
        //include
        temp.push_back(idx);
        //call next
        comb(idx+1,k-1,temp,ans,n);

        //exclude
        temp.pop_back();
        //call next
        comb(idx+1,k,temp,ans,n);
    }
    
    
};