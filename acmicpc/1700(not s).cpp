#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int n, k;
int elec[MAX];
int tab[MAX];
int flag[MAX] = {0,};
int ranks[MAX] = {0,};
bool valid[MAX] = {0,};

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;i++)
        scanf("%d", &elec[i]);
    
    
    for(int i=0;i<n;i++)
        tab[n] = -1;

    for(int i=0;i<k;i++)
        valid[elec[i]] = true;
        

    int ans = 0;
    bool full = false;
    int idx = 0;
    for(int i=0;i<k;i++){
        int cur_elec = elec[i];
        
        if(!flag[cur_elec]){
            if(full){ // 탭이 꽉찬 경우
                int r = 1;
                for(int j=i+1;j<k;j++){
                    if(ranks[elec[j]]==0 && flag[elec[j]]){
                        ranks[elec[j]] = r;
                        r++;
                    }
                }

                for(int j=0;j<k;j++){
                    if(valid[j] && ranks[j]==0 && flag[j]){
                        ranks[j] = r;
                        r++;
                    }
                }

                int pull_elec = 0;
                int last = -1;
                
                for(int j=0;j<k;j++){
                    if(last<ranks[j]){
                        last = ranks[j];
                        pull_elec = j;
                    }
                }

                for(int j=0;j<n;j++){
                    if(tab[j]==pull_elec){
                        idx = j;
                        break;
                    }
                }

                flag[tab[idx]] = false;
                flag[i] = true;
                tab[idx] = i;

                ans++;

            } else{ // 아직 탭 남은 경우
                tab[idx] = cur_elec;
                flag[cur_elec] = true;
                idx++;

                if(idx==n) full = true;
            }

        }
    }

    cout<<ans<<endl;

    return 0;
}