class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int  n = heights.size();
        int maxarea = 0;
        int width;
        int height;

        stack <int> st;

        for(int i = 0;i<=n;i++){

            int curH = (i==n)?0:heights[i];

            while(!st.empty()&& curH<heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int w = st.empty()?i:i - st.top() -1;

                maxarea = max(maxarea , h *w);
            }

            st.push(i);
        }

        return maxarea;
    }
};
