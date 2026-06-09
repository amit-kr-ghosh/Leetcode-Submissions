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

            for(int i = idx ;i<n+1;i++){
                //include
                temp.push_back(i);

                //call next
                comb(i+1,k-1,temp,ans,n);

                //exclude
                temp.pop_back();
            }
        }
        
    
};