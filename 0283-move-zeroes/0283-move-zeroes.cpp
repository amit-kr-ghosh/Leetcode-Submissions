class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }
        int l = 0;
        int r = 1;

        while(r<nums.size()){
            if(nums[l] == 0 && nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
                r++;

            }
            else if(nums[l] == 0 && nums[r] == 0){
                r++;
            }
            else{
                l++;
                r++;
            }
        }
        return;
        
    }
};