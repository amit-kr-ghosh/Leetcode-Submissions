class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(),nums.end());

        perm2(0 , temp , nums ,ans);
        return ans;
        
    }

    void perm2(int id , vector<int> & temp, vector<int> &nums  , vector<vector<int>> &ans){
        if(id == nums.size()){
            ans.push_back(temp);
            return;
        }

        
        unordered_set<int> st;
        for(int  i = id ; i<nums.size();i++){
            if(st.count(nums[i])){
                continue;
            }

            st.insert(nums[i]);
            temp.push_back(nums[i]);
            swap(nums[i],nums[id]);
            perm2(id+1,temp,nums,ans);
            temp.pop_back();
            swap(nums[i],nums[id]);

           


        }
    }
};