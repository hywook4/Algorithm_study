#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> t[100005];

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int e, s;
        scanf("%d %d", &s, &e);
        t[i] = make_pair(e, s);
    }

    sort(t, t+n);
    
    int ans = 0;
    int end = 0;
    for(int i=0;i<n;i++){
        if(t[i].second>=end){
            ans++;
            end = t[i].first;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}