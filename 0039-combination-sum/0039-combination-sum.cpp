class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        comb(0,target,temp,ans,candidates);

        return ans; 
        
    }

   void comb(int id, int tar, vector<int> & temp , vector<vector<int>> & ans , vector<int> &nums){

        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        if(tar<0){
            return ;
        }


        for(int i = id;i<nums.size();i++){
            //include
            temp.push_back(nums[i]);
            //call
            comb(i,tar-nums[i],temp,ans,nums);

            //excude
            temp.pop_back();
           
        }


    }
};