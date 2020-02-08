#include <bits/stdc++.h>
using namespace std;

int n, slate[25][25], gem = 0;
// 1 : 불순물 ,  2: 보석
int solve(bool dir, int lx, int ly, int rx, int ry){
    bool next_dir = !dir;
    int ret = 0;

    // check if one gem per slate
    int gem_num = 0;
    int imp_num = 0;
    for(int i=lx;i<=rx;i++){
        for(int j=ly;j<=ry;j++){
            if(slate[i][j]==1) imp_num += 1;
            else if(slate[i][j]==2) gem_num += 1;
        }
    }

    // 완벽한 조각인 경우
    if(gem_num==1 && imp_num==0) return 1;
    
    // 완벽한 조각이 아닌 경우
    else{
        // 가로로 자름
        if(next_dir==0){
            for(int i=ly+1;i<=ry-1;i++){
                int cut_gem = 0;
                int cut_imp = 0;
                for(int j=lx;j<=rx;j++){
                    if(slate[j][i]==1) cut_imp++;
                    else if(slate[j][i]==2) cut_gem++;
                }
                if(cut_imp>0 && cut_gem==0){
                    ret += solve(next_dir, lx, ly, rx, i-1)*solve(next_dir, lx, i+1, rx, ry);
                }
            }
        } else{ // 세로로 자름
            for(int i=lx+1;i<=rx-1;i++){
                int cut_gem = 0;
                int cut_imp = 0;
                for(int j=ly;j<=ry;j++){
                    if(slate[i][j]==1) cut_imp++;
                    else if(slate[i][j]==2) cut_gem++;
                }
                if(cut_imp>0 && cut_gem==0){
                    ret += solve(next_dir, lx, ly, i-1, ry)*solve(next_dir, i+1, ly, rx, ry);
                }
            }
        }
    }
    return ret;

}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &slate[i][j]);
            if(slate[i][j]==2) gem++;
        }
    }

    int ans = 0;
    //0 : 가로 , 1 : 세로
    ans += solve(0, 0, 0, n-1, n-1);
    ans += solve(1, 0, 0, n-1, n-1);
    
    if(ans>0) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}