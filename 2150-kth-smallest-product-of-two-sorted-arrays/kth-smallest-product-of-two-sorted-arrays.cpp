class Solution {
public:
    typedef long long ll;
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> neg1,neg2,pos1,pos2;
        while(nums1.size())
        {
            int x=nums1.back();
            if(x>0) pos1.push_back(x);
            else neg1.push_back(-x);
            nums1.pop_back();
        }
        while(nums2.size())
        {
            int y=nums2.back();
            if(y>0) pos2.push_back(y);
            else neg2.push_back(-y);
            nums2.pop_back();
        }
        reverse(pos1.begin(),pos1.end());
        reverse(pos2.begin(),pos2.end());
        ll negcnt=1ll*neg1.size()*pos2.size()+1ll*pos1.size()*neg2.size();
        int sign=1;
        if(k>negcnt) k-=negcnt;
        else
        {
            k=negcnt-k+1;
            sign=-1;
            swap(pos2,neg2);
        }
        
        ll l=0,r=1e10,ans=1e10;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(calc(pos1,pos2,mid)+calc(neg1,neg2,mid)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return sign*ans;
    }
    ll calc(vector<int> &A,vector<int> &B,ll m)
    {
        ll cn=0;
        int j=(int)B.size()-1;
        for(int i=0;i<(int)A.size();i++)
        {
            while(j>=0&&1ll*A[i]*B[j]>m) j--;
            cn+=j+1;
        }
        return cn;
    }
};