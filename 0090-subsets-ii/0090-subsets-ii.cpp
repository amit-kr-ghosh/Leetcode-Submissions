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
        if(id == nums.size()){
            ans.push_back(temp);
            return;
        }

        //include

        temp.push_back(nums[id]);
        sub2(id+1,nums,temp,ans);


        //skip duplicate
        int i = id+1;
        temp.pop_back();
        while(i<nums.size() &&nums[id] == nums[i]){
            i++;
        }
        sub2(i ,nums,temp , ans);

    }
};