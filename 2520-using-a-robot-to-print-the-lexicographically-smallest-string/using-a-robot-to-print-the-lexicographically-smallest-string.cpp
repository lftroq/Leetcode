class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int> cnt;
        for(char c:s) cnt[c]++;
        stack<char> st;
        string ans;
        char mi='a';
        for(char c:s)
        {
            st.push(c);
            cnt[c]--;
            while(mi!='z'&&cnt[mi]==0) mi++;
            while(st.size()&&st.top()<=mi)
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};