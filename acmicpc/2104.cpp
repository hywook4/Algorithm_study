#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long ll;
int n, a[MAX], i, j;

ll solve(int i, int j){
    if(i==j) return (long long)a[i]*a[i];

    ll ret = 0;

    int mid = (i+j)/2;
    ll L = solve(i, mid);
    ll R = solve(mid+1, j);

    ret = max(max(ret, L), R);
    
    int left = mid, right = mid+1;

    ll sum = a[left] + a[right];
    int min_v = min(a[left], a[right]);

    ret = max(ret, sum*min_v);
    while(left>i || right<j){
        //왼쪽 확장
        if(left>i && (right==j || a[left-1] > a[right+1])){
            left--;
            sum += a[left];
            min_v = min(min_v, a[left]);
        } else{
            right++;
            sum += a[right];
            min_v = min(min_v, a[right]);
        }

        ret = max(ret, sum*min_v);
    }

    return ret;
}

int main(){
    scanf("%d", &n);
    for(int l=1;l<=n;l++)
        scanf("%d", &a[l]);
    cout<<solve(1, n)<<endl;
    return 0;
}