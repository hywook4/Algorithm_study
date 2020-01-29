#include <bits/stdc++.h>

using namespace std;


vector<int> graph[10005];
map<int, bool> road[10005];
int cows[105];
int n, k, r;

bool flag[10005];

void reset(){
    for(int i=0;i<10005;i++)
        flag[i] = false;
}

bool dfs(int s, int e){
    flag[s] = true;
    //cout<<s;
    if(s==e) return true;

    bool ret = false;

    for(auto i:graph[s]){
        if(!flag[i]){
            ret = ret || dfs(i, e);
        }
        
        if(ret) return true;
    }

    return ret;
}


int main(){
    scanf("%d %d %d", &n, &k, &r);

    int x1, y1, x2, y2, s, e;
    for(int i=0;i<r;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        s = (x1-1)*n + y1;
        e = (x2-1)*n + y2;
        road[s][e] = true;
        road[e][s] = true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-1;j++){
            s = (i-1)*n + j;
            e = s + 1;
            if(!road[s][e]){
                graph[s].push_back(e);
                graph[e].push_back(s);
            }
        }
    }

    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            s = (i-1)*n + j;
            e = s + n;
            if(!road[s][e]){
                graph[s].push_back(e);
                graph[e].push_back(s);
            }
        }
    }

    for(int i=0;i<k;i++){
        scanf("%d %d", &x1, &y1);
        cows[i] = (x1-1)*n + y1;
    }

    int ans = 0;
    for(int i=0;i<=k-2;i++){
        for(int j=i+1;j<=k-1;j++){
            //cout<<cows[i]<<", "<<cows[j]<<endl;
            reset();
            int ret = dfs(cows[i], cows[j]);
            //cout<<endl<<ret<<endl;
            if(!ret) ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}