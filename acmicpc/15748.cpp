#include <bits/stdc++.h>

using namespace std;

long long l, n, rf, rb;
long long d, t;
pair<long long, long long> td;

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>> pq;

int main(){
    scanf("%lld %lld %lld %lld", &l, &n, &rf, &rb);
    for(int i=0;i<n;i++){
        scanf("%lld %lld", &d, &t);
        pq.push(make_pair(t, d));
    }

    unsigned long long ans = 0;
    long long cur_pos = 0;
    while(!pq.empty()){
        d = pq.top().second;
        t = pq.top().first;
        pq.pop();

        if(d>cur_pos){
            long long eat_time = (d-cur_pos)*rf - (d-cur_pos)*rb;
            ans += t*eat_time;
            cur_pos = d;
        }
    }

    cout<<ans<<endl;

    return 0;
}