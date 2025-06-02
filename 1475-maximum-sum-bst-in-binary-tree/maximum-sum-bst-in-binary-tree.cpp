/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dp[400005],check[400005],ma[400005],mi[400005],treesz=0;
    map<TreeNode*,int> idx;
    void dfs(TreeNode *root)
    {
        idx[root]=++treesz;
        dp[treesz]=check[treesz]=ma[treesz]=0;
        mi[treesz]=1e5;
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    int find_max(TreeNode *root)
    {
        if(ma[idx[root]]) return ma[idx[root]];
        int ans=root->val;
        if(root->left) ans=max(ans,find_max(root->left));
        if(root->right) ans=max(ans,find_max(root->right));
        return ma[idx[root]]=ans;
    }
    int find_min(TreeNode *root)
    {
        if(mi[idx[root]]!=1e5) return mi[idx[root]];
        int ans=root->val;
        if(root->left) ans=min(ans,find_min(root->left));
        if(root->right) ans=min(ans,find_min(root->right));
        return mi[idx[root]]=ans;
    }
    bool isValidBST(TreeNode* root) {
        if(check[idx[root]]) return check[idx[root]];
        bool ok=true;
        if(root->left)
        {
            if(find_max(root->left)>=root->val) return check[idx[root]]=false;
            ok&=isValidBST(root->left);
        }
        if(root->right)
        {
            if(find_min(root->right)<=root->val) return check[idx[root]]=false;
            ok&=isValidBST(root->right);
        }
        return check[idx[root]]=ok;
    }
    int maxSumBST(TreeNode* root,int head=-1) {
        int ans=0;
        if(head) dfs(root);
        if(isValidBST(root)) ans=sum(root);
        if(root->left) ans=max(ans,maxSumBST(root->left,0));
        if(root->right) ans=max(ans,maxSumBST(root->right,0));
        return ans;
    }
    int sum(TreeNode *root)
    {
        if(dp[idx[root]]) return dp[idx[root]];
        int s=root->val;
        if(root->left) s+=sum(root->left);
        if(root->right) s+=sum(root->right);
        return dp[idx[root]]=s;
    }
};