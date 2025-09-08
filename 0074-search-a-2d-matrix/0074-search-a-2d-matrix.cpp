class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0,r = m-1,index = 0;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(matrix[mid][0]<=target){
                index = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
     l = 0,r = n-1;
     bool found = false;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[index][mid]==target){
                found = true;
            }
            if(matrix[index][mid]<=target){
                l = mid+1;
            }

            else{
                r = mid-1;
            }
        }
        return found;
    }
};