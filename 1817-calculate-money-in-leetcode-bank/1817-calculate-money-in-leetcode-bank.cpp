class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int count  =0;
        for(int  i =1;i<=n;i++){
            for(int j = i;j<i+7;j++){
                if(count == n){
                    return sum;
                }
                sum  = sum+j;
                count++;
            }
        }
        return 0;
    }
};
