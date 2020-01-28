#include <bits/stdc++.h>

using namespace std;

int cnt;
int l, p, v;

int main(){
    cnt = 0;
    int ans = 0;
    while(1){
        cnt++;
        scanf("%d %d %d", &l, &p, &v);
        if(l==0 && p==0 && v==0) break;

        ans = 0;

        int camp = v/p;
        int left = v%p;
    
        if(l<=left) ans += l;
        else ans += left;
        ans += l*camp;

        cout<<"Case "<<cnt<<": "<<ans<<endl;
    }
   
    return 0;
}