#include <bits/stdc++.h>
using namespace std;

int n, a[1005], dp[10000] = {0,};

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    for(int i=0;i<n;i++){
        dp[i] = a[i];
        for(int j=0;j<i;j++){
            if(a[j]<a[i]) dp[i] = max(dp[i], dp[j]+a[i]);
        }
    }    

    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}