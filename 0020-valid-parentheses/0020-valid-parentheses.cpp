class Solution {
public:
    bool isValid(string s) {
        string st;
        return valid(0,s,st);
    }

    bool valid(int i , string &s ,string &st){

        if(i == s.size()){
            return st.empty();
        }
        char c = s[i];

        if(c == '('||c=='{'||c=='['){
            st.push_back(c);
            return valid(i+1,s,st);
        }

        if(st.empty()){
            return false;
        }
        else if(c == ')' && st.back()!='('
        || c == '}' && st.back()!='{' || c == ']' && st.back()!='['){
            return false;
        }

        st.pop_back();
        return valid(i+1,s,st);


    }
};