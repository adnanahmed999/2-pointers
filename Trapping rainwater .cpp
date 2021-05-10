    int trap(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int leftMax = 0;
        int rightMax = 0;
        int lp = 0;
        int rp = n-1;
        while(lp<=rp) {
            if(a[lp]<a[rp]) {
                if(a[lp]<=leftMax) {
                    ans += min(leftMax,a[rp])-a[lp];
                    lp++;
                } else {
                    leftMax = a[lp];
                }
            } else {
                if(a[rp]<=rightMax) {
                    ans += min(rightMax,a[lp])-a[rp];
                    rp--;
                } else {
                    rightMax = a[rp];
                }
            }
        }
        return ans;
    }