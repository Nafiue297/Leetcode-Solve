class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int>v(n);
        stack<int>st;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')')
            {
                int top=st.top();
                st.pop();
                v[top]=i;
                v[i]=top;
            }
        }
        int flag=1;
        string res;
        for(int i=0; i<n; i+=flag)
        {
            if(s[i]=='(')
            {
                i=v[i];
                flag=-flag;
                
            }else if(s[i]==')')
            {
                i=v[i];
                flag=-flag;
               
            }
         else   res.push_back(s[i]);
        }
    return res;
    }
};