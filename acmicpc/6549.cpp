#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll h[10000005];

ll solve(int s, int e){
    if(s==e) return h[s];

    int mid = (s+e)/2;
    ll L = solve(s, mid);
    ll R = solve(mid+1, e);

    ll ret = max(L, R);

    int left = mid, right = mid+1;
    ll min_h = min(h[left], h[right]);
    ret = max(ret, min_h*2);
    while(left>s || right<e){
        if(left>s && (right == e || h[right+1] <= h[left-1])){
            left--;
            min_h = min(min_h, h[left]);
            ret = max(ret, (right-left+1)*min_h);
        } else{
            right++;
            min_h = min(min_h, h[right]);
            ret = max(ret, (right-left+1)*min_h);
        }
    }
    return ret;
}

int main(){
    while(1){
        scanf("%d", &n);
        if(n==0) break;
        for(int i=1;i<=n;i++) scanf("%lld", &h[i]);
        cout<<solve(1, n)<<endl;
    }
    return 0;
}