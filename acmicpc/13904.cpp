#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

int n;
int d, w;
vector<int> score[MAX];
int m;


int main(){
    scanf("%d", &n);
    m=-1;
    for(int i=0;i<n;i++){
        scanf("%d %d", &d, &w);
        score[d].push_back(w);
        m = max(m, d);
    }

    for(int i=1;i<=1000;i++){
        if(score[i].size() == 0 || score[i].size() == 1){

        } else{
            sort(score[i].begin(), score[i].end());
        }
    }

    int ans = 0;
    for(int i=m;i>=1;i--){
        int max_score = -1;
        int idx = -1;
        for(int j=i;j<=m;j++){
            if(score[j].size()!=0){
                if(score[j].back() > max_score){
                    max_score = score[j].back();
                    idx = j;
                }
            }
        }
        if(max_score == -1) continue;
            
        ans += max_score;
        score[idx].pop_back();
    }

    cout<<ans<<endl;

    return 0;
}