#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n, k, v, dp[100005], val[100005] = {0,};

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &val[i]);
    sort(val, val+n);
    
    for(int i=1;i<=k;i++) dp[i] = MAX;
    for(int i=0;i<n;i++) dp[val[i]] = 1;
    
    for(int i=1;i<=k;i++){
        if(dp[i]!=MAX){
            for(int j=0;j<n;j++){
                dp[i+val[j]] = min(dp[i+val[j]], dp[i]+1);
            }
        }
    }

    if(dp[k]==MAX) cout<<-1<<endl;
    else cout<<dp[k]<<endl;

    return 0;
}