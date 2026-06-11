class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(),candidates.end());
        comb2(0,target,temp,ans,candidates);

        return ans;
    }

    void comb2(int id ,int tar , vector<int> & temp  , vector<vector<int>> &ans , vector<int> &nums){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        if(tar<0){
            return;
        }
        if(id == nums.size()){
            return;
        }

        //include
        temp.push_back(nums[id]);
        comb2(id+1,tar-nums[id],temp,ans,nums);

        //skip same
        int i = id;
        while(i+1<nums.size()  && nums[i] == nums[i+1]){
            i++;
        }
        temp.pop_back();
        comb2(i+1,tar,temp,ans,nums);


    }
};