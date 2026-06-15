class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
    
        unordered_map<int,int> freq;
        for(int i = 0;i<nums.size();i++){

                freq[nums[i]]++;

        }


        perm2(temp , freq ,  nums ,ans);
        return ans;
        
    }

    void perm2(vector<int> & temp, unordered_map<int,int> & freq, vector<int> &nums , vector<vector<int>>& ans){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto &i : freq){

            if(i.second == 0){
                continue;
            }

            temp.push_back(i.first);
            i.second--;

            perm2(temp,freq,nums,ans);
                        
            temp.pop_back();
            i.second++;

        }
    }
};