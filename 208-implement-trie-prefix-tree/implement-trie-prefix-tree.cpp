class Trie {
public:
    Trie *child[26];
    bool isEnd;
    Trie() {
        for(int i=0;i<26;i++) child[i]=0;
        isEnd=false;
    }
    
    void insert(string word) {
        Trie *p=this;
        for(int i=0;i<word.size();i++)
        {
            if(p->child[word[i]-'a']==NULL) p->child[word[i]-'a']=new Trie();
            p=p->child[word[i]-'a'];
        }
        p->isEnd=true;
    }
    
    bool search(string word) {
        Trie *p=this;
        for(int i=0;i<word.size();i++) 
        {
            if(p->child[word[i]-'a']==NULL) return false;
            p=p->child[word[i]-'a'];
        }
        return p->isEnd;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */