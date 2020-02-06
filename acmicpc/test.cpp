#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll A, B, C;

ll solve(ll a, ll b, ll c){
    if(b==0) return 1;

    int ret = solve(a, b/2, c);
    
    ret = ret*ret%c;
    
    if(b%2==1) return ret*a%c;

    return ret;
}

int main(){
    scanf("%lld %lld %lld", &A, &B, &C);
    cout<<solve(A, B, C)<<endl;
    return 0;
}