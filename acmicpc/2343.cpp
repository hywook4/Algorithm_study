#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll lesson[100005], max_len=0;

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &lesson[i]);
        max_len = max(max_len, lesson[i]);
    } 

    ll left = max_len, right = 1000000005;

    ll ans = right + 10;
    while(left<=right){
        ll mid = (left+right)/2;

        ll length = 0;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            length += lesson[i];
            if(length > mid){
                cnt++;
                length = lesson[i];
            }
        }

        if(length>0) cnt++;
        
        if(cnt>m){
            left = mid+1;
        } else{ 
            right = mid-1;
            ans = min(ans, mid);
        }
    }
    cout<<ans<<endl;

    return 0;
}