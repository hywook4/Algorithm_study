#include <bits/stdc++.h>

using namespace std;

int n, s;
int a[30];
bool flag[30] = {0,};

int main(){
    scanf("%d %d", &n, &s);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++)
            flag[j] = 0;
        for(int j=n-i;j<n;j++)
            flag[j] = 1;

        do{
            int val = 0;
            for(int j=0;j<n;j++){
                if(flag[j]) val += a[j];
            }
            if(s==val) ans++;
        }while(next_permutation(flag, flag+n));
    }
    
    cout<<ans<<endl;
    return 0;
}