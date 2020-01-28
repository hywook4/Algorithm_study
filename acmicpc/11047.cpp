#include <bits/stdc++.h>

using namespace std;

int n, k;

int a[20];

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    reverse(a, a+n);

    int ans = 0;
    for(int i=0;i<n;i++){
        ans += k/a[i];
        k = k%a[i];
    }

    cout<<ans<<endl;

    return 0;
}