class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(int i = 0; i < op.size(); i++)
        {
            if(op[i] == "C")
            {
                st.pop();
            }
            else if(op[i] == "D")
            {
                int x = st.top();
                st.push(2 * x);
            }
            else if(op[i] == "+")
            {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();    
                int sum = x1 + x2;
                st.push(x1);
                st.push(sum);
            }
            else
            {
                st.push(stoi(op[i]));
            }
        }
        int result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};