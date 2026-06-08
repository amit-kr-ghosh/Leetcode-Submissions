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
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target <0){
            return;
        }
        if(i == arr.size()){
            return;
        }

        //include current
        temp.push_back(arr[i]);
        combsum2(i+1,arr,temp,ans,target-arr[i]);
        

        //exclude cuurent and skip duplicate
        temp.pop_back();

        int j = i;
        while(j+1<arr.size() && arr[j] == arr[j+1]){
            j++;
        }
        combsum2(j+1,arr,temp,ans,target);

        
    }

};