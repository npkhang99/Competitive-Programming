#include <bits/stdc++.h>
using namespace std;

const int N = 509;

int n, m, t, d;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&d);
        priority_queue<int> q;
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            q.push(x);
        }

        int flag = true;
        for(int i=0; i<m; i++){
            int x = q.top() - d; q.pop();
            if(x <= 0){
                flag = false;
                break;
            }
            q.push(x);
        }

        printf("%s\n", flag? "YES":"NO");
    }
    return 0;
}
