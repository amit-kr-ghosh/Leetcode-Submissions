class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;  // base cases
        int first = 1, second = 2; // ways to reach step 1 and step 2
        for (int i = 3; i <= n; i++) {
            int current = first + second; 
            first = second;
            second = current;
        }
        return second; // total ways for n steps
    }
};