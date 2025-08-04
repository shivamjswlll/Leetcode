class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        stack<string> st;
        int i = 0;
        while(i<s.size()){
            if(s[i] == ' '){
                while(s[i] == ' ') i++;
                if(temp != "")
                st.push(temp);
                temp = "";
            }
            else{
                temp += s[i];
                i++;
            }
        }
        if(temp != "")
        st.push(temp);
        string ans = "";
        while(st.size() > 1){
            ans += st.top();
            st.pop();
            ans+= " ";
        }
        ans += st.top();
        return ans;
    }
};