#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

ll lan[100000];

int main(){
    scanf("%lld %lld", &k, &n);
    ll max_len = 0;
    for(ll i=0;i<k;i++) {
        scanf("%lld", lan+i);
        max_len = max(max_len, lan[i]);
    }

    ll left = 1, right = max_len;
    ll ans = 0;
    while(left<=right){
        ll mid = (left+right)/2;
        ll cnt = 0;
        for(ll i=0;i<k;i++){
            cnt += lan[i]/mid;
        }
        if(cnt>=n){
            left = mid+1;
            ans = max(ans, mid);
        } else{
            right = mid-1;
        }
    }

    cout<<ans<<endl;
    return 0;
}