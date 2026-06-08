class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        combsum2(0,candidates,temp,ans,target);

        return ans;
    }

    void combsum2(int i , vector<int> & arr , vector<int> & temp,vector<vector<int>> &ans,int target){

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int j = i;j<arr.size();j++){
            if(j>i && arr[j] == arr[j-1]){
                continue;
            }

            if(target<0){
                break;
            }

            //include
            temp.push_back(arr[j]);
            combsum2(j  +1,arr,temp,ans,target-arr[j]);

            //pop
            temp.pop_back();
        }        
    }
};