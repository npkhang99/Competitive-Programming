#include <stdio.h>
#include <queue>
using namespace std;

#define long long long

const int N=5009;

int n;
priority_queue<long, vector<long>, greater<long> > q;

int main(){
    while(scanf("%d",&n), n){
        while(!q.empty()) q.pop();
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            q.push(x);
        }
        long ans = 0, curr = 0;
        while(!q.empty()){
            curr = q.top(); q.pop();
            curr += q.top(); q.pop();
            ans += curr;
            if(!q.empty()) q.push(curr);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
