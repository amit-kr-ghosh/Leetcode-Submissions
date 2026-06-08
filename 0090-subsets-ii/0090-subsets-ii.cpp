class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subsets(0 , nums ,temp,ans);
        return ans;
        
    }
     void subsets(int i ,vector<int> & arr,vector<int> & temp , vector<vector<int>> &ans){
        if(i== arr.size()){
            ans.push_back(temp);
            return;
        }

        //include
        temp.push_back(arr[i]);
        subsets(i+1,arr,temp,ans);

        //exclude current and skip duplicate
        temp.pop_back();
        int j = i;
        while(j<arr.size()-1 && arr[j] == arr[j+1]){
            j++;
        }
        subsets(j+1,arr,temp,ans);
    }
    

};