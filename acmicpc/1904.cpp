#include <bits/stdc++.h>
using namespace std;

int n, dp[1000005];

int main(){
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        if(dp[i]>=15746) dp[i] %= 15746;
    }
    cout<<dp[n]<<endl;
    return 0;
}