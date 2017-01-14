#include <bits/stdc++.h>
using namespace std;

int n, k, r;
queue<int> q, roller;

int main(){
    while(~scanf("%d%d%d",&r,&k,&n)){
        while(!q.empty()) q.pop();
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            q.push(x);
        }

        int curr = 0, turn = 0, ans = 0;
        while(turn++ < r){
            while(!q.empty() && curr + q.front() <= k){
                curr += q.front();
                roller.push(q.front()); q.pop();
            }
            while(!roller.empty()) q.push(roller.front()), roller.pop();
            ans += curr;
            curr = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
