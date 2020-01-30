#include <bits/stdc++.h>

using namespace std;

#define MAX 200005

int n;
pair<int, int> st[MAX];
priority_queue<int, vector<int>, greater<int>> pq;


int main(){
    scanf("%d", &n);

    int s, t;
    for(int i=0;i<n;i++){
        scanf("%d %d", &s, &t);
        st[i] = make_pair(s, t);
    }

    sort(st, st+n);

    pq.push(st[0].second);

    for(int i=1;i<n;i++){
        if(pq.top()<=st[i].first){
            pq.pop();
            pq.push(st[i].second);
        } else{
            pq.push(st[i].second);
        }
    }

    cout<<pq.size()<<endl;

    return 0;
}