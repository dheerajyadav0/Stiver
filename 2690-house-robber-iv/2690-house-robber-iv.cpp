class Solution {

    bool check(vector<int>& a,int x,int k,int n){
        for(int i=0;i<n;i++){
            if(x<a[i]) continue;
            k-=1;
            i+=1;
        }
        return k<=0?1:0;
    }

public:
    int minCapability(vector<int>& a, int k) {
        int n = a.size();
        int l = 0, h = a[0], ans = 0;

        for(auto i : a){
            h = max(h,i);
        }

        while(l<=h){
            int mid = (l+h)/2;
            if(check(a,mid,k,n)){
                ans = mid;
                h=mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};