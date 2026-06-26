class Solution {
public:
    string getPermutation(int n, int k) {

        string arr;
        for(char i = 1;i<=n;i++){
           arr.push_back('0'+i);
        }
        string s;

        vector<int> vis(n,0);

        perm(n,k,arr,s,vis);
        return s;
        
    }

    void perm(int n , int   &k  , string & arr , string &s,vector<int> & vis){
        if(s.size() == n ){
            k--;
            return;
        }
        for(int i = 0 ;i<n ;i++ ){
            if(!vis[i]){
                vis[i] = 1;
                s.push_back(arr[i]);
                perm(n,k,arr,s,vis);
                if(k == 0){
                    return;
                }
                s.pop_back();
                vis[i] = 0;
            }
        }
    }
};