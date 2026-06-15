class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());

        sub2(0,nums,temp,ans);
        return ans;
    }

    void sub2(int id , vector<int> &nums, vector<int> &temp , vector<vector<int>> &ans){

        ans.push_back(temp);

            for(int i = id ; i<nums.size();i++){
                if(i>id && nums[i] == nums[i-1]){
                    continue;
                }
            temp.push_back(nums[i]);
            sub2(i+1,nums,temp,ans);
            temp.pop_back();

            }


    }
};