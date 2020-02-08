#include <bits/stdc++.h>
using namespace std;

int n, dp[1005];

int main(){
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2]*2;
        if(dp[i] >= 10007) dp[i] %= 10007;
    }
    cout<<dp[n]<<endl;
    return 0;
}