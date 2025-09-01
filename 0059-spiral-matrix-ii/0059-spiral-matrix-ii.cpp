class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int j = left; j <= right; j++) {
                res[top][j] = num++;
            }
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                res[i][right] = num++;
            }
            right--;

            // Traverse from right to left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    res[bottom][j] = num++;
                }
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = num++;
                }
                left++;
            }
        }
        return res;
    }
};
