#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, tree[10000005];


int main(){
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<n;i++)
        scanf("%lld", &tree[i]);

    ll left = 1, right = 2000000000;
    ll ans = 0; 

    while(left<=right){
        ll mid = (left+right)/2;
        ll get = 0;
        for(int i=0;i<n;i++){
            if(tree[i]>mid) get += tree[i]-mid;
        }

        if(get<m){
            right = mid-1;
        } else{
            left = mid + 1;
            ans = max(ans, mid);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}