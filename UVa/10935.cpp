#include <stdio.h>
#include <queue>
using namespace std;

int n;

int main(){
    while(scanf("%d",&n), n){
        queue<int> q;
        for(int i=1; i<=n; i++) q.push(i);
        printf("Discarded cards:");
        if(q.size() > 1){
            printf(" %d",q.front());
            q.pop(); q.push(q.front()); q.pop();
        }
        while(q.size() > 1){
            printf(", %d",q.front());
            q.pop(); q.push(q.front()); q.pop();
        }
        printf("\nRemaining card: %d\n",q.front());
    }
    return 0;
}
