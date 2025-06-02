class BrowserHistory {
public:
    vector<string> history;
    int idx=-1;
    int sz=0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        idx=0;
        sz=1;
    }
    
    void visit(string url) {
        if(history.size()-1>idx)
        {
            history[idx+1]=url;
            idx++;
            sz=idx+1;
        }
        else 
        {
            history.push_back(url);
            idx++;
            sz++;
        }
    }
    
    string back(int steps) {
        int temp=min(steps,idx);
        idx-=temp;
        return history[idx];
    }
    
    string forward(int steps) {
        int temp=min(steps,sz-idx-1);
        idx+=temp;
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */