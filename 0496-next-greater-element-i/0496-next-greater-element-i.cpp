class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int>ans;
        unordered_map<int,int> nge;
        stack<int>st;

        for(int i :nums2){

            while(!st.empty()&& i>st.top()){

                nge[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }


        while(!st.empty()){
            nge[st.top()] = -1;
            st.pop();
        }

        for( int i  : nums1){
            ans.push_back(nge[i]);
        }

        return ans;

    }
};