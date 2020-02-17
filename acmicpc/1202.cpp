#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll m, v, c[300005];
pair<ll, ll> info[300005];
bool used[300005] = {0,};

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%lld %lld", &m, &v);
        info[i] = make_pair(m, v);
    } 
    for(int i=0;i<k;i++) scanf("%lld", &c[i]);

    sort(c, c+k);
    sort(info, info+n);

    ll ans = 0;
    for(int i=0;i<k;i++){
        ll add = 0;
        int use = -1;
        for(int j=0;j<n;j++){
            if(used[j]) continue;
            if(info[j].first>c[i]) break;
            
            if(add < info[j].second){
                add = info[j].second;
                if(use!=-1) used[use] = false;
                used[j] = true;
                use = j;
            }
            add = max(add, info[j].second);
        }
        ans += add;
    }
    cout<<ans<<endl;
    return 0;
}