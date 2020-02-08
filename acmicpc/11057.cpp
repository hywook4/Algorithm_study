#include <bits/stdc++.h>
using namespace std;

int n, dp[10000][10] = {0,}, divide = 10007;

int main(){
    scanf("%d", &n);
    for(int i=0;i<=9;i++) dp[1][i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=j;k>=0;k--){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= divide;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=9;i++){
        ans += dp[n][i];
        ans %= divide;
    }
    cout<<ans<<endl;
    return 0;
}
