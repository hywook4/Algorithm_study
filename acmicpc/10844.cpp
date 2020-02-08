#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll divide = 1000000000, dp[100000][10] = {0,};

int main(){
    scanf("%d", &n);
    for(int i=1;i<=9;i++) dp[1][i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            int up = j+1, down = j-1;
            if(up<=9) {
                dp[i][up] += dp[i-1][j];
                dp[i][up] %= divide;
            }
            if(down>=0){
                dp[i][down] += dp[i-1][j];
                dp[i][down] %= divide;
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