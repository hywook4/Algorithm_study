#include <bits/stdc++.h>

using namespace std;

int d[20], v[20];

int main(){
    for(int i=0;i<11;i++)
        scanf("%d %d", &d[i], &v[i]);
    
    int ans = 0;
    for(int i=0;i<11;i++)
        ans += v[i]*20;

    sort(d, d+11);

    int sum = 0;
    for(int i=0;i<11;i++){
        sum += d[i];
        ans += sum;
    }

    cout<<ans<<endl;    

    return 0;
}