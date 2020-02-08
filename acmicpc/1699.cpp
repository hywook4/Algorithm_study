#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005;
int n, dp[1000005];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) dp[i] = MAX;

    int idx = 1;
    while(1){
        if(idx*idx>n) break;
        dp[idx*idx] = 1;
        idx++;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<idx;j++)
            dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
        
    cout<<dp[n]<<endl;
    return 0;
}