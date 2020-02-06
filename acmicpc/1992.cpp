#include <bits/stdc++.h>
using namespace std;

int n, v[100][100];

void solve(int lx, int ly, int rx, int ry){
    int val = v[lx][ly];
    bool flag = true;
    for(int i=lx;i<=rx;i++){
        for(int j=ly;j<=ry;j++){
            if(val!=v[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    if(flag){
        cout<<val;
    } else{
        cout<<"(";
        int len = (rx - lx + 1)/2;
        solve(lx, ly, lx+len-1, ly+len-1);
        solve(lx, ly+len, lx+len-1, ly+len+len-1);
        solve(lx+len, ly, lx+len+len-1, ly+len-1);
        solve(lx+len, ly+len, lx+len+len-1, ly+len+len-1);
        cout<<")";
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d", &v[i][j]);
    solve(1, 1, n, n);
    cout<<endl;
    return 0;
}