#include <bits/stdc++.h>
using namespace std;

long long n, dp[2][100];

int main(){
    scanf("%lld", &n);
    dp[0][1] = 0;
    dp[1][1] = 1;
    dp[0][2] = 1;
    dp[1][2] = 0;
    dp[0][3] = 1;
    dp[1][3] = 1;

    for(int i=4;i<=n;i++){
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }

    cout<<dp[0][n]+dp[1][n]<<endl;
    return 0;
}