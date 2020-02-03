#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int n, k;
int use[MAX];
bool pluged[MAX] = {0,};
int tab[MAX] = {0,};

void printd(int i){
    cout<<i<<" : ";
    for(int j=0;j<n;j++)
        cout<<tab[j];
    cout<<endl;
}

int main(){
    scanf("%d %d", &n, &k);
    int e;
    for(int i=0;i<k;i++)
        scanf("%d", &use[i]);

    for(int i=0;i<n;i++)
        tab[i] = -1;
    
    bool full = false;
    int idx = 0;

    int ans = 0;
    for(int i=0;i<k;i++){
        //printd(i-1);
        if(pluged[use[i]]) continue;

        if(full){
            // 꼽혀있는 전자기기 순회
            
            int change_idx = 0;

            int change_order = 0;
            for(int j=0;j<n;j++){
                int cur = tab[j]; 
                int order = MAX;
                for(int l=k-1;l>=i+1;l--){
                    if(use[l]==cur) order = l;
                }
                if(order>change_order){
                    change_order = order;
                    change_idx = j;
                }
            }

            pluged[tab[change_idx]] = false;
            tab[change_idx] = use[i];
            pluged[use[i]] = true;
            ans++;

        } else{
            tab[idx] = use[i];
            pluged[use[i]] = true;

            idx++;
            if(idx>=n) full = true;
        }
    }
    //printd(n-1);

    cout<<ans<<endl;
    
    return 0;
}