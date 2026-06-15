class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
      

        sort(nums.begin(),nums.end());

        perm2(0 , nums ,ans);
        return ans;
        
    }

    void perm2(int id , vector<int> &nums  , vector<vector<int>> &ans){
        if(id == nums.size()){
            ans.push_back(nums);
            return;
        }

        
        unordered_set<int> st;
        for(int  i = id ; i<nums.size();i++){
            if(st.count(nums[i])){
                continue;
            }

            st.insert(nums[i]);
            swap(nums[i],nums[id]);
            perm2(id+1,nums,ans);
            swap(nums[i],nums[id]);

           


        }
    }
};