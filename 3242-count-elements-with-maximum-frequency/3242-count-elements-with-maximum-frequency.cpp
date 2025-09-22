class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        int maxcount = 0,count = 0;
        for(auto i: nums){
            freq[i]++;
            maxcount = max(freq[i],maxcount);
        }

        for(auto i:nums){
            if(freq[i]==maxcount){
                count++;
            }
        }
        return count;
    }
};