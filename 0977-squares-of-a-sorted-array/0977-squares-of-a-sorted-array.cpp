class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        

        int l = 0,r = nums.size()-1;
        vector<int> arr(nums.size());
        int n = nums.size()-1;

        while(l<=r){
            if(abs(nums[l])<abs(nums[r])){
                arr[n] = nums[r]*nums[r];
                r-- ;
                n--;
                
            }
            else{
                arr[n] = nums[l]*nums[l];
                l++;
                n--;
            }

        }

         return arr;

    }
};