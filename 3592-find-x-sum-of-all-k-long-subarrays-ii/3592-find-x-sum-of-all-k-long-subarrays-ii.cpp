#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long freq, val;
        bool operator<(const Node &other) const {
            if (freq != other.freq) return freq < other.freq; // lower freq first
            return val < other.val; // if freq same, smaller val first (so largest is last)
        }
    };

    long long calc(Node n) { return n.freq * n.val; }

    void removeNode(multiset<Node> &st, Node x) {
        auto it = st.find(x);
        if (it != st.end()) st.erase(it);
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        unordered_map<long long, long long> freq;

        multiset<Node> top, rest;
        long long sumTop = 0;

        auto add = [&](long long val) {
            long long oldF = freq[val];
            long long newF = ++freq[val];
            if (oldF > 0) {
                Node oldNode = {oldF, val};
                if (top.find(oldNode) != top.end()) {
                    sumTop -= calc(oldNode);
                    removeNode(top, oldNode);
                } else {
                    removeNode(rest, oldNode);
                }
            }
            Node newNode = {newF, val};

            if ((int)top.size() < x) {
                top.insert(newNode);
                sumTop += calc(newNode);
            } else {
                if (!top.empty() && *top.begin() < newNode) {
                    auto it = top.begin();
                    sumTop -= calc(*it);
                    rest.insert(*it);
                    top.erase(it);
                    top.insert(newNode);
                    sumTop += calc(newNode);
                } else {
                    rest.insert(newNode);
                }
            }
        };

        auto removeVal = [&](long long val) {
            long long oldF = freq[val];
            long long newF = --freq[val];
            Node oldNode = {oldF, val};
            if (top.find(oldNode) != top.end()) {
                sumTop -= calc(oldNode);
                removeNode(top, oldNode);
            } else {
                removeNode(rest, oldNode);
            }
            if (newF > 0) {
                Node newNode = {newF, val};
                rest.insert(newNode);
            }

            if ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                top.insert(*it);
                sumTop += calc(*it);
                rest.erase(it);
            }
        };

        for (int i = 0; i < k; i++) add(nums[i]);
        ans[0] = sumTop;

        for (int i = k; i < n; i++) {
            add(nums[i]);
            removeVal(nums[i - k]);
            ans[i - k + 1] = sumTop;
        }
        return ans;
    }
};
