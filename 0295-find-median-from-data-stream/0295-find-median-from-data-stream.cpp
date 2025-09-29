#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> leftHeap;  // max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> rightHeap; // min-heap for the larger half
public:
    MedianFinder() {}

    void addNum(int num) {
        if (leftHeap.empty() || num <= leftHeap.top()) {
            leftHeap.push(num);
        } else {
            rightHeap.push(num);
        }

        if (leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        } else if (rightHeap.size() > leftHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }

    double findMedian() {
        if (leftHeap.size() == rightHeap.size()) {
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        } else {
            return leftHeap.top();
        }
    }
};
