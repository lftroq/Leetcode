class Solution {
public:
    #define ll long long
    vector<int> finalPrices(vector<int>& a) {
        using namespace std;
        stack<ll> st;
        vector<int> ans(a.size(),0);
        for(int i=a.size()-1;i>=0;i--)
        {
            while(st.size()&&a[st.top()]>a[i]) st.pop();
            if(st.size()) ans[i]=a[i]-a[st.top()]; else ans[i]=a[i];
            st.push(i);
        }
        return ans;
    }
};