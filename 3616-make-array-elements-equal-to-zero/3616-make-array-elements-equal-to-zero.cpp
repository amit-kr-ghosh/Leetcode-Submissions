class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0);
        int out = 0;
        pref[0] = nums[0];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }

        for(int i = 0;i<n;i++){
            int leftsum = pref[i];
            int rightsum = pref[n-1]-pref[i];
            if(nums[i] == 0){
                if(leftsum==rightsum){
                    out+=2;
                }
                if(leftsum-rightsum==1){
                    out +=1;
                }
                if(rightsum-leftsum==1){
                    out+=1;
                }
            }

        }
        return out;
    }
};