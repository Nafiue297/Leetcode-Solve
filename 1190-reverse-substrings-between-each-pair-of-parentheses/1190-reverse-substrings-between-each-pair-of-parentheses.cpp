class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        stack<int>st;
        for(auto u:s)
        {
            if(u=='(') st.push(res.size());
            else if(u==')') 
            {
                int top=st.top();
                st.pop();
                reverse(begin(res)+top,end(res));
            }else res.push_back(u);
        }
        return res;
    }
};