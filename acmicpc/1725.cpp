#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long ll;

int n;
int a[MAX];

ll solve(int i, int j){
    if(i==j) return (long long)a[i];

    int mid = (i+j)/2;
    ll L = solve(i, mid);
    ll R = solve(mid+1, j);

    ll ret = max(L, R);

    int left = mid, right=mid+1;
    int min_h = min(a[left], a[right]);
    ret = max(ret, (long long)2*min_h);

    while(left>i || right<j){
        //왼쪽 확장
        if(left>i && (right==j || a[left-1]>a[right+1])){
            left--;
            min_h = min(min_h, a[left]);
        } else{ // 오른쪽 확장
            right++;
            min_h = min(min_h, a[right]);
        }
        ret = max(ret, (long long)(right-left+1)*min_h);
    }
    
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    cout<<solve(1, n)<<endl;
    return 0;
}