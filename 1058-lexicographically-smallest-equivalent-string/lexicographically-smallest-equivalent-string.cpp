class Solution {
public:
    vector<int> par,sz,ma;
    int find_set(int u){return (u==par[u]?u:par[u]=find_set(par[u]));}
    void union_set(int u,int v) {
        u=find_set(u);v=find_set(v);if(u==v) return;
        if(sz[u]<sz[v]) swap(u,v);
        par[v]=u;sz[u]+=sz[v];ma[u]=min(ma[u],ma[v]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26,0);sz.resize(26,0);ma.resize(26,0);
        for(int i=0;i<26;i++) 
        {
            par[i]=ma[i]=i;
            sz[i]=1;
        }
        for(int i=0;i<(int)s1.size();i++) union_set(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<(int)baseStr.size();i++) baseStr[i]=(char)('a'+ma[find_set(baseStr[i]-'a')]);
        return baseStr;
    }
};