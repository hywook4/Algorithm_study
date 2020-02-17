#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll maxhp, curhp, cur_atk, n, atk;

class room{
public:
    int t;
    ll a;
    ll h;

};

room r[123460];

bool simulate(int ith){
    int t = r[ith].t;
    ll a = r[ith].a;
    ll h = r[ith].h;

    // monster
    if(t==1){
        ll turn_hero; 
        ll turn_mon;

        turn_hero = h/cur_atk;
        if(h%cur_atk !=0) turn_hero += 1;

        turn_mon = curhp/a;
        if(curhp%a !=0) turn_mon += 1;

        if(turn_mon<turn_hero){
            return false;
        } else{
            curhp -= a*(turn_hero-1);
            return true;
        }
    }
    // potion
    else if(t==2){
        curhp += h;
        if(curhp>maxhp) curhp = maxhp;
        cur_atk += a;
        return true;
    }
}

int main(){
    scanf("%lld %lld", &n, &atk);
    int t;
    ll a, h;
    ll left = 1, right = (ll)223372036854775805; 
    for(int i=1;i<=n;i++){
        scanf("%d %lld %lld", &t, &a, &h);
        r[i].t = t;
        r[i].a = a;
        r[i].h = h;
    }

    ll ans = right;
    while(left<=right){
        ll mid = (left+right)/2;
        bool clear = false;
        
        maxhp = mid;
        curhp = mid;
        cur_atk = atk;

        //cout<<"start : "<<cur_atk<<", "<<maxhp<<endl;
        for(int i=1;i<=n;i++) {
            clear = simulate(i);
            //cout<<curhp<<", "<<cur_atk<<endl;
            if(!clear) break;
        }

        if(clear){
            right = mid-1;
            ans = min(ans, mid);
        } 
        else left = mid+1;

    }
    cout<<ans<<endl;
    return 0;
}

