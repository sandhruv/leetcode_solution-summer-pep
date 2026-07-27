class Solution {
public:
    void reverseString(vector<char>& s) {

        stack <int> st;
        
        for(char ch : s){
            st.push(ch);
        }

        for(int i=0;i<s.size();i++){

            s[i]=st.top();
            st.pop();
        }
    }
};