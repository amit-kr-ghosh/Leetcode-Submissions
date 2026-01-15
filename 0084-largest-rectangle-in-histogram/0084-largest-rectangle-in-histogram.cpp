class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int  n = heights.size();
        int maxarea = 0;
        int width;
        int height;


        vector<int> nse(n) , pse(n);
        stack <int> st;

        for(int i = 0;i<n;i++){

            while(!st.empty()&& heights[i]<=heights[st.top()]){
                st.pop();
            }
            pse[i] = st.empty()? -1:st.top();

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1;i>=0;i--){

            while(!st.empty()&& heights[i]<=heights[st.top()]){
                st.pop();
            }
            nse[i] = st.empty()? n:st.top();

            st.push(i);
        }


        for(int  i = 0;i<n;i++){
            height = heights[i];
            width = nse[i] - pse[i] -1;
            maxarea = max(maxarea,height*width);
        }

        return maxarea;
    }
};
