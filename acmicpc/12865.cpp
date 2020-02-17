#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll w[105], v[105], dp[105][100005] = {0,};

int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++) scanf("%lld %lld", &w[i], &v[i]);
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout<<dp[n][k]<<endl;
}