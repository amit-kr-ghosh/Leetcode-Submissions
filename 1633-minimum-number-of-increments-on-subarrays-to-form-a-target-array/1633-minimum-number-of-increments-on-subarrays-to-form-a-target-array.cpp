class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0;
        int ans = 0;

        for(int x:target){
            if(x>prev){
                ans += x - prev;
            }
            prev = x;
        }

        return ans;
    }
};