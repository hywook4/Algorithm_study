#include <bits/stdc++.h>
using namespace std;
int N;
string line[2200];

void draw_empty(int h, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            line[h+i] += " ";
        }
    }
}

void draw(int h, int n){
    //cout<<h<<", "<<n<<endl;
    if(n==1){
        line[h] += "*";
        return;
    }
    int len = n/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1) draw_empty(h+len*i, len);
            else draw(h+len*i, len);
        }
    }
    return;
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        line[i] = "";
    draw(0, N);
    for(int i=0;i<N;i++)
        cout<<line[i]<<endl;
    return 0;
}