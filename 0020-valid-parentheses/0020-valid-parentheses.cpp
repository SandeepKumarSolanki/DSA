class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s) {
            char temp = ch;
            if(temp == '(' || temp == '[' || temp == '{') {
                st.push(temp);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    char top = st.top();
                    if(
                        (top == '(' && temp == ')') ||
                        (top == '[' && temp == ']') ||
                        (top == '{' && temp == '}') 
                    ) {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        return st.empty();
    }
};