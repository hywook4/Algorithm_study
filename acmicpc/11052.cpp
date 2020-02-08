#include <bits/stdc++.h>
using namespace std;

int n, p[1005], dp[1000005] = {0,};

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &p[i]);
    for(int i=1;i<=n;i++) dp[i] = p[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i+j] = max(dp[i+j], dp[i] + p[j]);
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}