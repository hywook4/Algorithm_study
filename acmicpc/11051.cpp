#include <bits/stdc++.h>
using namespace std;

int n, k, dp[1005][1005] = {0,}, divide = 10007;

int main(){
    scanf("%d %d", &n, &k);

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-1;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= divide;
        }
    }

    cout<<dp[n][k]<<endl;
    return 0;
}