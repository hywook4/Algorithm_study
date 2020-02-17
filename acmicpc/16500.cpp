#include <bits/stdc++.h>
using namespace std;

string s, a[105];
int n;

int main(){
    cin>>s;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    int ans = 0;
    queue<string> q;
    q.push("");

    while(1){
        queue<string> next_q;
        while(!q.empty()){
            string cur = q.front();
            q.pop();

            int s_idx = cur.size();
            for(int i=0;i<n;i++){
                bool match = true;
                
                for(int j=0;j<a[i].size();j++){
                    if(s[s_idx + j] != a[i][j]){
                        match = false;
                        break;
                    } 
                }

                if(match){
                    next_q.push(cur+a[i]);
                    if(cur+a[i]==s){
                        ans = 1;
                        break;
                    }
                } 
            }

            if(ans) break;
        }
        if(next_q.empty()) break;
        q = next_q;
        if(ans) break;
    }

    cout<<ans<<endl;
}