class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        vector<long long> A(n), B(n);
        long long base = 0;

        for (int i = 0; i < n; i++) {
            base += 1LL * strategy[i] * prices[i];
            A[i] = -1LL * strategy[i] * prices[i];           // gain if set to 0
            B[i] = 1LL * prices[i] - 1LL * strategy[i] * prices[i]; // gain if set to 1
        }

        vector<long long> prefA(n + 1, 0), prefB(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefA[i + 1] = prefA[i] + A[i];
            prefB[i + 1] = prefB[i] + B[i];
        }

        long long best = 0;
        int half = k / 2;

        for (int l = 0; l + k <= n; l++) {
            long long gain =
                (prefA[l + half] - prefA[l]) +
                (prefB[l + k] - prefB[l + half]);
            best = max(best, gain);
        }

        return base + best;
    }
};
