class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(),0);

        sort(nums.begin(),nums.end());

        perm2(temp , vis ,  nums ,ans);
        return ans;
        
    }

    void perm2(vector<int> & temp, vector<int> & vis, vector<int> &nums , vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int  i = 0 ; i<nums.size();i++){

            if(vis[i] == 1 ){
                continue;
            }

            if(i>0 && nums[i] == nums[i-1]&& !vis[i-1]){
                continue;
            }

            temp.push_back(nums[i]);
            vis[i] = 1;

            perm2(temp,vis,nums,ans);
                        
            temp.pop_back();
            vis[i] = 0;

        }
    }
};