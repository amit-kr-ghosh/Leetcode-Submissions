class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxarea = 0;
        int area = 0;
        while(left<right){
            area = min(height[right],height[left])*(right-left) ;
            maxarea = max(maxarea,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxarea;
    } 
};
