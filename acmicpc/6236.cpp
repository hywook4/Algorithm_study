#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
int cash[MAX], max_cash = 0;

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", cash+i);
        max_cash = max(max_cash, cash[i]);
    } 

    int left = max_cash, right = 1000000005;

    while(left<=right){
        int mid = (left+right)/2;

        int sum = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            sum += cash[i];
            if(sum>mid){
                cnt++;
                sum = cash[i];
            }
        }
        if(sum > 0) cnt++;

        if(cnt>m) left = mid+1;
        else right = mid-1;
    }
    cout<<left<<endl;
    return 0;
}
