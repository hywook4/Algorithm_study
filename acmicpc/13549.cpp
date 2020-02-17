#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int flag[1000005] = {0,};

int main(){
    scanf("%d %d", &n, &k);

    for(int i=0;i<=100000;i++) flag[i] = 10000000;

    if(k<n){
        cout<<n-k<<endl;
        return 0;
    }

    int ans = 0;
    queue<int> q;
    
    q.push(n);
    flag[n] = 0;
    while(!q.empty()){
        int cur_pos = q.front();
        q.pop();
        
        if(cur_pos==k) {
            ans = flag[cur_pos];
            break;
        }

        if(flag[cur_pos*2] > flag[cur_pos]){
            flag[cur_pos*2] = flag[cur_pos];
            q.push(cur_pos*2);
        }

        if(flag[cur_pos+1]> flag[cur_pos] + 1){
            flag[cur_pos+1] = flag[cur_pos] + 1;
            q.push(cur_pos+1);
        }

        if(flag[cur_pos-1]>flag[cur_pos] + 1){
            flag[cur_pos-1] = flag[cur_pos] + 1;
            q.push(cur_pos-1);
        }
    }
    cout<<ans<<endl;
    return 0;   
}