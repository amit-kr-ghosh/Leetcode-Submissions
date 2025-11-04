#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i = 0; i < k; i++) freq[nums[i]]++;
        auto calc = [&]() {
            vector<pair<int,int>> v;
            for(auto &p : freq) v.push_back({p.second, p.first});
            sort(v.rbegin(), v.rend());
            long long s = 0;
            for(int i = 0; i < min(x, (int)v.size()); i++) s += 1LL * v[i].first * v[i].second;
            return (int)s;
        };
        ans.push_back(calc());
        for(int i = k; i < n; i++) {
            if(--freq[nums[i-k]] == 0) freq.erase(nums[i-k]);
            freq[nums[i]]++;
            ans.push_back(calc());
        }
        return ans;
    }
};
