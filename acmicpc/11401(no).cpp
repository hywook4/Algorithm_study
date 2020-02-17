#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> dp[4000005];
ll divide = 1000000007;

int main(){
    scanf("%lld %lld", &n, &k);

    for(int i=0;i<=n;i++){
        dp[i].resize(i+1);
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for()


    return 0;
}