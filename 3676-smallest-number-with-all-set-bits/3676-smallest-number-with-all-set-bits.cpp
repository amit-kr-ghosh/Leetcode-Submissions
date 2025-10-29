class Solution {
public:
    long long smallestNumber(long long n) {
        long long x = 1;
        while (x < n) {
            x = (x << 1) | 1; // generate numbers like 1, 3, 7, 15, ...
        }
        return x;
    }
};
