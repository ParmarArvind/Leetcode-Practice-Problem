class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string token = "";
        stack<string> st;
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if (token == "")
                    continue;
                else if (token == ".") {
                    token = "";
                } else if (token == "..") {
                    if (!st.empty())
                        st.pop();
                    token = "";
                } else {
                    st.push(token);
                    token = "";
                }

            } else
                token.push_back(path[i]);
        }
        if (token != "" && token != "." )
        {
            if(token==".." && !st.empty()) st.pop();
            if(token != "..")  st.push(token);
        }
            
        

        if(st.empty()) return "/";

        stack<string> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            temp.push("/");
            st.pop();
        }
        string result;
        while (!temp.empty())
        {
            result+=temp.top();
            temp.pop();
        }

        return result;

    }
};
