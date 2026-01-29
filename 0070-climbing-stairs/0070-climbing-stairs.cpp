class Solution {
public:
    int climbStairs(int n) {
        // if(n == 0||n==1) return 1;
        // return climbStairs(n-1)+climbStairs(n-2);

        if(n == 0||n==1) return 1;

        int prev1 = 1;
        int prev2 =1;
        int cur = 0;
        for(int i = 2;i<=n;i++){
            cur  = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
            
        }

        return cur;
    }
};