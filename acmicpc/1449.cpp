#include <bits/stdc++.h>

using namespace std;

int n, l;
int h[1005];
int flag[1005] = {0,};

int main(){
    scanf("%d %d", &n, &l);
    for(int i=0;i<n;i++) scanf("%d", &h[i]);

    sort(h, h+n);
    
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!flag[i]){
            ans++;

            float start = h[i] - 0.5;
            float end = start + l;

            int idx = i;
            while(h[idx]>start && h[idx]<end){
                flag[idx] = true;
                idx++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}