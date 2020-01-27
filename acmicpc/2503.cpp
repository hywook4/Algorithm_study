#include <bits/stdc++.h>

using namespace std;

int n;
bool flag[1005] = {0,};

int main(){

    for(int i=111;i<=999;i++){
        int n1, n2, n3, num;
        num = i;
        n1 = num%10;
        num = num/10;
        n2 = num%10;
        n3 = num/10;
        
        if(n1!=0 && n2!=0 && n3!=0){
            if(n1!=n2 && n2!=n3 && n3!=n1)
                flag[i] = true;
        }
    }

    scanf("%d", &n);
    
    int num, strike, ball;
    for(int i=0;i<n;i++){
        scanf("%d %d %d", &num, &strike, &ball);
        
        int num1 = num;
        int a[3];
        a[0] = num1%10;
        num1 /= 10;
        a[1] = num1%10;
        a[2] = num1/10;

        for(int j=111;j<=999;j++){
            if(!flag[j]) continue;
            int cur_s = 0, cur_b = 0;
            int b[3], num2;

            num2 = j;
            b[0] = num2%10;
            num2 /= 10;
            b[1] = num2%10;
            b[2] = num2/10;


            for(int k=0;k<3;k++){
                if(a[k]==b[k]) cur_s++;
            }

            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++)
                    if(a[k]==b[l]) cur_b++;
            }

            cur_b -= cur_s;

            if(cur_b!=ball || cur_s!=strike){
                flag[j] = false;
            }
        }
    }

    int ans = 0;
    for(int i=111;i<=999;i++){
        if(flag[i]) ans++;
    }

    cout<<ans<<endl;

    return 0;
}