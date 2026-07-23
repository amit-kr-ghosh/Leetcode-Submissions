class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(0,nums,ans);
        return ans;

    }
    
    void perm(int id , vector<int>& nums , vector<vector<int>>& ans){
        if(id == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = id;i<nums.size();i++){
            swap(nums[i],nums[id]);
            perm(id+1,nums,ans);
            swap(nums[i],nums[id]);
        }
    }

};