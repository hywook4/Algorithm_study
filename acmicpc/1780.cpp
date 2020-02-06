#include <bits/stdc++.h>
using namespace std;

int n, p[2500][2500], val;
int cnt[3];

void count(int lx, int ly, int rx, int ry){
    if(lx==rx && ly==ry) cnt[p[lx][ly]];

    int type = p[lx][ly];
    bool flag = true;
    // 값이 다르면 break
    for(int i=lx;i<=rx;i++){
        for(int j=ly;j<=ry;j++){
            if(type!=p[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    if(flag){
        cnt[type] += 1;
    } else{
        int len = (rx - lx + 1)/3;
        
        for(int i=lx;i<=lx+2*len;i+=len)
            for(int j=ly;j<=ly+2*len;j+=len)
                count(i, j, i+len-1, j+len-1);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d", &val);
            p[i][j] = val+1;
        }
    count(1, 1, n, n);
    for(int i=0;i<=2;i++)
        cout<<cnt[i]<<endl;
    return 0;
}