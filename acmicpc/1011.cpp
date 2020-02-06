#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;
ll x, y;

int main(){
    scanf("%d", &t);
    while(t-->0){
        scanf("%lld %lld", &x, &y);
        ll dis = y-x;
        ll ms = (ll)sqrt(dis);
        
        dis = dis - ms*(ms-1)/2 - ms*(ms+1)/2;
        int ans = ms + ms - 1;
        ans += dis/ms + (dis%ms==0 ? 0 : 1);

        cout<<ans<<endl;
    }
    return 0;
}