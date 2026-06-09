class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        sub(0,nums,temp,ans);
        return ans;
    }
        void sub(int i , vector<int> &arr,vector<int> &temp , vector<vector<int>> & ans){
        
                ans.push_back(temp);
            
            for(int j = i;j<arr.size();j++){
                //include
                temp.push_back(arr[j]);
                //call next
                sub(j+1,arr,temp,ans);

                //exclude
                temp.pop_back();
            }
        }
        
    
};