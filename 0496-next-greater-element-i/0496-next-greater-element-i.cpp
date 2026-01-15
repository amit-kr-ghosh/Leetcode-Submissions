class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> nge(n,-1);
        vector<int>ans;
        for(int i = n-1;i>=0;i--){

            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }

            if(!st.empty()){
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i : nums1){
            for(int j = 0;j<nums2.size();j++){
                if(i==nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }

        return ans;
    }
};