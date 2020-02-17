#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x[200005], c;

int main(){
    scanf("%d %d", &n, &c);
    for(int i=0;i<n;i++) scanf("%d", &x[i]);
       

    sort(x, x+n);

    int ans = 0;
    int left = 1, right = x[n-1] - x[0];
    

    while(left<=right){
        int mid = (left+right)/2;

        int prev = x[0];
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(x[i]-prev>mid){
                cnt++;
                prev = x[i];
            }
        }


    }
    cout<<ans<<endl;
    return 0;
}