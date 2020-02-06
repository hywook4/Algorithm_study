#include <bits/stdc++.h>

using namespace std;

long long l, w, h;
int n;
long long cube[25] = {0,};
int len, num;

int main(){
    scanf("%lld %lld %lld", &l, &w, &h);
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &len, &num);
        cube[len] = num;
    }

    


    return 0;
}