class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }
        int l = 0;
        int r = nums.size()-1;
        int nums2 [ nums.size()];

        for(int  i = 0;i<nums.size();i++){
            if(nums[i]== 0){
                nums2[r] = 0;
                r--;
            }
            else{
                nums2[l] = nums[i];
                l++;
            }
        }

        for(int i = 0;i<nums.size();i++){
            nums[i] = nums2[i];

        }

       
        return;
        
    }
};