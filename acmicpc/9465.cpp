#include <bits/stdc++.h>
using namespace std;

int t, n, sticker[2][100005], dp[2][100005];

int main(){
    scanf("%d", &t);
    while(t-->0){
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &sticker[0][i]);
        for(int i=1;i<=n;i++) scanf("%d", &sticker[1][i]);

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        dp[0][2] = dp[1][1] + sticker[0][2];
        dp[1][2] = dp[0][1] + sticker[1][2];
        
        for(int i=3;i<=n;i++){
            dp[0][i] = max(dp[1][i-1]+sticker[0][i], dp[1][i-2]+sticker[0][i]);
            dp[1][i] = max(dp[0][i-1]+sticker[1][i], dp[0][i-2]+sticker[1][i]);
        }
        int ret = 0;
        ret = max(dp[0][n], dp[1][n]);
        ret = max(ret, dp[0][n-1]);
        ret = max(ret, dp[1][n-1]);
        cout<<ret<<endl;
    }
    return 0;
}
