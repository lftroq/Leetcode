class Trie {
public:
    Trie *child[26];
    Trie() {
        for(int i=0;i<26;i++) child[i]=0;
    }
    
    void insert(string word) {
        Trie *p=this;
        for(int i=0;i<word.size();i++)
        {
            if(p->child[word[i]-'a']==NULL) p->child[word[i]-'a']=new Trie();
            p=p->child[word[i]-'a'];
        }
    }
    
    bool startsWith(string prefix) {
        Trie *p=this;
        for(int i=0;i<prefix.size();i++) 
        {
            if(p->child[prefix[i]-'a']==NULL) return false;
            p=p->child[prefix[i]-'a'];
        }
        return true;
    }
};

class Solution {
public:
    Trie *t=new Trie();
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a,string b)
        {
            return a.size()>b.size();
        });
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(),words[i].end());
            if(t->startsWith(words[i])) continue;
            ans+=words[i].size()+1;
            t->insert(words[i]);
        }
        return ans;
    }
};