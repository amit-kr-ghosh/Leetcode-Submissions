class Solution {
public:
    int countTriples(int n) {
        int c = 0;
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                int s = a*a + b*b;
                int cval = sqrt(s);
                if(cval*cval == s && cval <= n) c++;
            }
        }
        return c;
    }
};
