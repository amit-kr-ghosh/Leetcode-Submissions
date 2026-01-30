class Solution {
public:
void subseq(int index, vector<int> & nums , vector<int> &curr , vector<vector<int>> &res , int n){
            if(index == n){
                res.push_back(curr);
            
            return;
          }

          //include
          curr.push_back(nums[index]);
          subseq(index+1,nums,curr,res,n);

          //exclude
          curr.pop_back();
          subseq(index+1,nums,curr,res,n);
          }

    vector<vector<int>> subsets(vector<int>& nums) {
          int n = nums.size();
          vector<vector<int>> res;
          vector<int> curr;

          
subseq(0,nums,curr,res,n);
          return res;
        
    }
};