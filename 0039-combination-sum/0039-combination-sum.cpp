class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        combsum(0,target,temp,candidates,ans);

        return ans;
    }

        void combsum(int i , int tar , vector<int> & temp, vector<int> &arr , vector<vector<int>> & ans){

            if(tar == 0){
                ans.push_back(temp);
                return;
            }

            if(tar<0){
                return;
            }
            if(i == arr.size()){
                return;
            }


            //include
            temp.push_back(arr[i]);
            combsum(i,tar-arr[i],temp,arr,ans);

            //exclude
            temp.pop_back();
            combsum(i+1,tar,temp,arr,ans);
        }
    
};