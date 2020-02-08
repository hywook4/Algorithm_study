#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll w[105], v[105], dp[105][1000005] = {0,};

int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++) scanf("%lld %lld", &w[i], &v[i]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    
    ll ans = 0;
    for(int j=1;j<=k;j++) ans = max(ans, dp[n][j]);
    cout<<ans<<endl;
}