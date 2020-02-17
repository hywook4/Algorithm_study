#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m, budget[1000000];

int main(){
    scanf("%d", &n);
    ll right = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        scanf("%lld", &budget[i]);
        sum += budget[i];
        right = max(right, budget[i]);
    } 
    scanf("%lld", &m);

    if(sum<=m){
        cout<<right<<endl;
        return 0;
    }

    ll ans = 0;
    ll left = 1;
    ll max_sum = 0;
    while(left<=right){
        ll mid = (left+right)/2;
        sum = 0;
        for(int i=0;i<n;i++){
            if(budget[i]<=mid) sum += budget[i];
            else sum += mid;
        }

        if(sum>m){
            right = mid-1;
        } else if(sum<=m){
            if(max_sum<=sum){
                max_sum = max(max_sum, sum);
                ans = max(ans, mid);
            }
            left = mid+1;
        }
    }

    cout<<ans<<endl;

    return 0;
}