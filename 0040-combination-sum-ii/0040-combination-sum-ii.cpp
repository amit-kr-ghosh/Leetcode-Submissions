class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> temp ; 
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());

        sum2(0,target,candidates,temp,ans);
        return ans;
    }

    void sum2(int id , int tar , vector<int> &nums , vector<int> & temp , vector<vector<int>> &ans){

        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        if(tar <0){
            return;
        }
        

        for(int i = id;i<nums.size();i++){

            if(i>id && nums[i] == nums[i-1]){
                continue;
            }
             //include
             temp.push_back(nums[i]);
            sum2(i+1,tar-nums[i],nums,temp,ans);
             temp.pop_back();

        }

       
      
    }
    
};