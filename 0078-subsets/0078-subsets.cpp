class Solution {
public:

void subseq(int index , vector<int>&nums , int n , vector<int> &curr, vector<vector<int>> & ans){

    if(index == n){
        ans.push_back(curr);
        return;
    }

    //include
    curr.push_back(nums[index]);
    subseq(index+1,nums,n,curr,ans);

    //exclude
    curr.pop_back();
    subseq(index+1,nums,n,curr,ans);

}

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        vector<vector<int>> ans;

        subseq(0,nums,n,curr,ans);

        return ans;
        
    }
};