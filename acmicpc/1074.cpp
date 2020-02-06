#include <bits/stdc++.h>
using namespace std;

int n, r, c, cnt=-1;

bool find(int x, int y, int n){
    if(n==0){
        cnt++;
        if(x==r && y==c) return true;
        return false;
    }

    bool flag = false;
    int len = pow(2, n-1);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(x+len*i<=r && y+len*j<=c && r<x+len*(i+1) && c<y+len*(j+1)){
                cnt += (len*len)*(i*2 + j);
                flag = find(x+len*i, y+len*j, n-1);
                if(flag) return flag;
            }
        }
    }
    return flag;
}

int main(){
    scanf("%d %d %d", &n, &r, &c);
    find(0, 0, n);
    cout<<cnt<<endl;
    return 0;
}